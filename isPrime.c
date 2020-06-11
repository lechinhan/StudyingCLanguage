#include <math.h>
#include <stdio.h>
int isPrime(long long int n) {
    if (n == 2)
        return 1;
    if (n == 1 || n % 2 == 0)
        return 0;
    for (int i = 3; i <= (int)sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}
int main() {
    long long int n;
    scanf("%lld", &n);
    if (isPrime(n)) {
        return (int)printf("%lld is a prime number", n);
    } else {
        return (int)printf("%lld is not a prime number", n);
    }
}