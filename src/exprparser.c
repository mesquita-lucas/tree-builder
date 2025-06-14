#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "exprparser.h"

char get_value_of(char* expression){
    if(expression[1] == ')') return '\0'; // não possui filho

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

    do{
        if(*expression == '(') count_parenthesis_pair++;

        if(*expression == ')') count_parenthesis_pair--;

        *child = *expression;

        expression++;
        child++;
    } while(count_parenthesis_pair != 0 && *expression != '\0');

    *child = '\0';
}