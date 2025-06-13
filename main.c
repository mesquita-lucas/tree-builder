#include <stdio.h>
#include <stdlib.h> // Para EXIT_SUCCESS, EXIT_FAILURE
#include <string.h> // Para strlen (se precisar de strings)
#include "tree.h"   // Contém t_binary_tree, t_node e protótipos
#include "exprparser.h" // Contém protótipos de parsing

int main() {
    // A expressão de exemplo fornecida
    // (A,(B,(),()),(C,(F,(),()),()))
    // Raiz: A
    // Filho esquerdo de A: (B,(),())
    //   Raiz: B
    //   Filho esquerdo de B: () (NULL)
    //   Filho direito de B: () (NULL)
    // Filho direito de A: (C,(F,(),()),())
    //   Raiz: C
    //   Filho esquerdo de C: (F,(),())
    //     Raiz: F
    //     Filho esquerdo de F: () (NULL)
    //     Filho direito de F: () (NULL)
    //   Filho direito de C: () (NULL)

    char expression_string[] = "(A,(B,(),()),(C,(F,(),()),()))";
    printf("Expressão de entrada: \"%s\"\n\n", expression_string);

    // Tentar criar a árvore
    t_binary_tree* my_tree = create(expression_string);

    printf("Árvore construída com sucesso!\n");
    printf("Raiz da árvore: %c (Altura: %d)\n\n", my_tree->root->item, my_tree->root->height);

    // Testar as travessias
    printf("Travessia em Pré-Ordem: ");
    pre_order(my_tree->root);
    printf("\n");

    printf("Travessia em Em-Ordem:  ");
    in_order(my_tree->root);
    printf("\n");

    printf("Travessia em Pós-Ordem: ");
    post_order(my_tree->root);
    printf("\n\n");

    // Testar a altura de alguns nós (se a lógica de height_of for relevante)
    printf("Altura do nó 'A': %d\n", height_of(my_tree->root));
    if (my_tree->root->left) {
        printf("Altura do nó 'B': %d\n", height_of(my_tree->root->left));
    }
    if (my_tree->root->right && my_tree->root->right->left) {
        printf("Altura do nó 'F': %d\n", height_of(my_tree->root->right->left));
    }
    if (my_tree->root->right && my_tree->root->right->right == NULL) {
        printf("Filho direito de C é NULL, altura: %d\n", height_of(my_tree->root->right->right));
    }

    return EXIT_SUCCESS;
}