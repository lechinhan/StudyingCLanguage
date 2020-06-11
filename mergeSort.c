#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init(int* arr, int n) {
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
void mergeSort(int A[], int B[], int C[], int n, int m) {
    int i = 0, j = 0;
    int k = 0;
    while (i < n && j < m) {
        if (A[i] <= B[j]) {
            C[k] = A[i];
            i++;
            k++;
        } else {
            C[k] = B[j];
            j++;
            k++;
        }
    }
    for (; i < n; i++) {
        C[k] = A[i];
        k++;
    }
    for (; j < m; j++) {
        C[k] = B[j];
        k++;
    }
}
int cmpfun(const void* a, const void* b) { return *(int*)a - *(int*)b; }
int main() {
    srand(time(NULL));
    int numA, numB;
    printf("Enter number of listA's element: ");
    scanf("%d", &numA);
    printf("Enter number of listB's element: ");
    scanf("%d", &numB);
    int* listA = (int*)malloc(sizeof(int) * numA);
    int* listB = (int*)malloc(sizeof(int) * numB);
    int* listSorted = (int*)malloc(sizeof(int) * (numA + numB));
    init(listA, numA);
    qsort(listA, numA, sizeof(int), cmpfun);
    init(listB, numB);
    qsort(listB, numB, sizeof(int), cmpfun);
    display(listA, numA);
    display(listB, numB);
    mergeSort(listA, listB, listSorted, numA, numB);
    display(listSorted, numA + numB);
    free(listA);
    free(listB);
    free(listSorted);
    return 0;
}