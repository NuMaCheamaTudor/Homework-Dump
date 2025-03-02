#include <stdio.h>

double sinh_taylor(double x, int n) {
    double result = 0.0;
    double power = x;
    double factorial = 1.0;
    for (int i = 1; i <= n; ++i) {
        result += power / factorial;
        power *= x * x;
        factorial *= (2 * i) * (2 * i + 1);
    }
    return result;
}

int main() {
    double x;
    int n;
    printf("Introduceți valoarea lui x: ");
    scanf("%lf", &x);
    printf("Introduceți numărul de termeni pentru dezvoltarea Taylor: ");
    scanf("%d", &n);
    double result = sinh_taylor(x, n);
    printf("sinh(%.10f) ≈ %.10f\n", x, result);
    return 0;
}
