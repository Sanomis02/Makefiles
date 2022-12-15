#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#define SIZE 52
struct Person {
    char name[SIZE];
    char surname[SIZE];
    char number[SIZE];
    char email[SIZE];
    struct Person *next;
};

int getSize(struct Person *list);

void add_to_list(struct Person **list, struct Person *node);
void print_list(struct Person *list);
void delete_list(struct Person **list);
void load_addresses(FILE *file, struct Person **list);
void add_by_index(struct Person **list, struct Person *person, int ind);
int remove_by_index(struct Person **list, int ind);
struct Person* find_node_text(struct Person *list, int option, char *data);
struct Person* create_address_node(char *address_line);
struct Person* create_node(char *name, char *surname, char *number, char *email);
struct Person* find_node(struct Person *list, int ind);

#endif
