#include <stdio.h>
#include <math.h>
using namespace std;

#define PI 3.14159265358979323846

void draw_star(int size) {
    char canvas[50][50] = { ' ' }; // T?o m?t "khung" kích thý?c 50x50
    int center_x = 25, center_y = 25; // Tâm ngôi sao

    // T?a ð? c?a các ð?nh ngôi sao (5 cánh)
    double outer_points[5][2]; // Ð?nh ngoài
    double inner_points[5][2]; // Ð?nh trong

    // Góc chia ð?u cho 5 cánh và 5 góc bên trong
    for (int i = 0; i < 5; i++) {
        // Tính t?a ð? các ð?nh ngoài (cánh ngôi sao)
        outer_points[i][0] = center_x + size * cos(2 * PI * i / 5 - PI / 2);
        outer_points[i][1] = center_y + size * sin(2 * PI * i / 5 - PI / 2);

        // Tính t?a ð? các ð?nh trong (góc bên trong ngôi sao)
        inner_points[i][0] = center_x + (size / 2.5) * cos(2 * PI * (i + 0.5) / 5 - PI / 2);
        inner_points[i][1] = center_y + (size / 2.5) * sin(2 * PI * (i + 0.5) / 5 - PI / 2);
    }

    // N?i các ð?nh ð? t?o h?nh ngôi sao
    for (int i = 0; i < 5; i++) {
        // N?i ð?nh ngoài v?i ð?nh trong ti?p theo
        int x1 = round(outer_points[i][0]), y1 = round(outer_points[i][1]);
        int x2 = round(inner_points[(i + 1) % 5][0]), y2 = round(inner_points[(i + 1) % 5][1]);

        // N?i các ð?nh b?ng cách v? các ðý?ng th?ng
        for (int j = 0; j <= size; j++) {
            int x = x1 + (x2 - x1) * j / size;
            int y = y1 + (y2 - y1) * j / size;
            canvas[y][x] = '*';
        }

        // N?i ð?nh trong v?i ð?nh ngoài ti?p theo
        x1 = round(inner_points[i][0]), y1 = round(inner_points[i][1]);
        x2 = round(outer_points[(i + 1) % 5][0]), y2 = round(outer_points[(i + 1) % 5][1]);

        for (int j = 0; j <= size; j++) {
            int x = x1 + (x2 - x1) * j / size;
            int y = y1 + (y2 - y1) * j / size;
            canvas[y][x] = '*';
        }
    }

    // In canvas ra màn h?nh
    for (int y = 0; y < 50; y++) {
        for (int x = 0; x < 50; x++) {
            printf("%c", canvas[y][x]);
        }
        printf("\n");
    }
}

int main() {
    int size = 10; // Kích thý?c ngôi sao (ð? dài cánh)
    draw_star(size);
    return 0;
}

