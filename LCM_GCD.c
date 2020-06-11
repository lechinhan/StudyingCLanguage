#include <stdio.h>

// Find Greatest Common Divisor (Euclid)
long long int GCD(long long int a, long long int b) {
    a = (a < 0) ? -a : a; // Absolute of a
    b = (b < 0) ? -b : b; // Absolute of b
    return (b == 0) ? a : GCD(b, a % b);
}
// Find Least Common Multiple
long long int LCM(long long int a, long long int b) {
    a = (a < 0) ? -a : a; // Absolute of a
    b = (b < 0) ? -b : b; // Absolute of b
    return ((a * b) / GCD(a, b));
}
int main() {
    long long int a, b;
    scanf("%lld%lld", &a, &b);
    printf("GCD(%lld, %lld) = %lld", a, b, GCD(a, b));
    printf("\nLCM(%lld, %lld) = %lld", a, b, LCM(a, b));
    // Status code green means everything work great !!
}
