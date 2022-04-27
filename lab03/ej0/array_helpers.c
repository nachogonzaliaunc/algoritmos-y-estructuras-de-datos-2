#include <stdlib.h>
#include <stdio.h>

unsigned int data_from_file(const char *path,
                            unsigned int indexes[],
                            char letters[],
                            unsigned int max_size) {
    
    unsigned int counter = 0;
    unsigned int counter_int = 0;
    unsigned int counter_char = 0;

    FILE *file;
    file = fopen(path, "r");
    while(!feof(file)) {
        if((counter % 2) == 0) {
            fscanf(file, "%u\n", &indexes[counter_int]);
            counter_int++;
        } else {
            fscanf(file, "%c\n", &letters[counter_char]);
            counter_char++;
        }
        counter++;
    }

    max_size = counter;

    fclose(file);

    return max_size;
}