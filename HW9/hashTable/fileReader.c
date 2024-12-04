#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool fileReader(char *array, int *arrayLength, char *fileName) {
    FILE *arrayFile;
    arrayFile = fopen(fileName, "r");
    if (arrayFile == NULL) {
        printf("Error opening file\n");
        return false;
    }
    char i = 0;
    fscanf(arrayFile, "%c\n", &array[i]);
    while (array[i] != EOF) {
        fscanf(arrayFile, "%c\n", &array[i]);
        ++i;
    }
    *arrayLength = i + 1;
    fclose(arrayFile);
    return true;
}