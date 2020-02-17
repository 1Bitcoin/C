#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "proc.h"
#include "lib.h"
#include "IO_GUI.h"
#include "error_message.h"

void proc(FILE *fin)
{
    int out = TRUE;
    int size;

    if (fscanf(fin, "%d", &size) == 1 && size > 0)
    {
        int *array = NULL;
        input(&array, &size, &out, fin);

        if (!out)
        {
            int average = calc_average(array, size);
            delete_elems_array(&array, &size, average, &out);

            if (!out)
            {
                int position;
                if (fscanf(fin, "%d", &position) == 1 && position >= 0 && position < size)
                {
                    int max_number;
                    find_max(array, size, &max_number);
                    add_numbers(&array, &size, max_number, position, &out);

                    if (!out)
                        output(array, size);
                }
                else
                    out = FALSE;
            }
        }
        free(array);
    }
    else
        out = FALSE;

    if (out)
    {
        input_error();
    }
}
