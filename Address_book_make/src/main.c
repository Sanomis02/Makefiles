#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <list.h>
#include <pwd.h>
#include <unistd.h>
#include "function.h"

#define SIZE 52

static int run = 1;

void sigint_handler(int signum) {
    printf("SIGINT INITIATED\n");
    run = 0;
}

void drawFunctions();
void drawLine();
void helpWindow();

int main(void) {
    signal(SIGTSTP, sigint_handler);
    struct sigaction sa;
    memset(&sa, 0, sizeof(struct sigaction));
    sa.sa_handler = sigint_handler;
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);

    char *homedir = NULL;
    char *file_path = NULL;

    if((homedir = getenv("HOME")) == NULL) { //Pirmiausiai patikriname $HOME
        homedir = getpwuid(getuid())->pw_dir; //Jei neegzistuoja, getpwuid()
    }

    file_path = strcat(homedir, "/data.csv");

    struct Person *list = NULL;
    FILE *adr_file = NULL;

    adr_file = fopen(file_path, "r");
    if(adr_file != NULL) {
        load_addresses(adr_file, &list);
        fclose(adr_file);
    }
    else
        printf("Unable to find file in %s\n", homedir);

    char ctrl[12];

    drawLine();
    drawFunctions();
    drawLine();
    helpWindow();
    drawLine();
    //Kurias mygtuku kombinacijas
    while(run) {
        printf("What function to perform?\n");
        scanf(" %10[^\n]s", ctrl);
        switch(*ctrl) {
            case '0': //draw functions
                drawFunctions();
                break;
            case '1': //print list
                print_list(list);
                printf("Amount: %d\n",getSize(list));
                break;
            case '2': //add element to the end
                func_add(&list);
                break;
            case '3': //add element by index
                func_add_index(&list);
                break;
            case '4': //remove element by index
                func_remove_index(&list);
                break;
            case '5': //destroy list
                printf("Destroying list ...\n");
                delete_list(&list);
                //goto CLEAN_UP;
                break;
            case '6': //find person by index
                func_find_index(list);
                break;
            case '7': //find person by chosen criteria
                func_find_criteria(list);
                break;
            case '8': //help window
                helpWindow();
                break;
            case '9':
                printf("Stopping program...\n");
                run = 0;
                break;
            default:
                printf("Did not select viable option, try again\n");
                break;
        }
    }
    delete_list(&list);
    return 0;
}

void drawLine() {
    printf("%0*d\n", SIZE, 0);
}

void drawFunctions() {
    printf("        Functions       \n");
    printf("[1] - view list\n");
    printf("[2] - add element to end\n");
    printf("[3] - add element by index\n");
    printf("[4] - remove element by index\n");
    printf("[5] - destroy list\n");
    printf("[6] - find person by index\n");
    printf("[7] - find person by chosen criteria\n");
    printf("[8] - help\n");
}

void helpWindow() {
    printf("        Search options      \n");
    printf("[10] - searches by name\n");
    printf("[11] - searches by surname\n");
    printf("[12] - searches by email\n");
    printf("[13] - searches by number\n");
    printf("\n");
    printf("        Program options     \n");
    printf("[9] - quits program\n");
    printf("[0] - function window\n");
}
