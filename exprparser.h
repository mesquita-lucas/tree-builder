#ifndef EXPRPARSER_H
#define EXPRPARSER_H

int is_valid(char* expression);

void get_children(char* leftchild, char* rightchild, char* expression);

char get_value_of(char* expression);

void extract(char* child, char* expression);
#endif