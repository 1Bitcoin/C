#include <stdio.h>
#include <stdlib.h>
#include "proc.h"

int main()
{
    int code_error = proc(stdin, stdout);
    return code_error;
}
