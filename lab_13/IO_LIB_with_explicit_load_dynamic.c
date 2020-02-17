#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "lib_with_explicit_load_dynamic.h"
#include "IO_LIB_with_explicit_load_dynamic.h"

void input(double **array, int *size, int *p, void *dynamic_library)
{
    void (*dll_realloc_to_array)(double **array_to_increase, int p_size, int *code_error);
    dll_realloc_to_array = (void (*) (double **array_to_increase, int p_size, int *code_error))
                            GetProcAddress(dynamic_library, "realloc_to_array");
    dll_realloc_to_array(array, *size, p);
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
