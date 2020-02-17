#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10
#define TRUE 0
#define FALSE 1

void transform(int *a, int **ap, int row, int column);
void check_input(int **ap, int row, int column, int *out);
int sum(int meaning);
void solve(int **ap, int *a, int *row, int column);
void output(int **ap, int row, int column);
void add_row(int **ap, int i, int row, int column);
void move_row(int **ap, int row, int column, int i);


int main()
{
    int out = TRUE;

    int a[2 * MAX_SIZE * MAX_SIZE];
    int *array[2 * MAX_SIZE];

    printf("Input rows and columns of array: ");

    int row, column;
    int rc = scanf("%d %d", &row, &column);

    if (rc == 2 && row >= 1 && row <= 10 && column >= 1 && column <= 10)
    {
        transform(a, array, row, column);
        check_input(array, row, column, &out);

        if (out == TRUE)
        {
            solve(array, a, &row, column);
            output(array, row, column);
        }
    }
    else
        out = FALSE;

    return out;
}

void transform(int *a, int **ap, int row, int column)
{
    for (int i = 0; i < 2 * MAX_SIZE; i++)
        ap[i] = a + i * column;
}

void check_input(int **ap, int row, int column, int *out)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            *out = (scanf("%d", ap[i] + j) != 1) ? FALSE : TRUE;
}

void solve(int **ap, int *a, int *row, int column)
{
    for (int i = 0; i < *row; i++)
    {
        int count = 0;

        for (int j = 0; j < column; j++)
        {
            if (sum(*(ap[i] + j)) % 2 != 0)
                count++;
        }

        if (count > 1)
        {
            add_row(ap, i, *row, column);
            (*row)++;
            i++;
        }
    }
}

int sum(int meaning)
{
    int s = 0;

    while (abs(meaning) > 0)
    {
        s += meaning % 10;
        meaning /= 10;
    }

    return s;
}

void add_row(int **ap, int i, int row, int column)
{
    move_row(ap, row, column, i);

    for (int j = 0; j < column; j++)
        ap[i][j] = -1;
}

void output(int **ap, int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            printf("%d ", ap[i][j]);

        puts("\n");
    }
}

void move_row(int **ap, int row, int column, int i)
{
    for (int j = row - 1; j >= i; j--)
        for (int k = 0; k < column; k++)
            ap[j + 1][k] = ap[j][k];
}
