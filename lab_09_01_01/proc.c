#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib.h"
#include "IO.h"

int proc(FILE *fin, FILE *fout)
{
    matrix_t matrix_a;
    matrix_t matrix_b;
    matrix_t matrix_pow_a;
    matrix_t matrix_pow_b;
    matrix_t matrix_result;

    int position[2] = { 0, 0 };
    int p_factor, j_factor;

    int code_error = TRUE;

    printf("Input row and column matrix A:");
    if (fscanf(fin, "%d", &matrix_a.row) == 1 && matrix_a.row > 0 && fscanf(fin, "%d", &matrix_a.column) == 1 && matrix_a.column > 0)
    {
        code_error = create_matr(&matrix_a);
        if (!code_error)
            code_error = input_matr(&matrix_a, fin);

        if (!code_error)
        {
            printf("Input row and column matrix B:");
            if (fscanf(fin, "%d", &matrix_b.row) == 1 && matrix_b.row > 0 && fscanf(fin, "%d", &matrix_b.column) == 1 && matrix_b.column > 0)
            {
                code_error = create_matr(&matrix_b);
                if (!code_error)
                    code_error = input_matr(&matrix_b, fin);

                if (!code_error)
                {
                    printf("Input factor p and factor j");
                    if (fscanf(fin, "%d", &p_factor) == 1 && p_factor >= 0 && fscanf(fin, "%d", &j_factor) == 1 && j_factor >= 0)
                        code_error = make_sqare_matr(&matrix_a, position);
                    else
                        code_error = ERROR_INPUT;
                }
                if (!code_error)
                    code_error = make_sqare_matr(&matrix_b, position);

                if (!code_error)
                    code_error = choice(&matrix_a, &matrix_b);

                if (!code_error)
                {
                    matrix_pow_a.row = matrix_a.row;
                    matrix_pow_a.column = matrix_a.column;
                    code_error = create_matr(&matrix_pow_a);

                    matrix_pow_b.row = matrix_a.row;
                    matrix_pow_b.column = matrix_a.column;
                    code_error = create_matr(&matrix_pow_b);

                    matrix_result.row = matrix_a.row;
                    matrix_result.column = matrix_a.column;
                    code_error = create_matr(&matrix_result);

                    if (!code_error)
                        code_error = pow_matr(&matrix_a, &matrix_pow_a, p_factor);

                    if (!code_error)
                        code_error = pow_matr(&matrix_b, &matrix_pow_b, j_factor);

                    if (!code_error)
                    {
                        multiplication_quad_matr(&matrix_pow_a, &matrix_pow_b, &matrix_result);
                        output_matr(&matrix_result, fout);
                    }

                    delete_matr(&matrix_result);
                    delete_matr(&matrix_pow_b);
                    delete_matr(&matrix_pow_a);
                }
                delete_matr(&matrix_b);
            }
            else
                code_error = ERROR_INPUT;
        }
        delete_matr(&matrix_a);
    }
    else
        code_error = ERROR_INPUT;

    return code_error;
}


