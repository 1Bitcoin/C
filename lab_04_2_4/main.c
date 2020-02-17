#include <stdio.h>
#include <math.h>

#define TRUE 0
#define FALSE 1

void scan(int *array, int size, int *p);
void sorting(int *array, int size);
void print(int *array, int size);
void swap(int *a, int *b);

int main()
{
    int out = TRUE;
    int *p = &out;

    int size;
    printf("Input size of array: ");
    int rc = scanf("%d", &size);

    if (rc == 1 && size <= 10 && size >= 1)
    {
        int array[size];
        scan(array, size, p);

        if (out == TRUE)
        {
            sorting(array, size);
            print(array, size);
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
        int rc = scanf("%d ", (array + i));

        if (rc != 1)
            *p = FALSE;
    }
}

void sorting(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
            if (array[j] < array[min])
                min = j;

        swap((array + i), (array + min));
    }
}

void print(int *array, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
