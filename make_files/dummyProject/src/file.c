#include <stdio.h>
#include "file.h"

void readFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file) {
        printf("File opened successfully.\n");
        fclose(file);
    } else {
        printf("Failed to open file.\n");
    }
}
