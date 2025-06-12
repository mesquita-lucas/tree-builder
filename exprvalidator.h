#ifndef EXPRVALIDATOR_H
#define EXPRVALIDATOR_H

typedef enum _{
    OPEN_PAREN = 0,
    CLOSE_PAREN = 1,
    COMMA = 2,
    CHAR = 3,
    NUM_ELEMENT_TYPES = 4 
} expr_elements;

// extern significa dizer que a implementação da matriz de adjacência abaixo
// estará contida em outro lugar
extern const int LEGAL_ELEMENT_FOLLOWUP[NUM_ELEMENT_TYPES][NUM_ELEMENT_TYPES];

#endif