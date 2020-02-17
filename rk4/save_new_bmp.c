#include <stdio.h>
#include <stdlib.h>
#include "work_with_struct.h"
#include "save_new_bmp.h"
#include "read_info_from_bmp.h"
#include "work_with_matrix.h"
#include "work_with_convolution.h"

void save_bmp(FILE *file, const struct_bmp *bmp)
{
    fseek(file, 0, SEEK_SET);
    uint8_t tmpUInt8 = 0;
    uint16_t tmpUInt16 = 0;
    uint32_t tmpUInt32 = 0;
    int32_t tmpInt32 = 0;

    uint8_t shift = bmp->widht % 4;

    fputc('B', file);
    fputc('M', file);

    tmpUInt32 = 10;
    fwrite(&tmpUInt32, sizeof(uint32_t), 1, file);

    fputc(0, file);
    fputc(0, file);
    fputc(0, file);
    fputc(0, file);

    tmpUInt32 = 14 + 40;
    fwrite(&tmpUInt32, sizeof(uint32_t), 1, file);

    tmpUInt32 = 40;
    fwrite(&tmpUInt32, sizeof(uint32_t), 1, file);

    tmpInt32 = (int32_t)bmp->widht;
    fwrite(&tmpInt32, sizeof(int32_t), 1, file);

    tmpInt32 = (int32_t)bmp->height;
    fwrite(&tmpInt32, sizeof(int32_t), 1, file);

    tmpUInt16 = 1;
    fwrite(&tmpUInt16, sizeof(uint16_t), 1, file);

    tmpUInt16 = 24;
    fwrite(&tmpUInt16, sizeof(uint16_t), 1, file);

    tmpUInt32 = 0;
    fwrite(&tmpUInt32, sizeof(uint32_t), 1, file);

    tmpUInt32 = bmp->height * (bmp->widht + shift) * 32;
    fwrite(&tmpUInt32, sizeof(uint32_t), 1, file);

    tmpInt32 = 2835;
    fwrite(&tmpInt32, sizeof(int32_t), 1, file);

    tmpInt32 = 2835;
    fwrite(&tmpInt32, sizeof(int32_t), 1, file);

    tmpUInt32 = 0;
    fwrite(&tmpUInt32, sizeof(uint32_t), 1, file);

    tmpUInt32 = 0;
    fwrite(&tmpUInt32, sizeof(uint32_t), 1, file);

    tmpUInt32 = 0;

    for (int i = 0; i < bmp->height; i++)
    {
        for (int j = 0; j < bmp->widht; j++)
        {
            tmpUInt8 = bmp->blue_matr[i + 1][j + 1];
            fwrite(&tmpUInt8, sizeof(uint8_t), 1, file);
            tmpUInt8 = bmp->green_matr[i + 1][j + 1];
            fwrite(&tmpUInt8, sizeof(uint8_t), 1, file);
            tmpUInt8 = bmp->red_matr[i + 1][j + 1];
            fwrite(&tmpUInt8, sizeof(uint8_t), 1, file);
        }
        // выравнивание
        for (size_t i = 0; i < shift; i++)
            fwrite(&tmpUInt8, sizeof(uint8_t), 1, file);
    }
}

int menu(void)
{
    int code_error = 0;
    int choose = 0;
    char name_picture[20];

    puts("\n\n----------------------------------------------------Pre-alpha 0.99---------------------------------------------------\n\n");
    puts("Without GUI but you hold on! (libui don't work :( )\n");

    //рофл
    puts("\nLoading 56%..\n");
    puts("Loading 99%..\n");

    puts("\nStart program:\n");

    //конец рофлов

    puts("Input name picture (with .bmp) (test example in directory: triss.bmp)");
    scanf("%s", name_picture);

    puts("\nChoose: \n0 - Exit\n1 - Gauss filter (100%) \n2 - Gradient (fifty-fifty, but you see my calculation in work_with_convolution.c) \n");
    puts("Your choose:");
    scanf("%d", &choose);

    switch (choose)
    {
        case 0:
            return 0;
        break;

        case 1:
            run_gauss(name_picture, &code_error);
            if (!code_error)
                puts("You can see new image in directory. Name: new_image.bmp");
            else
                puts("You did not manage! bad user!");
            break;

        case 2:
            run_gradient(name_picture, &code_error);
            if (!code_error)
                puts("You can see new image in directory. Name: new_image.bmp");
            else
                puts("You did not manage! bad user!");
            break;
    }

    return code_error;
}
