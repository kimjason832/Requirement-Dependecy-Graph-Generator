#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void select_file(char *file_path);
void read_file(const char *file_path);
void write_file(const char *file_path, const char *content);

#endif // FILE_H