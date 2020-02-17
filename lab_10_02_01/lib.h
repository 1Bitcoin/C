#ifndef __LIB_H__
#define __LIB_H__

#define NOT_MEMORY 1
#define BAD_INPUT 2
#define FATAL_ERROR 3
#define NO_ELEMENTS 4
#define OK 0;

typedef struct
{
    char *article;
    char *name;
    int count;
}product_t;

typedef struct
{
    product_t *array_structs;
    int size;
}struct_array_t;

int resize_struct(struct_array_t *structs);
void delete_structs(struct_array_t *structs);
void safe_add_name_to_article(struct_array_t *structs);
int check_article(struct_array_t *structs);
int delete_struct(struct_array_t *structs, int index);
int cmp_article(const void *product_first, const void *product_second);
int cmp_name(const void *product_first, const void *product_second);
int cmp_count(const void *product_first, const void *product_second);
void sort_structs_by_key(struct_array_t *structs, int (*cmp)(const void *, const void *));
int check_key(struct_array_t *structs, char *key);
void swap(product_t *product_first, product_t *product_second);
void make_upper_string(char *string);
int check_article_to_valid(struct_array_t *structs, int index);
int check_upper_word(struct_array_t *structs, int index);

#endif