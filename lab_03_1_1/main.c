#include <stdio.h>
#include <stdlib.h>

#define BAD_INPUT 1
#define TRUE_INPUT 0

int process(FILE *fsrc, int *max1, int *max2);
void swap_for_p(int *max1, int *max2);
void swap_for_var(int *max1, int *max2, int z);

int main(void)
{
    int out = TRUE_INPUT;
    int max1, max2;

    FILE *fsrc;
    fsrc = stdin;

    if (process(fsrc, &max1, &max2) == 1)
    {
        printf("Not enough numbers\n");
        out = BAD_INPUT;
    }
    else
        printf("%d %d", max1, max2);

    return out;
}

int process(FILE *fsrc, int *max1, int *max2)
{
    int flag = TRUE_INPUT;

    if (fscanf(fsrc, "%d", max1) != 1)
        flag = BAD_INPUT;

    if (fscanf(fsrc, "%d", max2) != 1)
        flag = BAD_INPUT;

    if (max2 > max1)
        swap_for_p(max1, max2);

    int temp;

    while (fscanf(fsrc, "%d", &temp) == 1 && feof(fsrc) == 0)
    {
        if (temp > *max1)
            swap_for_var(max1, max2, temp);
        else
        {
            if (temp > *max2)
                *max2 = temp;
        }
    }

    return flag;
}

void swap_for_p(int *max1, int *max2)
{
    int buff = *max1;
    *max1 = *max2;
    *max2 = buff;
}

void swap_for_var(int *max1, int *max2, int temp)
{
    *max2 = *max1;
    *max1 = temp;
}
