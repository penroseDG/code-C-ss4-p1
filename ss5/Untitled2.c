#include <stdio.h>

int main() {
    int target = 10; 
    int input;
    printf("Nhap 1 so cho truoc là %d): ", target);
    do {
        scanf("%d", &input);  
        if (input != target) {
            printf("ban nhap khong dung hay thu lai : ");
        }
    } while (input != target);  
    printf("con ga tru la tion  %d.\n", target);

    return 0;
}

