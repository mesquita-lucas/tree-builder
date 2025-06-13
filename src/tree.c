#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "exprparser.h"
#include "exprvalidator.h"

t_binary_tree* create(char* expression){
    if(!is_a_valid_expression(expression)){
        return NULL;
    }

    t_binary_tree* tree = (t_binary_tree*)malloc(sizeof(t_binary_tree));

    t_node* root = build_tree(expression, 0);
    tree->root = root;

    return tree;
}

t_node* build_tree(char* expression, int current_height){
    if(get_value_of(expression) == '\0') {
        return NULL;
    }

    char* leftchild = (char*)malloc((strlen(expression)) * sizeof(char));
    char* rightchild = (char*)malloc((strlen(expression)) * sizeof(char));

    get_children(leftchild, rightchild, expression);

    t_node* root_node = create_node(get_value_of(expression), current_height);

    root_node->right = build_tree(rightchild, current_height + 1);
    root_node->left = build_tree(leftchild, current_height + 1);

    free(rightchild);
    free(leftchild);

    return root_node;
} 

t_node* create_node(char letter, int height){
    t_node* node = (t_node*)malloc(sizeof(t_node));
    node->item = letter;
    node->height = height;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void pre_order(t_node* tree_root){
    if(tree_root == NULL){
        return;
    }

    printf("%c ", tree_root->item);
    pre_order(tree_root->left);
    pre_order(tree_root->right);
}

void in_order(t_node* tree_root){
    if(tree_root == NULL){
        return;
    }

    pre_order(tree_root->left);
    printf("%c ", tree_root->item);
    pre_order(tree_root->right);
}

void post_order(t_node* tree_root){
    if(tree_root == NULL){
        return;
    }

    pre_order(tree_root->left);
    pre_order(tree_root->right);
    printf("%c ", tree_root->item);
}

int height_of(t_node* node){
    if(node == NULL){
        return -1;
    }

    return node->height;
}

void print_for_testing(t_binary_tree* tree){
    if (tree == NULL || tree->root == NULL) {
        printf("Árvore vazia.\n");
        return;
    }

    printf("Impressão em Pré-Ordem: ");
    pre_order(tree->root);
    printf("\n");
}