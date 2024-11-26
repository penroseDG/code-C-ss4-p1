#include <stdio.h>

int main() {
    int n, sum = 0;
    printf("Nhap mot so nguyen duong: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("So ban nhap khong phai la so nguyen duong. Vui long nhap lai.\n");
    }
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    printf("Tong cac so tu 1 den %d la: %d\n", n, sum);

    return 0;
}

