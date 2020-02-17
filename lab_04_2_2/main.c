#include <stdio.h>
#include <stdlib.h>

#define TRUE 0
#define FALSE 1
#define MAX_SIZE 10

void scan(int *array, int size, int *p);
void check(int *array, int *new_array, int size, int *p, int *cursor_new_size);
void print(int *new_array, int new_size);

int main()
{
    int out = TRUE;
    int *p = &out;

    int new_size = 0;
    int *cursor_new_size = &new_size;

    int size;
    printf("Input size of array: ");
    int rc = scanf("%d", &size);

    if (rc == 1 && size <= 10 && size >= 1)
    {
        int array[MAX_SIZE];
        scan(array, size, p);

        if (out == TRUE)
        {
            int new_array[MAX_SIZE];
            check(array, new_array, size, p, cursor_new_size);

            if (out == TRUE)
                print(new_array, new_size);
        }
    }
    else
        out = FALSE;

    return out;
}

void scan(int *array, int size, int *p)
{
    for (int i = 0; i < size; i++)
    {
        int rc = scanf("%d", (array + i));

        if (rc != 1)
            *p = FALSE;
    }
}

void check(int *array, int *new_array, int size, int *p, int *cursor_new_size)
{
    int flag = 0;

    for (int i = 0; i < size; i++)
    {
        int new_copy = abs(array[i]);
        int end = abs(new_copy) % 10;
        int first;

        while (new_copy > 0)
        {
            first = new_copy % 10;
            new_copy /= 10;
        }

        if (first == end)
        {
            new_array[flag] = array[i];
            flag++;
        }
    }
    if (flag == 0)
        *p = FALSE;
    else
        (*cursor_new_size) = flag;
}

void print(int *new_array, int new_size)
{
    for (int i = 0; i < new_size; i++)
        printf("%d ", new_array[i]);
}
