#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include "tree.h"   

#define MAX_INPUT_SIZE 1024

//todo está passando a expressão (A,(B,()),(C,(F,(),()),())). Corrigir

t_binary_tree* tree = NULL;

void trim_newline(char* str) {
    int len = strlen(str);
    if(len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
    }
}

t_node* find_node(t_node* root, char item) {
    if(root == NULL) return NULL;
    if(root->item == item) return root;

    t_node* found = find_node(root->left, item);
    if(found != NULL) return found;

    return find_node(root->right, item);
}

int main() {
    char input[MAX_INPUT_SIZE];

    printf("-----Binary Tree Builder-----\n");
    printf("> Comandos disponíveis:\n");
    printf("> create (expression)\n");
    printf("> pre\n");
    printf("> in\n");
    printf("> post\n");
    printf("> height <node>\n");
    printf("> print\n");
    printf("> exit\n");

    while(1) {
        printf("> ");

        if(fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        trim_newline(input);

        if(strncmp(input, "create ", 7) == 0) {
            char* expr = input + 7;
            
            if(tree != NULL) {
                free(tree->root);
                free(tree);
                tree = NULL;
            }

            tree = create(expr);

            if(tree == NULL) {
                printf("Invalid expression.\n");
            } else {
                printf("Tree created successfully.\n");
            }
        }

        else if(strcmp(input, "pre") == 0) {
            if(tree == NULL || tree->root == NULL) {
                printf("No tree created.\n");
            } else {
                pre_order(tree->root);
                printf("\n");
            }
        }

        else if(strcmp(input, "in") == 0) {
            if(tree == NULL || tree->root == NULL) {
                printf("No tree created.\n");
            } else {
                in_order(tree->root);
                printf("\n");
            }
        }

        else if(strcmp(input, "post") == 0) {
            if(tree == NULL || tree->root == NULL) {
                printf("No tree created.\n");
            } else {
                post_order(tree->root);
                printf("\n");
            }
        }

        else if(strncmp(input, "height ", 7) == 0) {
            if(tree == NULL || tree->root == NULL) {
                printf("No tree created.\n");
            } else {
                char node_char = input[7];
                t_node* node = find_node(tree->root, node_char);
                
                if(node == NULL) {
                    printf("Node '%c' not found.\n", node_char);
                } else {
                    printf("Height of node '%c': %d\n", node_char, height_of(node));
                }
            }
        }

        else if(strcmp(input, "print") == 0) {
            if(tree == NULL || tree->root == NULL) {
                printf("No tree created.\n");
            } else {
                print(tree->root, 0);
            }
        }

        else if(strcmp(input, "exit") == 0) {
            break;
        }

        else {
            printf("Unknown command.\n");
        }
    }

    if(tree != NULL) {
        free_tree(tree->root);
    }

    printf("Exiting...\n");
    return 0;
}