#include <stdio.h>
#include <math.h>
using namespace std;

#define PI 3.14159265358979323846

void draw_star(int size) {
    char canvas[50][50] = { ' ' }; // T?o m?t "khung" k�ch th�?c 50x50
    int center_x = 25, center_y = 25; // T�m ng�i sao

    // T?a �? c?a c�c �?nh ng�i sao (5 c�nh)
    double outer_points[5][2]; // �?nh ngo�i
    double inner_points[5][2]; // �?nh trong

    // G�c chia �?u cho 5 c�nh v� 5 g�c b�n trong
    for (int i = 0; i < 5; i++) {
        // T�nh t?a �? c�c �?nh ngo�i (c�nh ng�i sao)
        outer_points[i][0] = center_x + size * cos(2 * PI * i / 5 - PI / 2);
        outer_points[i][1] = center_y + size * sin(2 * PI * i / 5 - PI / 2);

        // T�nh t?a �? c�c �?nh trong (g�c b�n trong ng�i sao)
        inner_points[i][0] = center_x + (size / 2.5) * cos(2 * PI * (i + 0.5) / 5 - PI / 2);
        inner_points[i][1] = center_y + (size / 2.5) * sin(2 * PI * (i + 0.5) / 5 - PI / 2);
    }

    // N?i c�c �?nh �? t?o h?nh ng�i sao
    for (int i = 0; i < 5; i++) {
        // N?i �?nh ngo�i v?i �?nh trong ti?p theo
        int x1 = round(outer_points[i][0]), y1 = round(outer_points[i][1]);
        int x2 = round(inner_points[(i + 1) % 5][0]), y2 = round(inner_points[(i + 1) % 5][1]);

        // N?i c�c �?nh b?ng c�ch v? c�c ��?ng th?ng
        for (int j = 0; j <= size; j++) {
            int x = x1 + (x2 - x1) * j / size;
            int y = y1 + (y2 - y1) * j / size;
            canvas[y][x] = '*';
        }

        // N?i �?nh trong v?i �?nh ngo�i ti?p theo
        x1 = round(inner_points[i][0]), y1 = round(inner_points[i][1]);
        x2 = round(outer_points[(i + 1) % 5][0]), y2 = round(outer_points[(i + 1) % 5][1]);

        for (int j = 0; j <= size; j++) {
            int x = x1 + (x2 - x1) * j / size;
            int y = y1 + (y2 - y1) * j / size;
            canvas[y][x] = '*';
        }
    }

    // In canvas ra m�n h?nh
    for (int y = 0; y < 50; y++) {
        for (int x = 0; x < 50; x++) {
            printf("%c", canvas[y][x]);
        }
        printf("\n");
    }
}

int main() {
    int size = 10; // K�ch th�?c ng�i sao (�? d�i c�nh)
    draw_star(size);
    return 0;
}

