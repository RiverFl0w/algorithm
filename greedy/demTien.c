#include <stdio.h>

int main() {
    int menhGia[] = { 500000, 200000, 100000, 50000, 20000, 10000 };
    int ketQua[6] = { 0, 0, 0, 0, 0, 0 };
    int tien;
    scanf("%d", &tien);
    if (tien / 10000 != tien / 10000.0) {
        printf("KHONG RUT DUOC");
        return 0;
    }
    for (int i = 0; tien != 0; i++) {
        ketQua[i] = tien / menhGia[i];
        tien %= menhGia[i];
    }

    for (int i = 0; i < 6; i++) {
        if (ketQua[i] != 0)
        printf("%d VND: %d\n", menhGia[i], ketQua[i]);
    }
    return 0;
}
