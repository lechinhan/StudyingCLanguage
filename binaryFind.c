#include <stdio.h>

void read(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}
void write(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}
int binaryFind(int x, int arr[], int n) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == x) {
            return 1;
        } else if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return 0;
}
int main(void) {
    int arr[500];
    int n;
    scanf("%d", &n);
    read(arr, n);
    int x;
    scanf("%d", &x);
    if (binaryFind(x, arr, n)) {
        printf("Co %d trong mang", x);
    } else {
        printf("Khong tim thay %d trong mang", x);
    }
    return 0;
}