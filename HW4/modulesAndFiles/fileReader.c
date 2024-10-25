#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool fileReader(int *array, int arrayLength, char *fileName) {
    FILE *arrayFile;
    arrayFile = fopen(fileName, "r");
    if (arrayFile == NULL) {
        printf("Error opening file\n");
        return false;
    }

    for (int i = 0; i < arrayLength; i++) {
        fscanf(arrayFile, "%d\n", &array[i]);
    }

    fclose(arrayFile);
    return true;
}