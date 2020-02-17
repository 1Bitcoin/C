#ifndef _WORK_WITH_CONVOLUTION_H_
#define  _WORK_WITH_CONVOLUTION_H_

#include "read_info_from_bmp.h"

void input_core(FILE *core, double *core_array);
matr_t **approximation_convolution_with_kernel(struct_bmp *bmp, matr_t **matrix, double *core_array);
void make_this_gauss(struct_bmp *bmp, double *core_array);
void input_gradient(FILE *grad_x, FILE *grad_y, double *gradient_x, double *gradient_y);
matr_t **make_gradient_for_image(matr_t **matrix, int height, int widht, double *gradient_x, double *gradient_y);
double gradient_len(matr_t **matrix, double *gradient_x, double *gradient_y, int x, int y);
double multiplic_matr(matr_t **matrix, double *gradient, int i, int j);
void make_this_grad(struct_bmp *bmp, double *gradient_x, double *gradient_y);
void run_gauss(char *name_picture, int *code_error);
void run_gradient(char *name_picture, int *code_error);
int gauss_coef(double sigma, double a[3], double *b0);

#endif
