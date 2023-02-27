#include <stdio.h>
#include <stdlib.h>

int main() {
    for (int i = 0; i < 65535; i++) {
        char premier = 1;
        for (int modulo = 2; modulo < 11; modulo++) {
            if (modulo != i && i%modulo == 0) {
                premier = 0;
                break;
            }
        }
        if (premier == 1) {
            printf("%d \n", i);
        }
    }

    system("pause");

    return 0;
}