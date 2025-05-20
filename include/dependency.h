#ifndef DEPENDENCY_H
#define DEPENDENCY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct for the list of modules to show start and end of the related requirements
typedef struct{
    int length;
    char *dependency_list_start;
    char *dependency_list_end;
} MODULE_LIST;

// struct for a module that shows what it depends on and what is dependent on it
typedef struct {
    char name[20];
    int dependent_on_length;
    MODULE_LIST *dependent_on;
    int dependencies_length;
    MODULE_LIST *dependencies;
} MODULE;

// creates a list of modules which includes linked requirements
MODULE_LIST createModuleList(int length, char *dependency_list_start[20], char *dependency_list_end[20]);

// creates a module for a given requirement
MODULE *createModule(char name[20], int dependent_on_length, MODULE_LIST *dependent_on, int dependencies_length, MODULE_LIST *dependencies);

// adds a module to the module list
void appendModule(MODULE_LIST *list, MODULE *module);

#endif