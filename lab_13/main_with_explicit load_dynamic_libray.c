#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "lib_with_explicit_load_dynamic.h"
#include "IO_LIB_with_explicit_load_dynamic.h"

int main()
{
    HINSTANCE dynamic_library = LoadLibrary("libdynamic.dll");

    int code_error = TRUE;
    int size;

    printf("Input size");
    if (scanf("%d", &size) == 1 && size > 0)
    {
        printf("Input numbers");
        double *array = NULL;
        void (*dll_input)(double **array, int *size, int *p, void *dynamic_library);
        dll_input = (void (*) (double **array, int *size, int *p, void *dynamic_library))
                                                                  GetProcAddress(dynamic_library, "input");
        dll_input(&array, &size, &code_error, dynamic_library);

        if (!code_error)
        {
            double (*dll_calc_average)(double *array, int size);
            dll_calc_average = (double (*) (double *array, int size))
                                            GetProcAddress(dynamic_library, "calc_average");
            double average = dll_calc_average(array, size);

            void (*dll_delete_elems_array)(double **array, int *p_size, double number_to_compare,
                                           int *code_error, void *dynamic_library);
            dll_delete_elems_array = (void (*) (double **array, int *p_size,
                                                double number_to_compare, int *code_error, void *dynamic_library))
                                                GetProcAddress(dynamic_library, "delete_elems_array");
            dll_delete_elems_array(&array, &size, average, &code_error, dynamic_library);
            if (!code_error)
            {
                int position;
                printf("Input position");
                if (scanf("%d", &position) == 1 && position >= 0 && position < size)
                {
                    double max_number;
                    void (*dll_find_max)(double *array, int p_size, double *max_number);
                    dll_find_max = (void (*) (double *array, int p_size, double *max_number))
                                    GetProcAddress(dynamic_library, "find_max");
                    dll_find_max(array, size, &max_number);

                    void (*dll_add_numbers)(double **array, int *p_size, double number_to_add,
                                            int position, int *code_error, void *dynamic_library);
                    dll_add_numbers = (void (*) (double **array, int *p_size, double number_to_add,
                                                 int position, int *code_error, void *dynamic_library))
                                                 GetProcAddress(dynamic_library, "add_numbers");
                    dll_add_numbers(&array, &size, max_number, position, &code_error, dynamic_library);

                    if (!code_error)
                    {
                        void (*dll_output)(double *array, int size);
                        dll_output = (void (*) (double *array, int size))
                                    GetProcAddress(dynamic_library, "output");
                        dll_output(array, size);
                    }
                }
                else
                    code_error = FALSE;
            }
        }
        free(array);
    }
    else
        code_error = FALSE;

    FreeLibrary(dynamic_library);

    return code_error;
}
