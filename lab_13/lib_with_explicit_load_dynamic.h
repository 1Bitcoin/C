#ifndef __LIB_WITH_EXPLICIT_LOAD_DYNAMIC_H__
#define __LIB_WITH_EXPLICIT_LOAD_DYNAMIC_H

#define TRUE 0
#define FALSE 1
#define COUNT_NEW_NUMBERS 3

double calc_average(double *array, int size);
void delete_elems_array(double **array, int *p_size, double number_to_compare, int *code_error, void *dynamic_library);
void find_max(double *array, int p_size, double *max_number);
void add_numbers(double **array, int *p_size, double number_to_add, int position, int *code_error, void *dynamic_library);
void realloc_to_array(double **array_to_increase, int p_size, int *code_error);

#endif
