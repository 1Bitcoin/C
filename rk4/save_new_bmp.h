#ifndef _SAVE_NEW_BMP_H_
#define _SAVE_NEW_BMP_H_

#include <stdio.h>
#include <stdint.h>
#include "work_with_struct.h"

void save_bmp(FILE *file, const struct_bmp *bmp);
int menu(void);

#endif

