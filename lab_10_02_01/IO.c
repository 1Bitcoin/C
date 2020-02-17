#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "string.h"
#include "IO.h"

int input_struct(struct_array_t *structs, char *buf_array, char *buf_name, FILE *fin)
{
    int code_error = OK;

    structs->array_structs[structs->size - 1].article = (char *) malloc((strlen(buf_array) + 1) * sizeof(char));
    strcpy(structs->array_structs[structs->size - 1].article, buf_array);

    if (fscanf(fin, "%s", buf_name) == 1)
    {
        structs->array_structs[structs->size - 1].name = (char *) malloc((strlen(buf_name) + 1) * sizeof(char));
        strcpy(structs->array_structs[structs->size - 1].name, buf_name);
    }
    else
        code_error = BAD_INPUT;

    if (fscanf(fin, "%d", &(structs->array_structs[structs->size - 1].count)) != 1 || structs->array_structs[structs->size - 1].count < 0)
        code_error = BAD_INPUT;

    return code_error;
}

void output_struct_in_file(struct_array_t *structs)
{
    FILE *fout = fopen("stockpile.txt", "w");

    for (int i = 0; i < structs->size; i++)
    {
        fprintf(fout, "%s\n", structs->array_structs[i].article);
        fprintf(fout, "%s\n", structs->array_structs[i].name);
        fprintf(fout, "%d\n", structs->array_structs[i].count);
    }
    fclose(fout);
}

int input_key_for_sort(FILE *fin, char *key)
{
    int code_error = OK;

    if (fscanf(fin, "%s", key) != 1)
        code_error = BAD_INPUT;

    return code_error;
}

int input_filed(struct_array_t *structs, char *article, char *name, FILE *fin)
{
    int code_error = OK;
    printf("Input article, name, count ");

    while ((fscanf(fin, "%s", article) == 1 && strcmp(article, "nothing")) && !code_error)
    {
        structs->size++;
        code_error = resize_struct(structs);
        if (!code_error)
            code_error = input_struct(structs, article, name, fin);
    }
    return code_error;
}
