#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initList(int* arr, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 99;
    }
}
void display(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%5d", arr[i]);
    }
    printf("\n");
}
// void countAppear(int* arr, int n) {
//     int count = 1;
//     for (int i = 0; i < n; i++) {
//         if (arr[i] == arr[i + 1]) {
//             count++;
//         } else {
//             printf("%d times of %d\n", count, arr[i]);
//             count = 1;
//         }
//     }
// }
int cmpfunc(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int* arr = (int*)malloc(sizeof(int) * n);
    initList(arr, n);
    display(arr, n);
    qsort(arr, n, sizeof(int), cmpfunc);
    display(arr, n);
    // countAppear(arr, n);
    free(arr);
    return 0;
}