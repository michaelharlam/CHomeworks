#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool readFile(char *array, int *arrayLength, char *fileName) {
    FILE *arrayFile;
    arrayFile = fopen(fileName, "r");
    if (arrayFile == NULL) {
        free(arrayFile);
        printf("Error opening file\n");
        return false;
    }
    char i = 0;
    array[i++] = fgetc(arrayFile);
    while (array[i - 1] != -1) {
        array[i++] = fgetc(arrayFile);
    }
    array[i - 1] = '\0';
    *arrayLength = i - 1;
    fclose(arrayFile);
    return true;
}