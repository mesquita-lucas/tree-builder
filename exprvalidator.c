#include <stdlib.h>
#include "exprvalidator.h"

const int LEGAL_ELEMENT_FOLLOWUPS[NUM_ELEMENT_TYPES][NUM_ELEMENT_TYPES] = {
    // element           ( - ) - ,  char
    // open_paren       {0,  1,  0,  1},
    // close_paren      {0,  1,  1,  0},
    // comma            {1,  0,  0,  0},
    // char             {0,  0,  1,  0}
};