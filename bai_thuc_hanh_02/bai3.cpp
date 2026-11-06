#include <stdio.h>
#include <stdlib.h>
typedef struct SinhVien
{
    char hten[50];
    int masv;
    float d1, d2, d3;
}SinhVien;

int main () {
    int n;
    printf("Nhap so sinh vien: ");
    scanf("%d", &n);
    SinhVien *danhsach = (SinhVien *)malloc(n * sizeof(SinhVien));
    if (danhsach == NULL) {
        printf("Khong du bo nho\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        scanf("%s %d %f %f %f", danhsach[i].hten, &danhsach[i].masv, &danhsach[i].d1, &danhsach[i].d2, &danhsach[i].d3 );
    }
    for (int i = 0; i < n; i++){
        printf("%s %d %.2f %.2f %.2f\n", danhsach[i].hten, danhsach[i].masv, danhsach[i].d1, danhsach[i].d2, danhsach[i].d3);
    }
    free(danhsach);
}