#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Nhap so phan tu: ");
    scanf("%d", &n);
    float *mang = (float *)malloc(sizeof(float));
    for (int i = 0; i < n; i++) {
        scanf("%f", &mang[i]);
    }
    for (int i = 0; i < n; i++) {
        printf("%.2f ", mang[i]);
    }
    free(mang);
    return 0;
}