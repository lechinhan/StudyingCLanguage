#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpfun(const void* a, const void* b) {
    // Compared with lastname
    int n = strcmp(strrchr(a, ' '), strrchr(b, ' '));
    return n;
}
int main(void) {
    char list[40][50];
    int n;
    printf("Enter number of names: ");
    scanf("%d\n", &n);
    // Get n names
    for (int i = 0; i < n; i++) {
        scanf("%[^\n]%*c", &list[i]);
    }
    // Sorting list name 
    qsort(list, n, sizeof(list[0]), cmpfun);
    printf("\n");
    // Put list name onscreen
    for (int i = 0; i < n; i++) {
        printf("%d) %s\n", i + 1, list[i]);
    }
    return 0;
}