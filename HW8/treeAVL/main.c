#include "dictionary.h"
#include "tests.h"


int main(void) {
   if (!runTests()) {
        return 1;
    }
    dictionary();
    return 0;
}