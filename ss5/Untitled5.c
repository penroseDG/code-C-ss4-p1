#include <stdio.h>

int main() {
    for (int n = 1; n <= 9; n++) {
        printf("Bang cuu chuong cua %d:\n", n);
        for (int i = 1; i <= 10; i++) {
            printf("%d x %d = %d\n", n, i, n * i);
        }
        printf("\n");
    }

    return 0;
}

