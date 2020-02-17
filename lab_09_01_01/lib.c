#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib.h"

int create_matr(matrix_t *my_matrix)
{
    int code_error = TRUE;
    int **buf_matrix = (int **) malloc(my_matrix->row * sizeof(int *));
    if (buf_matrix)
    {
        my_matrix->matrix = buf_matrix;
        buf_matrix = NULL;
        for (int i = 0; i < my_matrix->row; i++)
        {
            int *buf_array = (int *) malloc(my_matrix->column * sizeof(int));
            if (buf_array)
            {
                my_matrix->matrix[i] = buf_array;
                buf_array = NULL;
            }
            else
                code_error = FALSE;
        }
    }
    else
        code_error = FALSE;
    return code_error;
}

void delete_matr(matrix_t *my_matrix)
{
    for (int i = 0; i < my_matrix->row; i++)
    {
        free(my_matrix->matrix[i]);
        my_matrix->matrix[i] = NULL;
    }
    free(my_matrix->matrix);
    my_matrix->matrix = NULL;
}

int make_sqare_matr(matrix_t *my_matrix, int *position)
{
    int code_error = TRUE;
    while (my_matrix->row != my_matrix->column)
    {
        find_position_max_elem(my_matrix, position);

        if (my_matrix->column > my_matrix->row)
            code_error = delete_column(my_matrix, position);
        else if (my_matrix->row > my_matrix->column)
            code_error = delete_row(my_matrix, position);
    }
    return code_error;
}

void find_position_max_elem(matrix_t *my_matrix, int *position)
{
    int max_elem = my_matrix->matrix[0][0];

    for (int i = 0; i < my_matrix->row; i++)
        for (int j = 0; j < my_matrix->column; j++)
        {
            if (my_matrix->matrix[i][j] > max_elem)
            {
                max_elem = my_matrix->matrix[i][j];
                position[0] = i;
                position[1] = j;
            }
        }
}

int delete_row(matrix_t *my_matrix, int *position)
{
    int code_error = TRUE;
    int i = position[0];
    free(my_matrix->matrix[i]);
    my_matrix->matrix[i] = NULL;

    my_matrix->row = my_matrix->row - 1;

    for (int j = i; j < my_matrix->row; j++)
        my_matrix->matrix[j] = my_matrix->matrix[j + 1];

    code_error = realloc_to_row_matr(my_matrix, position);
    return code_error;
}

int realloc_to_row_matr(matrix_t *my_matrix, int *position)
{
    int code_error = TRUE;
    int **buf_matrix = (int **) realloc(my_matrix->matrix, my_matrix->row * sizeof(int *));
    if (buf_matrix)
    {
        my_matrix->matrix = buf_matrix;
        buf_matrix = NULL;
    }
    else
        code_error = FALSE;

    return code_error;
}

int delete_column(matrix_t *my_matrix, int *position)
{
    int code_error = TRUE;
    int k = position[1];

    my_matrix->column = my_matrix->column - 1;

    for (int i = 0; i < my_matrix->row; i++)
        for (int j = k; j < my_matrix->column; j++)
            my_matrix->matrix[i][j] = my_matrix->matrix[i][j + 1];

    code_error = realloc_to_column_matr(my_matrix);
    return code_error;
}

int realloc_to_column_matr(matrix_t *my_matrix)
{
    int code_error = TRUE;
    for (int i = 0; i < my_matrix->row; i++)
    {
        int *buf_matrix = (int *) realloc(my_matrix->matrix[i], my_matrix->column * sizeof(int));
        if (buf_matrix)
        {
            my_matrix->matrix[i] = buf_matrix;
            buf_matrix = NULL;
        }
        else
            code_error = FALSE;
    }
    return code_error;
}

void multiplication_quad_matr(matrix_t *matrix_first, matrix_t *matrix_second, matrix_t *matrix_result)
{
    for (int i = 0; i < matrix_result->row; i++)
        for (int j = 0; j < matrix_result->column; j++)
        {
            matrix_result->matrix[i][j] = 0;
            for (int k = 0; k < matrix_second->row; k++)
                matrix_result->matrix[i][j] += matrix_first->matrix[i][k] * matrix_second->matrix[k][j];
        }
}

int pow_matr(matrix_t *matrix_to_pow, matrix_t *matrix_result, int pow)
{
    int code_error = TRUE;
    if (!pow)
        unit_matrix(matrix_result);
    else if (pow == 1)
        copy_for_matr(matrix_result, matrix_to_pow);
    else
    {
        matrix_t matrix_temp;
        matrix_temp.row = matrix_result->row;
        matrix_temp.column = matrix_result->column;
        code_error = create_matr(&matrix_temp);
        if (!code_error)
        {
            copy_for_matr(&matrix_temp, matrix_to_pow);

            for (int i = 0; i < pow - 1; i++)
            {
                multiplication_quad_matr(&matrix_temp, matrix_to_pow, matrix_result);
                copy_for_matr(&matrix_temp, matrix_result);
            }
            delete_matr(&matrix_temp);
        }
    }
    return code_error;
}

void copy_for_matr(matrix_t *matrix_to, matrix_t *matrix_from)
{
    for (int i = 0; i < matrix_to->row; i++)
        for (int j = 0; j < matrix_to->column; j++)
            matrix_to->matrix[i][j] = matrix_from->matrix[i][j];
}

void unit_matrix(matrix_t *my_matrix)
{
    for (int i = 0; i < my_matrix->row; i++)
        for (int j = 0; j < my_matrix->column; j++)
        {
            if (i == j)
                my_matrix->matrix[i][j] = 1;
            else
                my_matrix->matrix[i][j] = 0;
        }
}

int choice(matrix_t *my_matrix_a, matrix_t *my_matrix_b)
{
    int code_error = TRUE;
    if (my_matrix_b->row > my_matrix_a->row)
        code_error = add_row_to_matr(my_matrix_a, my_matrix_b);
    else
        code_error = add_row_to_matr(my_matrix_b, my_matrix_a);

    if (!code_error)
    {
        if (my_matrix_b->column > my_matrix_a->column)
            code_error = add_value_to_column(my_matrix_a, my_matrix_b);
        else
            code_error = add_value_to_column(my_matrix_b, my_matrix_a);
    }
    return code_error;
}

int add_value_to_column(matrix_t *my_matrix, matrix_t *my_matrix_max)
{
    int code_error = TRUE;
    while (my_matrix->column != my_matrix_max->column)
    {
        code_error = realloc_new_column(my_matrix);
        for (int i = 0; i < my_matrix->row; i++)
            my_matrix->matrix[i][my_matrix->column - 1] = calculate_max_in_row(my_matrix, i);
    }
    return code_error;
}

int calculate_max_in_row(matrix_t *my_matrix, int number_row)
{
    int max_elem = my_matrix->matrix[number_row][my_matrix->column - 2];

    for (int i = 0; i < my_matrix->column - 1; i++)
        if (my_matrix->matrix[number_row][i] > max_elem)
            max_elem = my_matrix->matrix[number_row][i];

    return max_elem;
}

int realloc_new_column(matrix_t *my_matrix)
{
    int code_error = TRUE;
    my_matrix->column += 1;

    for (int i = 0; i < my_matrix->row; i++)
    {
        int *buf_matrix = (int *) realloc(my_matrix->matrix[i], my_matrix->column * sizeof(int));
        if (buf_matrix)
        {
            my_matrix->matrix[i] = buf_matrix;
            buf_matrix = NULL;
        }
        else
            code_error = FALSE;
    }
    return code_error;
}

int add_row_to_matr(matrix_t *my_matrix, matrix_t *my_matrix_max)
{
    int code_error = TRUE;
    while (my_matrix->row != my_matrix_max->row)
    {
        code_error = realloc_new_row(my_matrix);
        for (int i = 0; i < my_matrix->column; i++)
            my_matrix->matrix[my_matrix->row - 1][i] = calculate_average_column(my_matrix, i);
    }
    return code_error;
}

int calculate_average_column(matrix_t *my_matrix, int number_column)
{
    double sum = 0;
    for (int i = 0; i < my_matrix->row - 1; i++)
        sum += my_matrix->matrix[i][number_column];

    return floor(sum / (my_matrix->row - 1));
}

int realloc_new_row(matrix_t *my_matrix)
{
    int code_error = TRUE;
    my_matrix->row += 1;

    int **buf_matrix = (int **)realloc(my_matrix->matrix, my_matrix->row * sizeof(int *));
    if (buf_matrix)
    {
        my_matrix->matrix = buf_matrix;
        buf_matrix = NULL;
        my_matrix->matrix[my_matrix->row - 1] = NULL;

        for (int i = 0; i < my_matrix->row; i++)
        {
            int *buf_array = (int *) realloc(my_matrix->matrix[i], my_matrix->column * sizeof(int));
            if (buf_array)
            {
                my_matrix->matrix[i] = buf_array;
                buf_array = NULL;
            }
            else
                code_error = FALSE;
        }
    }
    else
        code_error = FALSE;
    return code_error;
}
