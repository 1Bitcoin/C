#include <stdio.h>
#include <stdlib.h>

#define TRUE 0
#define FALSE 1
#define MAX_SIZE 10

void transform(int *a, int **ap, int n, int m);
void scan(int **ap, int *p, int row, int column);
void input_array(int *ap, int i, int flag, int *p_size);
void check(int **a, int *ap, int n, int m, int *p_size);
void print_new_array(int *ans, int new_size);
int choice(int flag, int n);

int main()
{
    int out = TRUE;
    int new_size = 0;

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
            int ans[MAX_SIZE];
            check(array, ans, row, column, &new_size);
            print_new_array(ans, new_size);
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

void transform(int *a, int **ap, int n, int m)
{
    for (int i = 0; i < n; i++)
        ap[i] = a + i * m;
}

void check(int **a, int *ap, int n, int m, int *p_size)
{
    for (int i = 0; i < m; i++)
    {
        int flag = 0;

        for (int j = 0; j < n - 1 ; j++)
        {
            if (a[j][i] * a[j + 1][i] < 0)
                flag++;
        }

        input_array(ap, i, choice(flag, n), p_size);
    }
}

int choice(int flag, int n)
{
    return ((flag == n - 1) && n > 1) ? 1 : 0;
}

void input_array(int *ap, int i, int flag, int *p_size)
{
    *(ap + i) = flag;
    (*p_size)++;
}

void print_new_array(int *ans, int new_size)
{
    for (int i = 0; i < new_size; i++)
        printf("%d ", *(ans + i));
}
