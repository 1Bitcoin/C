#include <stdio.h>
#include <stdlib.h>

double volume(double v1, double v2);
double temp(double v1, double v2, double t1, double t2, double v);

int main()
{
    double v1, v2;
    double t1, t2;

    printf("Input first volume: ");
    scanf("%lf", &v1);
    printf("Input first temp: ");
    scanf("%lf", &t1);

    printf("Input second volume: ");
    scanf("%lf", &v2);
    printf("Input second temp: ");
    scanf("%lf", &t2);

    double t, v;
    v = volume(v1, v2);
    t = temp(v1, v2, t1, t2, v);

    printf("New volume is %lf\nNew temp is %lf\n", v, t);

    return 0;
}

double volume(double v1, double v2)
{
    return v1 + v2;
}

double temp(double v1, double v2, double t1, double t2, double v)
{
    return (t1 * v1 + t2 * v2) / v;
}
