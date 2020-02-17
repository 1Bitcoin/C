#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lib.h"

int resize_struct(struct_array_t *structs)
{
    int code_error = OK;
    product_t *buf = (product_t *) realloc(structs->array_structs, structs->size * sizeof(product_t));
    if (buf)
    {
        structs->array_structs = buf;
        buf = NULL;
    }
    else
        code_error = NOT_MEMORY;

    return code_error;
}

void delete_structs(struct_array_t *structs)
{
    for (int i = 0; i < structs->size; i++)
    {
        free(structs->array_structs[i].article);
        free(structs->array_structs[i].name);
    }
    if (structs->size)
        free(structs->array_structs);
}

void safe_add_name_to_article(struct_array_t *structs)
{
    for (int i = 0; i < structs->size; i++)
    {
        structs->array_structs[i].article = (char *) realloc(structs->array_structs[i].article, (strlen(structs->array_structs[i].article) + strlen(structs->array_structs[i].name) + 1) * sizeof(char));
        if (!check_upper_word(structs, i))
        {
            char *temp_name = (char *) malloc((strlen(structs->array_structs[i].name) + 1) * sizeof(char));
            strcpy(temp_name, structs->array_structs[i].name);
            make_upper_string(temp_name);
            strcat(structs->array_structs[i].article, temp_name);
            free(temp_name);
        }
        else
            strcat(structs->array_structs[i].article, structs->array_structs[i].name);
    }
}

int check_upper_word(struct_array_t *structs, int index)
{
    int answer = 1;

    for (int i = 0; i < strlen(structs->array_structs[index].name) && answer; i++)
        if (!('A' <= structs->array_structs[index].name[i] && structs->array_structs[index].name[i] <= 'Z'))
            answer = 0;

    return answer;
}

int check_article(struct_array_t *structs)
{
    int code_error = OK;
    for (int i = 0; i < structs->size && !code_error; i++)
    {
        code_error = check_article_to_valid(structs, i);
        if (!strcmp(structs->array_structs[i].article, "LIPSTICK") && structs->array_structs[i].count == 0)
        {
            code_error = delete_struct(structs, i);
            i--;
        }
    }
    return code_error;
}

int check_article_to_valid(struct_array_t *structs, int index)
{
    int code_error = OK;

    for (int i = 0; i < strlen(structs->array_structs[index].article) && !code_error; i++)
    {
        if (!('A' <= structs->array_structs[index].article[i] && structs->array_structs[index].article[i] <= 'Z'))
            code_error = BAD_INPUT;
    }

    return code_error;
}

int delete_struct(struct_array_t *structs, int index)
{
    for (int i = index + 1; i < structs->size; i++)
        swap(structs->array_structs + (i - 1), structs->array_structs + i);

    structs->size--;
    free(structs->array_structs[structs->size].article);
    free(structs->array_structs[structs->size].name);

    int code_error = resize_struct(structs);

    if (!structs->size)
        code_error = NO_ELEMENTS;

    return code_error;
}

void sort_structs_by_key(struct_array_t *structs, int (*cmp)(const void *, const void *))
{
    qsort(structs->array_structs, structs->size, sizeof (product_t), cmp);
}

int check_key(struct_array_t *structs, char *key)
{
    int code_error = OK;

    if (!strcmp(key, "ARTICLE"))
        sort_structs_by_key(structs, cmp_article);
    else if (!strcmp(key, "NAME"))
        sort_structs_by_key(structs, cmp_name);
    else if (!strcmp(key, "COUNT"))
        sort_structs_by_key(structs, cmp_count);
    else
        code_error = BAD_INPUT;

    return code_error;
}

int cmp_article(const void *product_first, const void *product_second)
{
    const product_t *arg1 = product_first;
    const product_t *arg2 = product_second;

    return strcmp(arg1->article, arg2->article);
}

int cmp_name(const void *product_first, const void *product_second)
{
    const product_t *arg1 = product_first;
    const product_t *arg2 = product_second;

    return strcmp(arg1->name, arg2->name);
}

int cmp_count(const void *product_first, const void *product_second)
{
    int choise = 0;

    const product_t *arg1 = product_first;
    const product_t *arg2 = product_second;

    if (arg1->count > arg2->count)
        choise = 1;

    return choise;
}

void swap(product_t *product_first, product_t *product_second)
{
    product_t temp = *product_first;
    *product_first = *product_second;
    *product_second = temp;
}

void make_upper_string(char *string)
{
    for (int i = 0; i < strlen(string); i++)
        string[i] = toupper(string[i]);
}
