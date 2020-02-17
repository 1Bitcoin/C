#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "IO_LIB.h"
#include "lib.h"

void input(double **array, int *size, int *p)
{
    realloc_to_array(array, *size, p);
    if (!(*p))
    {
        for (int i = 0; i < *size; i++)
        {
            if (scanf("%lf", (*array + i)) != 1)
                *p = FALSE;
        }
    }
}

void output(double *array, int size)
{
    for (int i = 0; i < size; i++)
        printf(" %lf ", *(array + i));
}
