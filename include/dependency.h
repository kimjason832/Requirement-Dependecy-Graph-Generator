#ifndef DEPENDENCY
#define DEPENDENCY

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct MODULE {
    char name[20];
    int dependent_on_length;
    MODULE_LIST *dependent_on;
    int depencies_length;
    MODULE_LIST *dependncies;
    
};

struct MODULE_LIST {
    int length;
    char *dependency_list_start[20];
    char *dependency_list_end[20];
};

void createModule(char name[20], int dependent_on_length, MODULE_LIST *dependent_on, int depencies_length, MODULE_LIST *dependncies);

void createModuleList(int length, char *dependency_list_start[20], char *dependency_list_end[20]);


#endif