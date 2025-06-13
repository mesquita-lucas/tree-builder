#ifndef EXPRPARSER_H
#define EXPRPARSER_H

void get_children(char* leftchild_buff, char* rightchild_buff, char* expression);

char get_value_of(char* expression);

void extract(char* child, char* expression);
#endif