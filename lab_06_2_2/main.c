#include <stdio.h>
#include <string.h>

#define OK 0
#define INPUT_ERR 1
#define SIZE_ERR 1

#define TRUE 1
#define FALSE 0
#define OK_COUNT 1
#define NO_WORDS 2
#define ERROR_WORD_SIZE 1
#define EMPTY_STRING 1

#define MAX_LEN_WORD 16
#define SEP_SIZE 8
#define N 256

void transform(char *a, char **ap);
int my_strcmp(char *string1, char *string2);
int check_duplicate(char **matrix, int len, char *string, int index);
int symb_check_separators(char symbol);
int my_split(char *string, char **matrix_split, int *count_lexem, int *len_str);
int readstring(char *array);
void lexem_repeat_search(char **matrix1, int len_matrix1, char **matrix2, int len_matrix2);
void check_error(char *str1, char *str2, int *out);

int main(void)
{
    int out = OK;

    char str1[N] = { 0 };
    char a_str1[N] = { 0 };
    char *lexem_matrix1[N];

    transform(a_str1, lexem_matrix1);

    char str2[N] = { 0 };
    char a_str2[N] = { 0 };
    char *lexem_matrix2[N];

    transform(a_str2, lexem_matrix2);

    int len_lex1 = 0;
    int len_lex2 = 0;

    int len_str1 = 0;
    int len_str2 = 0;

    check_error(str1, str2, &out);

    if (!out)
    {
        if (my_split(str1, lexem_matrix1, &len_lex1, &len_str1) || my_split(str2, lexem_matrix2, &len_lex2, &len_str2))
        {
            puts("One of the words is more than 16 symbols.");
            out = ERROR_WORD_SIZE;
        }

        if (!len_str1 || !len_str2)
        {
            puts("One of the string have no words");
            out = NO_WORDS;
        }

        if (!out)
        {
            puts("Result: ");
            lexem_repeat_search(lexem_matrix1, len_lex1, lexem_matrix2, len_lex2);
        }
    }

    return out;
}

void transform(char *a, char **ap)
{
    for (int i = 0; i < 16; i++)
        ap[i] = a + i * 16;
}

int my_strcmp(char *string1, char *string2)
{
    int out = TRUE;
    int i = 0;

    while (string1[i] && out)
    {
        if (string1[i] != string2[i])
            out = FALSE;
        ++i;
    }

    if (string2[i] != '\0')
        out = FALSE;

    return out;
}

int check_duplicate(char **matrix, int len, char *string, int index)
{
    int out = TRUE;
    int flag = TRUE;
    for (int i = 0; i < len && flag; i++)
        if (my_strcmp(string, matrix[i]))
        {
            flag = FALSE;
            if (index != i)
                out = FALSE;
        }

    return out;
}

void lexem_repeat_search(char **matrix1, int len_matrix1, char **matrix2, int len_matrix2)
{
    for (int i = 0; i < len_matrix1; i++)
    {
        if (check_duplicate(matrix1, len_matrix1, matrix1[i], i))
        {
            int j = 0;
            int line_entry = FALSE;

            while (!line_entry && j < len_matrix2)
            {
                line_entry = my_strcmp(matrix1[i], matrix2[j]);
                ++j;
            }

            if (line_entry)
                printf("%s yes\n", matrix1[i]);
            else
                printf("%s no\n", matrix1[i]);
        }
    }
}

int symb_check_separators(char symbol)
{
    int out = FALSE;
    char separators[] = { ' ', ',', ';', ':', '.', '-', '!', '?' };

    for (int i = 0; i < SEP_SIZE && out == FALSE; i++)
        if (symbol == separators[i])
            out = TRUE;

    return out;
}

int my_split(char *string, char **matrix_split, int *count_lexem, int *len_str)
{
    int i = 0, k = 0;
    int out = OK;

    while (string[i] && out == OK)
    {
        if (!symb_check_separators(string[i]))
        {
            if (k >= MAX_LEN_WORD)
                out = ERROR_WORD_SIZE;

            (*len_str)++;
            matrix_split[*count_lexem][k] = string[i];
            k++;
        }
        else
        {
            if (!symb_check_separators(string[i + 1]))
            {
                if (k != 0)
                {
                    matrix_split[*count_lexem][k] = '\0';
                    if (string[i + 1])
                        (*count_lexem)++;
                }
                k = 0;
            }
        }
        i++;
    }
    (*count_lexem)++;

    return out;
}

int readstring(char *array)
{
    int out = OK;
    int i = 0;

    puts("Enter string: ");

    do
    {
        if (scanf("%c", array + i) != OK_COUNT)
            out = INPUT_ERR;
        ++i;
    } while (array[i - 1] != '\n' && i <= N && out == OK);

    if (array[i - 1] != '\n')
        out = SIZE_ERR;

    if (i == 1)
        out = EMPTY_STRING;

    array[i - 1] = '\0';

    return out;
}

void check_error(char *str1, char *str2, int *out)
{
    if (readstring(str1))
    {
        puts("Incorrect entered string1.");
        *out = NO_WORDS;
    }

    if (readstring(str2))
    {
        puts("Incorrect entered string2.");
        *out = NO_WORDS;
    }
}
