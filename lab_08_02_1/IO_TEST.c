#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "test.h"
#include "IO_TEST.h"

void input(double **array, int *size, int *p, FILE *fin)
{
    realloc_to_array(array, *size, p);
    if (!(*p))
    {
        for (int i = 0; i < *size; i++)
        {
            if (fscanf(fin, "%lf", (*array + i)) != 1)
                *p = FALSE;
        }
    }
}

void output(double *array, int size, FILE *fout)
{
    for (int i = 0; i < size; i++)
        fprintf(fout, " %lf ", *(array + i));
}
