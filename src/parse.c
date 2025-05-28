#include "../include/parse.h"

void parseSRS(const char *filename){
    //revise the function to print out the line and requirement in this format Line 23: REQ-XX-XXXX-XXXX --
    // "REQ-XX-XXXX-XXXX" is the requirement ID, where XX is a two-digit number and XXXX is a four-digit number.
    // This function will read the SRS file and print out the lines that match the requirement pattern.

    regex_t regex;
    int reti;
    char line[256];

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return;
    }
    reti = regcomp(&regex, "REQ-[0-9]{2}-[0-9]{4}-[0-9]{4}", REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        fclose(file);
        return;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        reti = regexec(&regex, line, 0, NULL, 0);
        if (!reti) {
            printf("Found matching line: %s", line);
        } else if (reti == REG_NOMATCH) {
            // No match found
        } else {
            fprintf(stderr, "Regex match failed\n");
        }
    }

    regfree(&regex);
    fclose(file);
}

void printDependencyList(const MODULE_LIST *list){
    // stub for printDependencyList function, will be implemented in the future
}

void printModule(const MODULE *module){
    // stub for printModule function, will be implemented in the future
}
