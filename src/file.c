#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/file.h"

void select_file(char *file_path){
    if (fgets(file_path, 256, stdin) != NULL) {
        size_t len = strlen(file_path);
        if (len > 0 && file_path[len - 1] == '\n') {
            file_path[len - 1] = '\0'; // Remove newline character
        }
    } else {
        fprintf(stderr, "Error reading file path.\n");
        exit(EXIT_FAILURE);
    }
}

void read_file(const char *file_path, int start_line, int line_count){
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", file_path);
        return;
    }

    char line[256];
    int current_line = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        if (current_line >= start_line && current_line < start_line + line_count) {
            printf("%s", line);
        }
        current_line++;
    }

    fclose(file);
}


void write_file(const char *file_path, const char *content){
    FILE *file = fopen(file_path, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file for writing: %s\n", file_path);
        return;
    }

    if (fprintf(file, "%s", content) < 0) {
        fprintf(stderr, "Error writing to file: %s\n", file_path);
    }

    fclose(file);
}