#ifndef __IO_H__
#define __IO_H__

#include "list.h"

void print_linked_list(FILE *fout, list *head);
code input_choice(FILE *fin, char *key);
code enter_one_number(FILE *fin, int *number);
code enter_two_number(FILE *fin, int *first_number, int *second_number);

#endif
