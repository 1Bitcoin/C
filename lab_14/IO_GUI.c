#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "ui.h"
#include "IO_GUI.h"
#include "lib.h"
#include "ui_input.h"

void input(int **array, int *size, int *p, FILE *fin)
{
    realloc_to_array(array, *size, p);
    if (!(*p))
    {
        for (int i = 0; i < *size; i++)
        {
            if (fscanf(fin, "%d", (*array + i)) != 1)
                *p = FALSE;
        }
    }
}

void output(int *array, int size)
{
    uiMultilineEntrySetText(mul_entry, "");
    char *product_info = malloc(sizeof(char) * 20);
    for (int i = 0; i < size; i++)
    {
        sprintf(product_info, "%d ", array[i]);
        uiMultilineEntryAppend(mul_entry, product_info);
    }
}
