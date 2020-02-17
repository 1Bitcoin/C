#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ARRAY_SIZE 100

//Variant 2

void print(float *array, int N);
void input(float *array, int N);
float findMiddle(float *array, int N);
void reSorting(float *array, int *p, float *m);
void printGone(float *array, int N);

int main()
{
    float a[MAX_ARRAY_SIZE];

    int N;
    int *p = &N;

    do
    {
        printf("Enter array length (length < 51)\n");
        scanf("%d", &N);
    }
    while ((N <= 0) || (N > MAX_ARRAY_SIZE) || N > 50) ;

    input(a, N);

    print(a, N);

    float middle = findMiddle(a, N);

    reSorting(a, p, &middle);


    printf("\n\nmiddle = %f", middle);

    printGone(a, N);

    return 0;
}

void print(float *array, int N)
{
    printf("Array:\n");

    for (int i = 0;i < N;i++)
        printf("%f ", array[i]);
}

void input(float *array, int N)
{
    printf("Input:\n");

    for (int i = 0;i < N;i++)
        scanf("%f", &array[i]);
}

float findMiddle(float *array, int N)
{
    float numbers = 0;
    float count = 0;
    float middle;

    for (int i = 0;i < N;i++)
    {
        numbers = numbers + array[i];
        count++;
    }

    middle = numbers / count;

    return middle;
}

void reSorting(float *array, int *p, float *m)
{
    int i = 0;

    while (i < *p)
    {
        if (i % 2 == 0)
        {
            for (int j = *p;j > i;j--)
                array[j] = array[j-1];
            (*p) = (*p) + 1;
            array[i+1] = (*m);
        }
        i++;
    }
}

void printGone(float *array, int N)
{
    printf("\n\nArray gone\n\n");

    for (int i = 0;i < N;i++)
        printf("%f ", array[i]);
}
