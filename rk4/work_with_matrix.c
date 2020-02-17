#include <stdio.h>
#include <stdlib.h>
#include "work_with_struct.h"
#include "work_with_matrix.h"
#include "save_new_bmp.h"
#include "read_info_from_bmp.h"

matr_t **create_matr(matr_t **matrix, int height, int widht)
{
    matr_t **buf_matrix = (matr_t **) malloc((height + 2) * sizeof(matr_t *));

    matrix = buf_matrix;
    buf_matrix = NULL;

    for (int i = 0; i < height + 2; i++)
    {
        matr_t *buf_array = (matr_t *) malloc((widht + 2) * sizeof(matr_t));
        matrix[i] = buf_array;
        buf_array = NULL;
    }

    return matrix;
}

void make_matrix_with_zeros_around_edges(struct_bmp *bmp)
{
    for (int row = 0; row < bmp->height + 2; row++)
    {
        bmp->red_matr[row][0] = 0;
        bmp->red_matr[row][bmp->widht + 1] = 0;

        bmp->green_matr[row][0] = 0;
        bmp->green_matr[row][bmp->widht + 1] = 0;

        bmp->blue_matr[row][0] = 0;
        bmp->blue_matr[row][bmp->widht + 1] = 0;

        if (!row)
            for (int column = 0; column < bmp->widht + 2; column++)
            {
                bmp->red_matr[row][column] = 0;
                bmp->green_matr[row][column] = 0;
                bmp->blue_matr[row][column] = 0;
            }

        if (row == bmp->height + 1)
            for (int column = 0; column < bmp->widht + 2; column++)
            {
                bmp->red_matr[row][column] = 0;
                bmp->green_matr[row][column] = 0;
                bmp->blue_matr[row][column] = 0;
            }
    }
}

void output_matr(const struct_bmp *bmp)
{
    for (int i = 0; i < bmp->height + 2; i++)
    {
        for (int j = 0; j < bmp->widht + 2; j++)
            printf("%lf ", bmp->red_matr[i][j]);

        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < bmp->height + 2; i++)
    {
        for (int j = 0; j < bmp->widht + 2; j++)
            printf("%lf ", bmp->green_matr[i][j]);

        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < bmp->height + 2; i++)
    {
        for (int j = 0; j < bmp->widht + 2; j++)
            printf("%lf ", bmp->blue_matr[i][j]);

        printf("\n");
    }
    printf("\n");
}

