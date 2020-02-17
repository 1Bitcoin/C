#include <stdio.h>
#include <stdlib.h>

#define TRUE 0
#define FALSE 1
#define MAX_SIZE 10

void transform(int *a, int **ap, int row, int column);
void output(int **a, int row, int column);
void scan(int **ap, int *p, int row, int column);
int check_max(int **a, int column, int i);
void sorting(int **a, int row, int column);
void swap(int **a, int **b);

int main()
{
    int out = TRUE;

    printf("Input row and column: ");
    int row, column;
    int rc = scanf("%d %d", &row, &column);

    if (rc == 2 && row >= 1 && row <= 10 && column >= 1 && column <= 10)
    {
        int a[MAX_SIZE * MAX_SIZE];
        int *array[row];
        transform(a, array, row, column);
        scan(array, &out, row, column);

        if (out == TRUE)
        {
            sorting(array, row, column);
            output(array, row, column);
        }
    }
    else
        out = FALSE;

    return out;
}

void scan(int **ap, int *p, int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            *p = (scanf("%d", ap[i] + j) != 1) ? FALSE : TRUE;
    }
}

void transform(int *a, int **ap, int row, int column)
{
    for (int i = 0; i < row; i++)
        *(ap + i) = a + i * column;
}

void output(int **a, int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column ; j++)
            printf("%d ", a[i][j]);

        putchar('\n');
    }
}

int check_max(int **a, int column, int i)
{
    int flag = 1;

    for (int j = 0; j < column ; j++)
        flag *= a[i][j];

    return flag;
}

void sorting(int **a, int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (check_max(a, column, i) < check_max(a, column, j))
                swap((a + i), (a + j));
        }
    }
}

void swap(int **a, int **b)
{
    int *buf = *b;
    *b = *a;
    *a = buf;
}
