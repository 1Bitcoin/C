#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_ARGV 53
#define ERROR_SUBSTR 5333
#define EMPTY 533
#define END_WITH_SUCCESS 0

typedef struct
{
    char product_name[31];
    char factory_name[16];
    int price;
    int volume;
} my_struct;

void count_structs(char *file_name, int *count);
void output_structs(char *file_name, const int count);
void sort(char *file_in, const int count);
my_struct get_struct_by_pos(FILE *f, const int position);
void put_struct_by_pos(FILE *f, my_struct *value, const int position);
void copy_to_file(char *file_in, char *file_out, const int count);
void search_and_print_substr(char *file_in, char *substr, const int count, int *out);
void add_new_struct(char *file_in_out, int count);
void insert_new_struct(FILE *f, const int index, my_struct *buf, int *count);
void search_pos_for_new_struct(FILE *f, my_struct *buf, const int count, int *index);
void scan_new_struct(my_struct *buf);

int main(int argc, char **argv)
{
    int out = END_WITH_SUCCESS;
    int count = 0;

    if (argc != 3 && argc != 4)
        out = ERROR_ARGV;
    else
    {
        if (argc == 3 && !strcmp(argv[1], "ab"))
        {
            count_structs(argv[2], &count);
            if (!count)
                out = EMPTY;
            else
            {
                add_new_struct(argv[2], count);
                output_structs(argv[2], count);
            }
        }
        else
        {
            if (argc == 4 && !strcmp(argv[1], "sb"))
            {
                count_structs(argv[2], &count);
                if (!count)
                    out = EMPTY;
                else
                {
                    sort(argv[2], count);
                    copy_to_file(argv[2], argv[3], count);
                    output_structs(argv[2], count);
                }
            }
            else
            {
                if (argc == 4 && !strcmp(argv[1], "fb"))
                {
                    count_structs(argv[2], &count);
                    if (!count)
                        out = EMPTY;
                    else
                        search_and_print_substr(argv[2], argv[3], count, &out);
                }
                else
                    out = ERROR_ARGV;
            }
        }
    }
    return out;
}

void count_structs(char *file_name, int *count)
{
    FILE *f = fopen(file_name, "rb");
    my_struct buf;
    memset(&buf, 0, sizeof(my_struct));

    while (fread(&buf, sizeof(my_struct), 1, f) == 1)
        *count += 1;

    fclose(f);
}

void output_structs(char *file_name, const int count)
{
    FILE *f = fopen(file_name, "rb");

    for (int position = 0; position < count; position++)
    {
        my_struct product;
        memset(&product, 0, sizeof(my_struct));

        fread(&product, sizeof(my_struct), 1, f);
        printf("%s\n%s\n%d\n%d\n", product.product_name, product.factory_name, product.price, product.volume);
    }

    fclose(f);
}

void sort(char *file_in, const int count)
{
    FILE *f_in = fopen(file_in, "r + b");

    my_struct a;
    my_struct b;

    memset(&a, 0, sizeof(my_struct));
    memset(&b, 0, sizeof(my_struct));

    int ind_min;

    for (int i = 0; i < count; i++)
    {
        ind_min = i;
        for (int j = i; j < count; j++)
        {
            a = get_struct_by_pos(f_in, j);
            b = get_struct_by_pos(f_in, ind_min);
            if (a.price > b.price || (a.price == b.price && a.volume > b.volume))
                ind_min = j;
        }

        a = get_struct_by_pos(f_in, i);
        b = get_struct_by_pos(f_in, ind_min);
        put_struct_by_pos(f_in, &b, i);
        put_struct_by_pos(f_in, &a, ind_min);
    }

    fclose(f_in);
}

my_struct get_struct_by_pos(FILE *f, const int position)
{
    my_struct value;
    memset(&value, 0, sizeof(my_struct));

    fseek(f, position * sizeof(my_struct), SEEK_SET);
    fread(&value, sizeof(my_struct), 1, f);

    return value;
}

void put_struct_by_pos(FILE *f, my_struct *value, const int position)
{
    fseek(f, position * sizeof(my_struct), SEEK_SET);
    fwrite(value, sizeof(my_struct), 1, f);
}

void copy_to_file(char *file_in, char *file_out, const int count)
{
    FILE *f_in = fopen(file_in, "rb");
    FILE *f_out = fopen(file_out, "wb");

    my_struct buf;
    memset(&buf, 0, sizeof(my_struct));

    for (int position = 0; position < count; position++)
    {
        fread(&buf, sizeof(my_struct), 1, f_in);
        fwrite(&buf, sizeof(my_struct), 1, f_out);
    }

    fclose(f_in);
    fclose(f_out);
}

void search_and_print_substr(char *file_in, char *substr, const int count, int *out)
{
    FILE *f_in = fopen(file_in, "rb");

    my_struct buf;
    memset(&buf, 0, sizeof(my_struct));

    int substr_len = strlen(substr);
    int check = 0;

    for (int i = 0; i < count; i++)
    {
        fread(&buf, sizeof(my_struct), 1, f_in);

        int letters = 0;
        int n = substr_len - 1;
        int str_len = strlen(buf.product_name) - 1;

        for (int j = str_len; n >= 0; j--, n--)
            if (buf.product_name[j] == substr[n])
                letters++;

        if (substr_len == letters)
        {
            printf("%s\n%s\n%d\n%d\n", buf.product_name, buf.factory_name, buf.price, buf.volume);
            check++;
        }
    }

    if (!check)
        *out = ERROR_SUBSTR;

    fclose(f_in);
}

void add_new_struct(char *file_in_out, int count)
{
    FILE *f = fopen(file_in_out, "r + b");

    my_struct buf;
    memset(&buf, 0, sizeof(my_struct));

    int index = count;
    scan_new_struct(&buf);
    search_pos_for_new_struct(f, &buf, count, &index);
    insert_new_struct(f, index, &buf, &count);

    fclose(f);
}

void insert_new_struct(FILE *f, const int index, my_struct *buf, int *count)
{
    for (int j = *count - 1; j >= index; j--)
    {
        my_struct a;
        memset(&a, 0, sizeof(my_struct));

        a = get_struct_by_pos(f, j);
        put_struct_by_pos(f, &a, j + 1);
    }

    put_struct_by_pos(f, buf, index);
    *count += 1;
}

void scan_new_struct(my_struct *buf)
{
    scanf("%s", buf->product_name);
    scanf("%s", buf->factory_name);
    scanf("%d", &buf->price);
    scanf("%d", &buf->volume);
}

void search_pos_for_new_struct(FILE *f, my_struct *buf, const int count, int *index)
{
    my_struct product;
    memset(&product, 0, sizeof(my_struct));

    int flag = 1;

    for (int position = 0; position < count && flag; position++)
    {
        fread(&product, sizeof(my_struct), 1, f);

        if (buf->price > product.price || (buf->price == product.price && buf->volume > product.volume))
        {
            *index = position;
            flag = 0;
        }
    }
}
