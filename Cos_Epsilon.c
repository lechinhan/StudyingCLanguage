#include <stdio.h>

// const double pi = 3.141592653;

double power(double a, int n) { return n == 0 ? 1 : (a * power(a, n - 1)); }
double fac(int n) { return n == 0 ? 1 : n * fac(n - 1); }
double my_abs(double n) { return n < 0 ? -n : n; }
double cosin(double x, double ep) {
    int n = 0;
    double kq = 0;
    double k = 0;

    while (1) {
        k = (power(-1.0, n) * ((power(x, 2 * n)) / fac(2 * n)));
        kq += k;
        n++;
        if (ep >= my_abs(k)) {
            break;
        }
    }
    return kq;
}
int main() {
    const double pi = 3.141592653;
    printf("%.10lf", cosin(pi / 3, 0.0000000001));
    return 0;
}
