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
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > i; j--) {
            if (arr[j - 1] > arr[j]) {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
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
    bubbleSort(arr, n);
    display(arr, n);
    free(arr);
    return 0;
}
