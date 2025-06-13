#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "exprparser.h"
#include "string.h"

char get_value_of(char* expression){
    // todo: validation
    if(expression[1] == ')') return NULL; // não possui filho

    return expression[1];
}

void get_children(char* leftchild_buff, char* rightchild_buff, char* expression){
    expression = expression + 3;  /*(A,(),()) <- pula os primeiros três caracteres*/
    
    extract(leftchild_buff, expression);

    expression = expression + strlen(leftchild_buff) + 1;

    extract(rightchild_buff, expression); 
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