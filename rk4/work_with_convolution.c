#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "work_with_struct.h"
#include "save_new_bmp.h"
#include "read_info_from_bmp.h"
#include "work_with_matrix.h"
#include "work_with_convolution.h"

void input_core(FILE *core, double *core_array)
{
    for (int i = 0; i < 9; i++)
        fscanf(core, "%lf", core_array + i);
}
//вычисление коэфа у гаусса, не доделано, возможно, балл накинете :)
int gauss_coef(double sigma, double a[3], double *b0)
{
	double sigma_inv_4;

	sigma_inv_4 = sigma*sigma; sigma_inv_4 = 1.0/(sigma_inv_4*sigma_inv_4);

	double coef_A = sigma_inv_4*(sigma*(sigma*(sigma*1.1442707+0.0130625)-0.7500910)+0.2546730);
	double coef_W = sigma_inv_4*(sigma*(sigma*(sigma*1.3642870+0.0088755)-0.3255340)+0.3016210);
	double coef_B = sigma_inv_4*(sigma*(sigma*(sigma*1.2397166-0.0001644)-0.6363580)-0.0536068);

	double z0_abs = exp(coef_A);

	double z0_real = z0_abs*cos(coef_W);
	double z2 = exp(coef_B);

	double z0_abs_2 = z0_abs*z0_abs;

	a[2] = 1.0/(z2*z0_abs_2);
	a[0] = (z0_abs_2+2*z0_real*z2)*a[2];
	a[1] = -(2*z0_real+z2)*a[2];

	*b0 = 1.0 - a[0] - a[1] - a[2];

	return 0;
};

matr_t **approximation_convolution_with_kernel(struct_bmp *bmp, matr_t **matrix, double *core_array)
{
    for (int i = 0; i < bmp->height; i++)
    {
        for (int j = 0; j < bmp->widht; j++)
        {
            matrix[i + 1][j + 1] = matrix[i][j] * core_array[0] + matrix[i][j + 1] * core_array[1] +
            matrix[i][j + 2] * core_array[2] + matrix[i + 1][j] * core_array[3] +
            matrix[i + 1][j + 1] * core_array[4] + matrix[i + 1][j + 2] * core_array[5] +
            matrix[i + 2][j] * core_array[6] + matrix[i + 2][j + 1] * core_array[7] +
            matrix[i + 2][j + 2] * core_array[8];
        }
    }
    return matrix;
}

void make_this_gauss(struct_bmp *bmp, double *core_array)
{
    for (int i = 0; i < 2; i++)
    {
        bmp->red_matr = approximation_convolution_with_kernel(bmp, bmp->red_matr, core_array);
        bmp->blue_matr = approximation_convolution_with_kernel(bmp, bmp->blue_matr, core_array);
        bmp->green_matr = approximation_convolution_with_kernel(bmp, bmp->green_matr, core_array);
    }
}

void input_gradient(FILE *grad_x, FILE *grad_y, double *gradient_x, double *gradient_y)
{
    for (int i = 0; i < 9; i++)
        fscanf(grad_x, "%lf", gradient_x + i);

    for (int i = 0; i < 9; i++)
        fscanf(grad_y, "%lf", gradient_y + i);
}

matr_t **make_gradient_for_image(matr_t **matrix, int height, int widht, double *gradient_x, double *gradient_y)
{
    for (int i = 0; i < height; i++)
        for (int j = 0; j < widht; j++)
            matrix[i + 1][j + 1] = gradient_len(matrix, gradient_x, gradient_y, i, j);

    return matrix;
}

double gradient_len(matr_t **matrix, double *gradient_x, double *gradient_y, int x, int y)
{
    double answer = 0;

    double der_x = multiplic_matr(matrix, gradient_x, x, y);
    double der_y = multiplic_matr(matrix, gradient_y, x, y);

    answer = sqrt(der_x * der_x + der_y * der_y);

    return answer;
}

double multiplic_matr(matr_t **matrix, double *gradient, int i, int j)
{
    double answer =  matrix[i][j] * gradient[0] + matrix[i][j + 1] * gradient[1] +
    matrix[i][j + 2] * gradient[2] + matrix[i + 1][j] * gradient[3] +
    matrix[i + 1][j + 1] * gradient[4] + matrix[i + 1][j + 2] * gradient[5] +
    matrix[i + 2][j] * gradient[6] + matrix[i + 2][j + 1] * gradient[7] +
    matrix[i + 2][j + 2] * gradient[8];

    return answer;
}

void make_this_grad(struct_bmp *bmp, double *gradient_x, double *gradient_y)
{
    bmp->red_matr = make_gradient_for_image(bmp->red_matr, bmp->height, bmp->widht, gradient_x, gradient_y);
    bmp->blue_matr = make_gradient_for_image(bmp->blue_matr, bmp->height, bmp->widht, gradient_x, gradient_y);
    bmp->green_matr = make_gradient_for_image(bmp->green_matr, bmp->height, bmp->widht, gradient_x, gradient_y);
}

void run_gauss(char *name_picture, int *code_error)
{
    FILE *core = fopen("gauss.txt", "r");
    FILE *end_image = fopen("new_image.bmp", "wb");
    FILE *begin_image = fopen(name_picture, "rb");
    if (core && end_image && begin_image)
    {
        struct_bmp *bmp = read_bmp(begin_image);

        double core_array[9];

        input_core(core, core_array);
        make_this_gauss(bmp, core_array);
        save_bmp(end_image, bmp);

        fclose(core);
        fclose(begin_image);
        fclose(end_image);
    }
    else
        *code_error = 2;
}

void run_gradient(char *name_picture, int *code_error)
{
    FILE *end_image = fopen("new_image.bmp", "wb");
    FILE *begin_image = fopen(name_picture, "rb");
    FILE *grad_x = fopen("gradient_x.txt", "r");
    FILE *grad_y = fopen("gradient_y.txt", "r");

    if (grad_x && grad_y && end_image && begin_image)
    {
        struct_bmp *bmp = read_bmp(begin_image);

        double grad_x_array[9];
        double grad_y_array[9];

        input_gradient(grad_x, grad_y, grad_x_array, grad_y_array);
        make_this_grad(bmp, grad_x_array, grad_y_array);
        save_bmp(end_image, bmp);

        fclose(grad_x);
        fclose(grad_y);
        fclose(begin_image);
        fclose(end_image);
    }
    else
        *code_error = 2;
}
