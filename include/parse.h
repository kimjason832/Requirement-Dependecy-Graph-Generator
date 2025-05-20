#ifndef PARSE_H
#define PARSE_H

#include "dependency.h"
#include <stdio.h>

// parses the SRS to get requirements and its relationship with other requirements
void parseSRS(const char *filename);

// prints the dependency list of all requirements and how they are related
void printDependencyList(const MODULE_LIST *list);

// prints individual modules
void printModule(const MODULE *module);

#endif