#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "exprvalidator.h"

const int LEGAL_ELEMENT_FOLLOWUPS[NUM_ELEMENT_TYPES][NUM_ELEMENT_TYPES] = {
    // element           ( | ) | , |char
    // open_paren       {0,  1,  0,  1},
    // close_paren      {0,  1,  1,  0},
    // comma            {1,  0,  0,  0},
    // char             {0,  0,  1,  0}
};

int is_a_valid_expression(char* expression){
    if(expression == NULL || *expression != '(' || strlen(expression) < MINIMUN_CHARACTER_COUNT){ //(A,(),()) a menor expressão tem 9 caracteres
        return 0;
    }

    int verify_parenthesis_balance = 1; 
    // começa em um pois o primeiro caractere da expressão ja foi validado como um OPEN_PAREN. Além disso, o loop de validação 
    // não alcança o último caractere da string em curr_elem, apenas em next_elem, me forçando a considerar o primeiro parentese
    // desde o começo.

    for(int i = 0; i < strlen(expression) - 1; i++){
        expr_elements curr_elem = get_element_type(expression[i]);
        expr_elements next_elem = get_element_type(expression[i+1]);

        if(next_elem == UNKNOWN || !is_a_legal_followup(curr_elem, next_elem)){
            return 0;
        }
        
        if(next_elem == OPEN_PAREN) verify_parenthesis_balance++;
        if(next_elem == CLOSE_PAREN) verify_parenthesis_balance--;
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