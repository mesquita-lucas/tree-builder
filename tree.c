#include "tree.h"
#include "exprparser.h"
#include "stdio.h"
#include "stdlib.h"
#include "exprparser.h"

t_binary_tree* create(char* expression){
    //todo: parse to know if the expression is valid
    
    //create after validation

    t_binary_tree* tree = (t_binary_tree*)malloc(sizeof(t_binary_tree));

    t_node* root = create_node(get_value(expression));

    tree->root = root;
    tree->height = 0;

    return tree;
}

t_node* create_node(char letter){
    //todo: validate if is valid char

    t_node* node = (t_node*)malloc(sizeof(t_node));
    node->item = letter;
    node->height = 0;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void pre_order(t_node* tree_root){
    if(tree_root == NULL){
        return;
    }

    printf('%c', tree_root->item);
    pre_order(tree_root->left);
    pre_order(tree_root->right);
}

void in_order(t_node* tree_root){
    if(tree_root == NULL){
        return;
    }

    pre_order(tree_root->left);
    printf('%c', tree_root->item);
    pre_order(tree_root->right);
}

void post_order(t_node* tree_root){
    if(tree_root == NULL){
        return;
    }

    pre_order(tree_root->left);
    pre_order(tree_root->right);
    printf('%c', tree_root->item);
}

int height_of(t_node* node){
    //validate if is not null
    return node->height;
}

void print(t_binary_tree* tree){
    //todo: print logic
 
}