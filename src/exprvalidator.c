#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "exprvalidator.h"

const int LEGAL_ELEMENT_FOLLOWUPS[NUM_ELEMENT_TYPES][NUM_ELEMENT_TYPES] = {
    {0,  1,  0,  1},  // ( seguido de CHAR e )
    {0,  1,  1,  0},  // ) seguido de ) ou ,
    {1,  0,  0,  0},  // , seguido de (
    {0,  0,  1,  0}   // CHAR seguido de ,
};

int is_a_valid_expression(char* expression){
    const int EXPR_SIZE = strlen(expression);

    if(expression == NULL || *expression != '(' || EXPR_SIZE < MINIMUN_CHARACTER_COUNT){ //(A,(),()) a menor expressão tem 9 caracteres
        return 0;
    }

    int verify_parenthesis_balance = 0;
    for(int i = 0; i < EXPR_SIZE; i++){
        expr_elements curr_elem = get_element_type(expression[i]);
        
        if(curr_elem == OPEN_PAREN) verify_parenthesis_balance++;
        if(curr_elem == CLOSE_PAREN) verify_parenthesis_balance--;

        if(i < EXPR_SIZE - 1){
            expr_elements next_elem = get_element_type(expression[i+1]);

            if(next_elem == UNKNOWN || !is_a_legal_followup(curr_elem, next_elem)){
                return 0;
            }
        }

        if(verify_parenthesis_balance < 0){
            return 0;
        }
    }

    if(verify_parenthesis_balance != 0) {
        return 0;
    }

    return 1;
}

expr_elements get_element_type(char element){
    switch (element){
        case '(': return OPEN_PAREN;
        case ')': return CLOSE_PAREN;
        case ',': return COMMA; 
    default:
        if(isalpha(element)){
            return CHAR;
        }

        return UNKNOWN;
    }
}

int is_a_legal_followup(expr_elements curr_elem, expr_elements next_elem){
    return LEGAL_ELEMENT_FOLLOWUPS[curr_elem][next_elem];
}