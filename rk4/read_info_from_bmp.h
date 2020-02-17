#ifndef _READ_INFO_FROM_BMP_H_
#define _READ_INFO_FROM_BMP_H_

#include <stdio.h>
#include <stdint.h>

#define OFF_SET_BITS 10
#define OFF_SIZE 14
#define OFF_WIDHT 18
#define OFF_HEIGHT 22

typedef double matr_t;

typedef struct
{
    int widht;
    int height;
    matr_t **red_matr;
    matr_t **green_matr;
    matr_t **blue_matr;
}struct_bmp;

void read_width(FILE *file, uint32_t *width);
void read_height(FILE *file, uint32_t *height);
void read_offsetbits(FILE *file, uint32_t *offsetbits);
int read_pixel(FILE *file, uint8_t *temp);
struct_bmp *read_bmp(FILE *file);

#endif
