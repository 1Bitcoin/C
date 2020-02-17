#ifndef __LIBRARY_FOR_TASK_H__
#define __LIBRARY_FOR_TASK_H__

#include "list.h"

void make_square_number_in_list(list *list);
void insert_result_mult(list *res_list, list *f_list, list *s_list);
list *is_bigger_list(list *f_list, list *s_list);
code division(list *first_list, list *second_list, int *result);
int re_factorization(list *list);
int my_pow(int number, int n);
int get_coefficient_from_node(node *node);
int get_degree_from_node(node *node);

#endif
