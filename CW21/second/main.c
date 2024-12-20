#include "fileReaderFileWriter.h"
#include <stdbool.h>


int main(void) {
    bool isDone = fileReaderFileWriter("read.txt", "write.txt");
    if (isDone) {
        return 0;
    }
    return 1;
}