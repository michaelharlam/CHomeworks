#include "states.h"
#include "hashTable.h"
#include "tests.h"


int main(void) {
    if (!runTests) {
        return 1;
    }

    HashTable *statesOnGraph = states("testfile.txt");
    destroyHashTable(&statesOnGraph);
}
