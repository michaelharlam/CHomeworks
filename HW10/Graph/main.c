#include "states.h"
#include "hashTable.h"


int main(void) {
    HashTable *statesOnGraph = states("testfile.txt");
    destroyHashTable(&statesOnGraph);
}
