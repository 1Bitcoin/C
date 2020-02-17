#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void print_linked_list(FILE *fout, list *list)
{
    node *buf = list->head;
    while (buf)
    {
        fprintf(fout, "%d %d ", ((container *)buf->info)->coefficient, ((container *)buf->info)->degree);
        buf = buf->next;
    }
    fprintf(fout, "1 ");
}

code input_choice(FILE *fin, char *key)
{
    code code_error = work;
    fgets(key, 4, fin);

    if (strcmp(key, "out") && strcmp(key, "sqr") && strcmp(key, "mul") && strcmp(key, "div"))
        code_error = bad_input;

    return code_error;
}

code enter_one_number(FILE *fin, int *number)
{
    code code_error = work;
    if (fscanf(fin, "%d", number) != 1)
        code_error = bad_input;

    if (*number < 1)
        code_error = bad_input;

    return code_error;
}

code enter_two_number(FILE *fin, int *first_number, int *second_number)
{
    code code_error = work;
    if (fscanf(fin, "%d %d", first_number, second_number) != 2)
        code_error = bad_input;

    if (*first_number < 1 || *second_number < 1)
        code_error = bad_input;

    return code_error;
}

