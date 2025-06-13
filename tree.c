#include "tree.h"
#include "exprparser.h"
#include "stdio.h"
#include "stdlib.h"

t_binary_tree* create(char* expression){
    //todo: parse to know if the expression is valid
    
    //create after validation

    t_binary_tree* tree = (t_binary_tree*)malloc(sizeof(t_binary_tree));

    t_node* root = build_tree(expression);
    tree->root = root;
    tree->height = 0;

    

    return tree;
}

t_node* build_tree(char* expression){
    if(!expression || !get_value_of(expression)) {
        return NULL;
    }

    char* leftchild = (char*)malloc((strlen(expression) + 1) * sizeof(char));
    char* rightchild = (char*)malloc((strlen(expression) + 1) * sizeof(char));

    get_children(leftchild, rightchild, expression);

    t_node* root_node = create_node(get_value_of(expression));

    root_node->right = build_tree(rightchild);
    root_node->left = build_tree(leftchild);

    free(rightchild);
    free(leftchild);

    return root_node;
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