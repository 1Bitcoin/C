#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Variant 2

int main()
{
    double x;
    double eps;

    printf("Input x, eps: ");
    scanf("%lf %lf", &x, &eps);

    if (fabs(x) < 1)
    {
        int n = 1;
        double t = x;
        double s = x;

        while (fabs(t) > eps)
        {
            n = n + 1;
            t = -t * x * x / ((2 * n - 1) * (2 * n - 2));
            s = s + t;
        }

        printf("approximation = %.5lf\n", s);

        printf("sin(x) = %.5lf", sin(x));
    }
    else
        printf("Error input");

    return 0;
}
