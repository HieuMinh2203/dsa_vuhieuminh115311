#include <stdio.h>
#include <stdlib.h>
int main () {
    int n,m;
    printf("Nhap so hang: ");
    scanf("%d",&n);
    printf("Nhap so cot: ");
    scanf("%d", &m);
    float **ma = (float **)malloc(n * sizeof(float));
    if (ma == NULL) {
        printf("Khong du bo nho\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("Nhap hang %d: \n", i + 1);
        for (int j = 0; j < m; j++){
            
            scanf("%f", &ma[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%.2f ", ma[i][j]);
        }
        printf("\n");
    }
    free(ma);
    return 0;
}