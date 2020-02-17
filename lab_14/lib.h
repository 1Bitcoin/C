#ifndef __LIB_H__
#define __LIB_H__

#define TRUE 0
#define FALSE 1
#define COUNT_NEW_NUMBERS 3

int calc_average(int *array, int size);
void delete_elems_array(int **array, int *p_size, int number_to_compare, int *code_error);
void find_max(int *array, int p_size, int *max_number);
void add_numbers(int **array, int *p_size, int number_to_add, int position, int *code_error);
void realloc_to_array(int **array_to_increase, int p_size, int *code_error);

#endif
