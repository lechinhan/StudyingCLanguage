#include <stdio.h>

void init(long long int arr[][50], int m, int n) {
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (j == 0 || j == i) {
                arr[i][j] = 1;
            } else {
                arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j]);
            }
        }
    }
}
void write(long long int arr[][50], int m, int n) {
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%lld ", arr[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int m = n;
    long long int arr[50][50];
    init(arr, m, n);
    write(arr, m, n);
    return 0;
}