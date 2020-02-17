#include <stdio.h>
#include <stdlib.h>

#define TRUE 0
#define FALSE 1
#define MAX_SIZE 10

int square(int number);
void scan(int *array, int size, int *p);
void dell(int *array, int *p_size, int *p);
void print(int *new_array, int *p_size);

int main()
{
    int out = TRUE;
    int *p = &out;

    int size;
    int *p_size = &size;
    
    printf("Input size of array: ");
    int rc = scanf("%d", &size);

    if (rc == 1 && size <= 10 && size >= 1)
    {
        int array[MAX_SIZE];
        scan(array, size, p);

        if (out == TRUE)
        {
            dell(array, p_size, p);

            if (out == TRUE)
                print(array, p_size);
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

int square(int number)
{
    int flag = 0;

    for (int i = 0; i <= number; i++)
    {
        if (i * i == number)
            flag = 1;
    }

    return flag;
}

void dell(int *array, int *p_size, int *p)
{
    for (int i = 0; i < *p_size; i++)
    {
        //buf = array[i];
        if (square(array[i]))
        {
            for (int j = i + 1; j < *p_size; j++)
                array[j - 1] = array[j];

            (*p_size)--;
            i--;
        }
    }
    if (*p_size == 0)
        *p = FALSE;
}

void print(int *new_array, int *p_size)
{
    for (int i = 0; i < *p_size; i++)
        printf("%d ", new_array[i]);
}
