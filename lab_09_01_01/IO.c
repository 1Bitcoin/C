#include <stdio.h>
#include <stdlib.h>
#include "IO.h"
#include "lib.h"

void output_matr(matrix_t *my_matrix, FILE *fout)
{
    fprintf(fout, "\n");
    for (int i = 0; i < my_matrix->row; i++)
    {
        for (int j = 0; j < my_matrix->column; j++)
            fprintf(fout, "%d ", my_matrix->matrix[i][j]);
        fprintf(fout, "\n");
    }
}

int input_matr(matrix_t *my_matrix, FILE *fin)
{
    int code_error = TRUE;
    for (int i = 0; i < my_matrix->row; i++)
        for (int j = 0; j < my_matrix->column; j++)
            if (fscanf(fin, "%d", &my_matrix->matrix[i][j]) != 1)
                code_error = FALSE;
    return code_error;
}
