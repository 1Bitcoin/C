#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "choice.h"
#include "library_for_task.h"
#include "factorization.h"
#include "IO.h"

code choice_actions(FILE *fin, FILE *fout, list *f_list, list *s_list, char *key)
{
    code code_error = work;
    int first_number_to_factorization = 0;
    int second_number_to_factorization = 0;

    if (!strcmp(key, "out") || !strcmp(key, "sqr"))
    {
        code_error = enter_one_number(fin, &first_number_to_factorization);

        if (!code_error)
        {
            factors(f_list, first_number_to_factorization);
            if (!strcmp(key, "sqr"))
                make_square_number_in_list(f_list);

            print_linked_list(fout, f_list);
            delete_list(f_list);
        }
    }
    else if (!strcmp(key, "mul") || !strcmp(key, "div"))
    {
        int result;
        code_error = enter_two_number(fin, &first_number_to_factorization, &second_number_to_factorization);

        if (!code_error)
        {
            list res_list;
            res_list.head = NULL;

            factors(f_list, first_number_to_factorization);
            factors(s_list, second_number_to_factorization);

            if (!strcmp(key, "mul"))
                insert_result_mult(&res_list, f_list, s_list);

            if (!strcmp(key, "div"))
            {
                code_error = division(f_list, s_list, &result);
                if (!code_error)
                    factors(&res_list, result);
            }
            if (!code_error)
                print_linked_list(fout, &res_list);

            delete_list(f_list);
            delete_list(s_list);

            if (!code_error)
                delete_list(&res_list);
        }
    }
    else
        code_error = bad_input;

    return code_error;
}
