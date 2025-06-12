#include <stdlib.h>
#include <stdio.h>
#include "exprparser.h"
#include "string.h"

char get_value_of(char* expression){
    // todo: validation

    return expression[1];
}

int is_valid(char* expression){
    int parenthesis_balance = 0; 
}

void get_children(char* leftchild, char* rightchild, char* expression){
    extract(leftchild, expression);

    expression = expression + strlen(leftchild) + 1;

    extract(rightchild, expression);
}

void extract(char* child, char* expression){
    int count_parenthesis_pair = 0; 

    char* child_addr = child;

    do{
        if(*expression == '(') count_parenthesis_pair++;

        if(*expression == ')') count_parenthesis_pair--;

        *child = *expression;

        expression++;
        child++;
    } while(count_parenthesis_pair != 0);

    *child = '\0';
}