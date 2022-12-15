#ifndef FUNCTION_H
#define FUNCTION_H
#include <stdio.h>

void func_add(struct Person **list);
void func_add_index(struct Person **list);
void func_remove_index(struct Person **list);
void func_find_index(struct Person *list);
void func_find_criteria(struct Person *list);
void clearInput();
void validateInput();

#endif
