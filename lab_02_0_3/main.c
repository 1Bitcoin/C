#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 0
#define FALSE 1

double approximation(double x, double eps);
double exact_value(double x);
double absolute_error(double x, double eps);
double relative_error(double x, double eps);

int main()
{
    double x;
    double eps;
    int rc;
    int out = TRUE;

    printf("Input x, eps: ");
    rc = scanf("%lf %lf", &x, &eps);
    if (rc == 2 && eps > 0 && eps <= 1)
    {
        printf("f(x) = %.6lf\n", exact_value(x));
        printf("s(x) = %.6lf\n", approximation(x, eps));
        printf("Absolute error: %.6lf\n", absolute_error(x, eps));
        printf("Relative error: %.6lf\n", relative_error(x, eps));
    }
    else
        out = FALSE;

    return out;
}

double approximation(double x, double eps)
{
    double s = 0;
    double q = 1;
    int i = 1;

    while (fabs(q) > eps)
    {
        s += q;
        q *= x / i;
        i ++;
    }
    return s;
}

double exact_value(double x)
{
    return exp(x);
}

double absolute_error(double x, double eps)
{
    return fabs(exact_value(x) - approximation(x, eps));
}

double relative_error(double x, double eps)
{
    return fabs((exact_value(x) - approximation(x, eps)) / exact_value(x));
}

