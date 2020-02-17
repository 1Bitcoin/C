#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "list.h"
#include "IO.h"
#include "library_for_task.h"

void make_square_number_in_list(list *list)
{
    node *buf = list->head;
    while (buf)
    {
        ((container *)buf->info)->degree *= 2;
        buf = buf->next;
    }
}

void insert_result_mult(list *res_list, list *f_list, list *s_list)
{
    node *f_buf = f_list->head;
    node *s_buf = s_list->head;

    list *bigger_list = NULL;

    int f_flag_work = 0;
    int s_flag_work = 0;

    bigger_list = is_bigger_list(f_list, s_list);
    node *bigger_buf = bigger_list->head;

    while (bigger_buf)
    {
        if (f_buf && s_buf)
        {
            if (get_coefficient_from_node(f_buf) > get_coefficient_from_node(s_buf))
            {
                push_back(res_list, get_coefficient_from_node(f_buf), get_degree_from_node(f_buf));
                f_flag_work = 1;
            }
            else if (get_coefficient_from_node(f_buf) < get_coefficient_from_node(s_buf))
            {
                push_back(res_list, get_coefficient_from_node(s_buf), get_degree_from_node(s_buf));
                s_flag_work = 1;
            }
            else
            {
                push_back(res_list, get_coefficient_from_node(s_buf), get_degree_from_node(f_buf) + get_degree_from_node(s_buf));
                f_flag_work = 1;
                s_flag_work = 1;
            }
        }
        else if (f_buf)
        {
            push_back(res_list, get_coefficient_from_node(f_buf), get_degree_from_node(f_buf));
            f_flag_work = 1;
        }
        else if (s_buf)
        {
            push_back(res_list, get_coefficient_from_node(s_buf), get_degree_from_node(s_buf));
            s_flag_work = 1;
        }

        if ((bigger_buf == f_buf && f_flag_work) || (bigger_buf == s_buf && s_flag_work))
            bigger_buf = bigger_buf->next;

        if (s_flag_work)
        {
            s_buf = s_buf->next;
            s_flag_work = 0;
        }

        if (f_flag_work)
        {
            f_buf = f_buf->next;
            f_flag_work = 0;
        }
    }
}

list *is_bigger_list(list *f_list, list *s_list)
{
    node *f_buf = f_list->head;
    node *s_buf = s_list->head;
    list *result_list = NULL;

    int len_f_list = 0;
    int len_s_list = 0;

    while (f_buf->next)
    {
        f_buf = f_buf->next;
        len_f_list++;
    }

    while (s_buf->next)
    {
        s_buf = s_buf->next;
        len_s_list++;
    }

    if (len_f_list >= len_s_list)
        result_list = f_list;
    else
        result_list = s_list;

    return result_list;
}

code division(list *first_list, list *second_list, int *result)
{
    code code_error = work;

    int first_number = re_factorization(first_list);
    int second_number = re_factorization(second_list);

    *result = first_number / second_number;

    if (!(*result))
        code_error = bad_input;

    return code_error;
}

int re_factorization(list *list)
{
    node *buf = list->head;
    int number = 1;

    while (buf)
    {
        number *= my_pow(get_coefficient_from_node(buf), get_degree_from_node(buf));
        buf = buf->next;
    }

    return number;
}

int my_pow(int number, int n)
{
    int result = 1;
    while (n > 0)
    {
        result *= number;
        n--;
    }
    return result;
}

int get_coefficient_from_node(node *node)
{
    return ((container *)node->info)->coefficient;
}

int get_degree_from_node(node *node)
{
    return ((container *)node->info)->degree;
}
