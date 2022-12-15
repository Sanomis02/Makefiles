#include <stdio.h>
#include <stdlib.h>
#include <list.h>
#include "function.h"

void clearInput() {
    while((getchar()) != '\n' && getchar() != EOF) {}
}

//Metodas paimtas is https://github.com/janenas-luk/linked_list_address_book/blob/main/helpers.c
void parse_user_input(char *name, char *surname, char *email, char *number)
{
    printf("\nEnter First name: ");
    fscanf(stdin, "%30s", name);

    printf("Enter Last name: ");
    fscanf(stdin, "%30s", surname);

    printf("Enter email: ");
    fscanf(stdin, "%52s", email);

    printf("Enter number: ");
    fscanf(stdin, "%30s", number);

}

void func_add(struct Person **list) {

    char name[30], surname[30], number[25], email[50];
    struct Person *person = NULL;

    printf("Enter person' information\n");
    parse_user_input(name, surname, email, number);
    person = create_node(name, surname, number, email);
    add_to_list(list, person);

}

void func_add_index(struct Person **list) {
    char name[30], surname[30], number[25], email[50];
    struct Person *person = NULL;

    int ind = -1;
    printf("Enter person' information\n");
    parse_user_input(name, surname, email, number);
    person = create_node(name, surname, number, email);

    printf("Enter index\n");
    scanf("%12d", &ind);
    clearInput();

    if((ind >=0) && (ind < getSize(*list))) 
        add_by_index(list, person, ind);
    else
        printf("Netinkamas indeksas\n");
}

void func_remove_index(struct Person **list) {
    int ind = -1;
    printf("Enter index for removal\n");
    scanf("%d", &ind);
    clearInput();
    if((ind >=0) && (ind < getSize(*list))) 
        remove_by_index(list, ind);
    else
        printf("Netinkamas indeksas\n");
}

void func_find_index(struct Person *list) {
    int ind = -1;
    printf("Select index of a person\n");
    scanf("%12d", &ind);
    clearInput();
    struct Person *p = NULL;
    if((ind >= 0) && (ind < getSize(list)))
        p = find_node(list, ind);
    else 
        p = NULL;
    if(p != NULL)
        printf("%s %s %s %s\n",p->name,p->surname,p->number,p->email);
    else
        printf("Did not find person by selected index\n");       
}

void func_find_criteria(struct Person *list) {
    int ind = -1;
    char data[50]; 
    printf("Select filter for search\n");
    scanf("%12d", &ind);
    clearInput();
    printf("Input data to search for\n");
    scanf("%48[^\n]s", data);
    struct Person *p = NULL;
    if(ind >= 0) 
        p = find_node_text(list, ind, data);
    else 
        p = NULL;

    if(p != NULL) {
        print_list(p);
        free(p);
    }
    else
        printf("Did not find the person\n");
}
