#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init(int* arr, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = 1 + rand() % 99;
    }
}
void display(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%5d", arr[i]);
    }
    printf("\n");
}
void interChangeSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[i]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int* arr = (int*)malloc(sizeof(int) * n);
    init(arr, n);
    display(arr, n);
    interChangeSort(arr, n);
    display(arr, n);
    free(arr);
    return 0;
}