#include <math.h>
#include <stdio.h>

double myAbs(double n) { return (n >= 0) ? n : -n; }
double myRoot(double a, int n, double ep) {
    double x0 = a / n;
    float x_kth = myAbs(((n - 1) * pow(x0, n) + a) / (n * pow(x0, n - 1)));
    do {
        x_kth = myAbs(((n - 1) * pow(x0, n) + a) / (n * pow(x0, n - 1)));
        x0 = x_kth;
    } while (myAbs(a - pow(x0, n)) >= ep);
    return x_kth;
}
int main() {
    int n;
    double a, ep;
    scanf("%lf%d%lf", &a, &n, &ep);
    printf("%.8lf\n", myRoot(a, n, ep));
    return 0;
}