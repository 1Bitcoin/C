#ifndef _WORK_WITH_MATRIX_H_
#define _WORK_WITH_MATRIX_H_

#include "read_info_from_bmp.h"

matr_t **create_matr(matr_t **matrix, int height, int widht);
void make_matrix_with_zeros_around_edges(struct_bmp *bmp);
void output_matr(const struct_bmp *bmp);

#endif


