#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#include "IO.h"

int proc(FILE *fin)
{
    char *buf_ar = (char *) malloc(256 * sizeof(char));
    char *buf_na = (char *) malloc(256 * sizeof(char));
    char *key = (char *) malloc(8 * sizeof(char));

    struct_array_t structs = { NULL, 0 };

    int code_error = input_filed(&structs, buf_ar, buf_na, fin);

    if (!code_error)
        code_error = input_key_for_sort(fin, key);

    if (!code_error)
        safe_add_name_to_article(&structs);

    if (!code_error)
        code_error = check_article(&structs);

    if (!code_error)
        code_error = check_key(&structs, key);

    if (!code_error)
        output_struct_in_file(&structs);

    delete_structs(&structs);

    free(buf_ar);
    free(buf_na);
    free(key);

    return code_error;
}