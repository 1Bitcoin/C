#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "function.h"

int my_snprintf(char *string, size_t n, const char *format, ...)
{
    int count_specifier = check_count_specifier(format);

    if (string && n)
    {
        clear_string(string, n);

        int len_string = strlen(format);
        int j = 0;

        va_list factor;
        va_start(factor, format);
        n--;
        for (int i = 0; i < len_string && n; i++, n--)
        {
            if (format[i] == '%' && i != len_string - 1 && format[i + 1] == 'c')
            {
                string[j] = va_arg(factor, int);
                i += 1;
            }
            else
                string[j] = format[i];
            j++;
        }

        va_end(factor);
    }

    return strlen(format) - count_specifier;
}

int check_count_specifier(const char *string)
{
    int len_string = strlen(string);
    int count_specifier = 0;

    for (int i = 0; i < len_string; i++)
        if (string[i] == '%' && i != len_string - 1 && string[i + 1] == 'c')
            count_specifier++;


    return count_specifier;
}

void clear_string(char *string, int len_string)
{
    for (int i = 0; i < len_string; i++)
        string[i] = '\0';
}

int cmp_int(int first, int second)
{
    return first - second;
}
