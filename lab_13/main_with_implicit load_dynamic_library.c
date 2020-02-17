#include <stdio.h>
#include <stdlib.h>
#include "IO_LIB.h"
#include "lib.h"

int main()
{
    int code_error = TRUE;
    int size;

    printf("Input size");
    if (scanf("%d", &size) == 1 && size > 0)
    {
        printf("Input numbers");

        double *array = NULL;
        input(&array, &size, &code_error);

        if (!code_error)
        {
            double average = calc_average(array, size);
            delete_elems_array(&array, &size, average, &code_error);

            if (!code_error)
            {
                int position;
                printf("Input position");
                if (scanf("%d", &position) == 1 && position >= 0 && position < size)
                {
                    double max_number;
                    find_max(array, size, &max_number);
                    add_numbers(&array, &size, max_number, position, &code_error);

                    if (!code_error)
                        output(array, size);
                }
                else
                    code_error = FALSE;
            }
        }
        free(array);
    }
    else
        code_error = FALSE;
    return code_error;
}
