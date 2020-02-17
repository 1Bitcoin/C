#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_FILENAME 2
#define OK 0
#define N 12
#define END_WITH_SUCCESS 0
#define EMPTY_FILE 1

int get_number_by_pos(FILE *f, int position);
void put_number_by_pos(FILE *f, int position, int number);
void count_numbers(char *file_name, int *count);
void sort(char *file_name, int count);
void create_file(char *file_name);
void print_file(char *file_name, int *count);
void usage(void);
void check_valid(int count, int *out);

int main(int argc, char **argv)
{
    int count = 0;
    int out = END_WITH_SUCCESS;

    if (argc != 3)
    {
        usage();
        out = ERROR_FILENAME;
    }
    else
    {
        if (strcmp(argv[1], "c") == OK)
            create_file(argv[2]);

        if (strcmp(argv[1], "p") == OK)
        {
            print_file(argv[2], &count);
            check_valid(count, &out);
        }

        if (strcmp(argv[1], "s") == OK)
        {
            count_numbers(argv[2], &count);
            check_valid(count, &out);
            sort(argv[2], count);
        }
    }

    return out;
}

int get_number_by_pos(FILE *f, int position)
{
    int number;
    fseek(f, position * sizeof(int) - sizeof(int), SEEK_SET);
    fread(&number, sizeof(int), 1, f);

    return number;
}

void put_number_by_pos(FILE *f, int position, int number)
{
    fseek(f, position * sizeof(int) - sizeof(int), SEEK_SET);
    fwrite(&number, sizeof(int), 1, f);
}

void count_numbers(char *file_name, int *count)
{
    FILE *f = fopen(file_name, "rb");
    int temp_num;

    while (fread(&temp_num, sizeof(int), 1, f) == 1)
        *count += 1;

    fclose(f);
}

void sort(char *file_name, int count)
{
    FILE *f = fopen(file_name, "r + b");

    int ind_min;
    int a, b;

    for (int i = 1; i <= count; i++)
    {
        ind_min = i;
        for (int j = i + 1; j <= count; j++)
        {
            a = get_number_by_pos(f, j);
            b = get_number_by_pos(f, ind_min);
            if (a < b)
                ind_min = j;
        }

        a = get_number_by_pos(f, i);
        b = get_number_by_pos(f, ind_min);
        put_number_by_pos(f, i, b);
        put_number_by_pos(f, ind_min, a);
    }

    fclose(f);
}

void create_file(char *file_name)
{
    FILE *f = fopen(file_name, "wb");
    int temp_num;

    for (int i = 0; i < N; i++)
    {
        temp_num = rand() % (10);
        fwrite(&temp_num, sizeof(int), 1, f);
    }

    fclose(f);
}

void print_file(char *file_name, int *count)
{
    FILE *f = fopen(file_name, "rb");
    int temp_num;

    while (fread(&temp_num, sizeof(int), 1, f) == 1)
    {
        printf("%d ", temp_num);
        *count += 1;
    }

    fclose(f);
}

void usage(void)
{
    printf("app.exe <action>\n");
    printf("<action>\n");
    printf("\t c - create file \n");
    printf("\t p - print file \n");
    printf("\t s - put numbers in order\n");
}

void check_valid(int count, int *out)
{
    if (!count)
        *out = EMPTY_FILE;
}