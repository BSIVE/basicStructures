
#include <stdio.h>

void main(int argc, char** argv) {
    int odds[] = { 1, 3, 5, 7, 9 };

    for (int i = 0; i < sizeof(odds) / sizeof(int); i++) {
        printf("  odds[%d] = %d\n", i, odds[i]);
    }
}

// array.c
