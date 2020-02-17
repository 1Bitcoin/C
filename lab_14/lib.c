#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "lib.h"

int calc_average(int *array, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += *(array + i);

    return (sum / size);
}

void delete_elems_array(int **array, int *p_size, int number_to_compare, int *code_error)
{
    for (int i = 0; i < *p_size; i++)
        if (*((*array) + i) > number_to_compare)
        {
            for (int j = i + 1; j < *p_size; j++)
                *((*array) + j - 1) = *((*array) + j);
            (*p_size)--;
            i--;
        }
    realloc_to_array(array, *p_size, code_error);
}

void realloc_to_array(int **array_to_increase, int p_size, int *code_error)
{
    int *buf_array = realloc(*array_to_increase, p_size * sizeof(int));
    if (buf_array)
    {
        (*array_to_increase) = buf_array;
        buf_array = NULL;
    }
    else
        (*code_error) = FALSE;
}

void find_max(int *array, int p_size, int *max_number)
{
    *max_number = *(array);

    for (int i = 1; i < p_size; i++)
        if (*(array + i) > *max_number)
            *max_number = *(array + i);
}

void add_numbers(int **array, int *p_size, int number_to_add, int position, int *code_error)
{
    (*p_size) += COUNT_NEW_NUMBERS;
    realloc_to_array(array, *p_size, code_error);

    if (!(*code_error))
    {
        for (int j = (*p_size) - 3; j > position; j--)
            *((*array) + j) = *((*array) + j - 1);

        *((*array) + position) = number_to_add;

        for (int j = (*p_size) - 2; j > 0; j--)
            *((*array) + j) = *((*array) + j - 1);

        *((*array) + 0) = number_to_add;
        *((*array) + (*p_size) - 1) = number_to_add;
    }
}
