#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265

double square(double a, double b, double alpha);

int main()
{
    double a, b;

    printf("Input base A: ");
    scanf("%lf", &a);

    printf("Input base B: ");
    scanf("%lf", &b);

    double alpha;

    printf("Input angle with large base: ");
    scanf("%lf", &alpha);

    printf("%.5lf", square(a, b, alpha));
    return 0;
}

double square(double a, double b, double alpha)
{
    alpha *= (PI / 180); // Transfer to radians
    return fabs(b * b - a * a) * sin(alpha) * sin(alpha) / (2 * sin(2 * alpha));
}

