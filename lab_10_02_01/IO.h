#ifndef __IO_TEST_H__
#define __IO_TEST_H__
#include "lib.h"

int input_struct(struct_array_t *structs, char *buf_array, char *buf_name, FILE *fin);
void output_struct_in_file(struct_array_t *structs);
int input_key_for_sort(FILE *fin, char *key);
int input_filed(struct_array_t *structs, char *article, char *name, FILE *fin);

#endif
