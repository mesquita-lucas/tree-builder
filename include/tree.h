#ifndef T_BINARY_TREE_H 
#define T_BINARY_TREE_H

typedef struct _node{
    char item;
    int height;
    struct _node* left;
    struct _node* right;
} t_node;

typedef struct _binary_tree{
    t_node* root;
} t_binary_tree;

t_binary_tree* create(char* expression);

t_node* build_tree(char* expression, int current_height);

t_node* create_node(char letter, int height);

void pre_order(t_node* tree_root);

void in_order(t_node* tree_root);

void post_order(t_node* tree_root);

int height_of(t_node* node);

void print(t_node* tree_root, int level);

#endif