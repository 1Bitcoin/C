#include <stdio.h>
#include <stdint.h>
#include "read_info_from_bmp.h"
#include "work_with_struct.h"
#include "work_with_matrix.h"

void read_width(FILE *file, uint32_t *width)
{
    fseek(file, OFF_WIDHT, SEEK_SET);
    fread(width, 4, 1, file);
}

void read_height(FILE *file, uint32_t *height)
{
    fseek(file, OFF_HEIGHT, SEEK_SET);
    fread(height, 4, 1, file);
}

void read_offsetbits(FILE *file, uint32_t *offsetbits)
{
    fseek(file, OFF_SET_BITS, SEEK_SET);
    fread(offsetbits, 4, 1, file);
}

int read_pixel(FILE *file, uint8_t *temp)
{
    return fread(temp, sizeof(uint8_t), 1, file);
}

struct_bmp *read_bmp(FILE *file)
{
    struct_bmp *bmp = NULL;

    uint32_t n, m, offsetbits;
    uint16_t bits_per_pixel = 0;

    read_width(file, &m);
    read_height(file, &n);

    bmp = create_struct_bmp(n, m);

    fseek(file, 28, SEEK_SET);
    fread(&bits_per_pixel, sizeof(uint16_t), 1, file);

    read_offsetbits(file, &offsetbits);
    fseek(file, offsetbits, SEEK_SET);

    uint8_t temp;

    uint8_t shift = m % 4;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            read_pixel(file, &temp);
            bmp->blue_matr[i + 1][j + 1] = temp;

            read_pixel(file, &temp);
            bmp->green_matr[i + 1][j + 1] = temp;

            read_pixel(file, &temp);
            bmp->red_matr[i + 1][j + 1] = temp;

            if (bits_per_pixel > 24)
                fseek(file, 1, SEEK_CUR);
        }
    }

    make_matrix_with_zeros_around_edges(bmp);

    return bmp;
}
