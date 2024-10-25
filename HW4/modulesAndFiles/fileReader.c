#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool fileReader(int *array, int arrayLength) {
    FILE *arrayFile;
    arrayFile = fopen("array.txt", "r");
    if (arrayFile == NULL) {
        printf("Error opening file\n");
        return false;
    }

    for (int i = 0; i < arrayLength; i++) {
        fscanf(arrayFile, "%d\n", array[i]);
    }

    fclose(arrayFile);
    return true;
}