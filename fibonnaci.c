#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned long F0 = 0;
    unsigned long F1 = 1;
    unsigned long F2 = F0 + F1;

    printf("%d \n", F0);
    printf("%d \n", F1);

    for (int i = 0; i < 45; i++) {
        printf("%d \n", F2);
        F0 = F1;
        F1 = F2;
        F2 = F0 + F1;
    }

    return 0;
}