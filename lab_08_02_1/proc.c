#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "lib.h"
#include "IO_TEST.h"

void proc(FILE *fin, FILE *fout)
{
    int out = TRUE;
    int size;

    printf("Input size");
    if (fscanf(fin, "%d", &size) == 1 && size > 0)
    {
        printf("Input numbers");

        double *array = NULL;
        input(&array, &size, &out, fin);

        if (!out)
        {
            double average = calc_average(array, size);
            delete_elems_array(&array, &size, average, &out);

            if (!out)
            {
                int position;
                printf("Input position");
                if (fscanf(fin, "%d", &position) == 1 && position >= 0 && position < size)
                {
                    double max_number;
                    find_max(array, size, &max_number);
                    add_numbers(&array, &size, max_number, position, &out);

                    if (!out)
                        output(array, size, fout);
                }
                else
                    out = FALSE;
            }
        }
        free(array);
    }
    else
        out = FALSE;
    fprintf(fout, "%d", out);
}
