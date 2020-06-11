#include <stdio.h>

int maxDay[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int isLeapYear(int n) {
    return ((n % 4 == 0 && n % 100 != 0) || (n % 400 == 0));
}
int main(void) {
    int d, m;
    printf("Enter day, month of 2019: ");
    scanf("%d%d", &d, &m);
    int year = 2019, num;
    printf("Enter number of add days: ");
    scanf("%d", &num);
    d += num;
    while (d > maxDay[m]) {
        d -= maxDay[m];
        m++;
        if (m > 12) {
            m = 1;
            year++;
            maxDay[2] += isLeapYear(year);
        }
    }
    printf("The date after %d days is %02d/%02d/%04d", num, d, m, year);
    return 0;
}