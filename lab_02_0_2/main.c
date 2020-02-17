#include <stdio.h>
#include <stdlib.h>

#define TRUE 0
#define FALSE 1

struct point
{
    double x;
    double y;
};
double calc_scalar(struct point *a, struct point *b, struct point *c);
double vector_mult(struct point *a, struct point *b, struct point *c);

int main()
{
    struct point a;
    struct point b;
    struct point c;

    int out = TRUE;

    printf("Enter coordinates: ");
    int rc = scanf("%lf %lf %lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y);
    if (rc == 6 && vector_mult(&a, &b, &c) != 0.0)
    {
        if (calc_scalar(&a, &b, &c) == 0)
            printf("1");
        else if (calc_scalar(&a, &b, &c) < 0)
            printf("0");
        else
            printf("2");
    }
    else
        out = FALSE;

    return out;
}

double calc_scalar(struct point *a, struct point *b, struct point *c)
{
    double a_side = (b->x - a->x) * (c->x - a->x) + (b->y - a->y) * (c->y - a->y);
    double b_side = (c->x - a->x) * (c->x - b->x) + (c->y - a->y) * (c->y - b->y);
    double c_side = (b->x - a->x) * (c->x - b->x) + (b->y - a->y) * (c->y - b->y);

    return a_side * b_side * c_side;
}

double vector_mult(struct point *a, struct point *b, struct point *c)
{
    return ((a->x - c->x) * (b->y - c->y) - (b->x - c->x) * (a->y - c->y));
}
