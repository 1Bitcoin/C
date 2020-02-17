#ifndef __FUNCTION_H__
#define __FUNCTION_H__

#define OK 0;
#define BAD_INPUT -1
#define NO_ELEMENTS -2
#define INVALID_LEN -3

#define DOUBLE 2

int my_snprintf(char *string, size_t n, const char *format, ...);
int check_count_specifier(const char *string);
void clear_string(char *string, int len_string);
int cmp_int(int first, int second);

#endif
