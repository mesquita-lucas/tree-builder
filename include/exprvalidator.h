#ifndef EXPRVALIDATOR_H
#define EXPRVALIDATOR_H

#define MINIMUN_CHARACTER_COUNT 9

typedef enum _{
    OPEN_PAREN = 0,
    CLOSE_PAREN = 1,
    COMMA = 2,
    CHAR = 3,
    NUM_ELEMENT_TYPES = 4,
    UNKNOWN,
} expr_elements;

// extern significa dizer que a implementação da matriz de adjacência abaixo
// estará contida em outro lugar
extern const int LEGAL_ELEMENT_FOLLOWUPS[NUM_ELEMENT_TYPES][NUM_ELEMENT_TYPES];

int is_a_valid_expression(char* expression);

int is_a_legal_followup(expr_elements curr_elem, expr_elements next_elem);

expr_elements get_element_type(char element);
#endif