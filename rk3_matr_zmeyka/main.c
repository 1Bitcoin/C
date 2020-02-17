#include <stdio.h>
#include <stdlib.h>

#define N 5
#define M 5

int *ind(int ii, int n, int **matr)
{
    int *iP = matr[ii / n];
    int j = ii % n;
    j = (ii/n) & 1 ? n - j - 1 : j;
    return iP + j;
}


int main()
{
    int **matr = (int **) malloc(sizeof(int *) * M);
    int i, j, flag = 1;
    for (i = 0; i < M; i++)
        matr[i] = malloc(sizeof(int) * N);

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
        {
            matr[i][j] = rand() % 1000000;
            printf("%6d ", matr[i][j]);
        }
        putchar('\n');
    }
    while(flag)
    {
        flag = 0;
        for(i = 0; i < M * N - 1; i++)
        {
            int *i1 = ind(i, N, matr);
            int *i2 = ind(i + 1, N, matr);
            if(*i1 > *i2) {
                flag = 1;
                int k = *i2;
                *i2 = *i1;
                *i1 = k;
            }
        }
    }
    printf("---------------------\n");
    for(i = 0; i < M; i++)
    {
        for(j = 0; j < N; j++)
            printf("%6d ", matr[i][j]);

        putchar('\n');
    }
    for(i = 0; i < M; i++)
        free(matr[i]);

    free(matr);
    return 0;
}
