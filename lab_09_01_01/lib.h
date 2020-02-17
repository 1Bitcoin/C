#ifndef __LIB_H__
#define __LIB_H__

#define TRUE 0
#define FALSE 1
#define ERROR_INPUT 2

typedef struct
{
    int **matrix;
    int row;
    int column;
}matrix_t;

int create_matr(matrix_t *my_matrix);
void delete_matr(matrix_t *my_matrix);
void find_position_max_elem(matrix_t *my_matrix, int *position);
int make_sqare_matr(matrix_t *my_matrix, int *position);
int delete_row(matrix_t *my_matrix, int *position);
int realloc_to_row_matr(matrix_t *my_matrix, int *position);
int delete_column(matrix_t *my_matrix, int *position);
int realloc_to_column_matr(matrix_t *my_matrix);
int add_row_to_matr(matrix_t *my_matrix, matrix_t *my_matrix_max);
int calculate_average_column(matrix_t *my_matrix, int number_column);
int realloc_new_row(matrix_t *my_matrix);
int realloc_new_column(matrix_t *my_matrix);
int add_value_to_column(matrix_t *my_matrix, matrix_t *my_matrix_max);
int calculate_max_in_row(matrix_t *my_matrix, int number_row);
void multiplication_quad_matr(matrix_t *matrix_first, matrix_t *matrix_second, matrix_t *matrix_result);
int pow_matr(matrix_t *matrix_to_pow, matrix_t *matrix_result, int pow);
void copy_for_matr(matrix_t *matrix_to, matrix_t *matrix_from);
void unit_matrix(matrix_t *my_matrix);
int choice(matrix_t *my_matrix_a, matrix_t *my_matrix_b);

#endif
