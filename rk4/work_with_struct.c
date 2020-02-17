#include <stdio.h>
#include <stdlib.h>
#include "work_with_struct.h"
#include "save_new_bmp.h"
#include "read_info_from_bmp.h"
#include "work_with_matrix.h"

struct_bmp *create_empty_struct_bmp()
{
    struct_bmp *bmp = malloc(sizeof(struct_bmp));
    if (bmp)
    {
        bmp->red_matr = NULL;
        bmp->green_matr = NULL;
        bmp->blue_matr = NULL;
    }
    return bmp;
}

struct_bmp *create_struct_bmp(const int height, const int width)
{
    struct_bmp *bmp = create_empty_struct_bmp();

    bmp->height = height;
    bmp->widht = width;

    if (bmp)
    {
        bmp->red_matr = create_matr(bmp->red_matr, height, width);
        bmp->blue_matr = create_matr(bmp->blue_matr, height, width);
        bmp->green_matr = create_matr(bmp->green_matr, height, width);
    }

    return bmp;
}
