#include <stdio.h>
#include <stdlib.h>

#define TRUE 0
#define FALSE 1

void scan(int *array, int size, int *p);
double average(int *array, int size);

int main()
{
    int out = TRUE;
    int *p = &out;

    int size;
    printf("Input size of array:");
    int rc = scanf("%d", &size);

    if (rc == 1 && size <= 10 && size >= 1)
    {
        int array[size];
        scan(array, size, p);

        if (out == TRUE)
            printf("Average is %f", average(array, size));
    }
    else
        out = FALSE;

    return out;
}

void scan(int *array, int size, int *p)
{
    int rc;
    int negative = 0;

    for (int i = 0; i < size; i++)
    {
        rc = scanf("%d", (array + i));
        if (rc == 1)
        {
            if (array[i] < 0)
                negative += 1;
        }
        else
            *p = FALSE;
    }
    if (negative == 0)
        *p = FALSE;
}

double average(int *array, int size)
{
    double count = 0;
    double numbers = 0;

    for (int i = 0; i < size; i++)
    {
        if (array[i] < 0)
        {
            count++;
            numbers += array[i];
        }
    }
    return numbers / count;;
}
