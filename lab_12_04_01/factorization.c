#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "factorization.h"

void factors(list *list, int number)
{
    int degree = 0;

    if (number == 1)
        push(list, 1, 1);

    for (int n = 2; number > 1;)
    {
        if (number % n == 0)
        {
            degree++;
            number /= n;
        }
        if (number % n != 0 || number == 1)
        {
            if (degree)
            {
                push(list, n, degree);
                degree = 0;
            }
            n++;
        }
    }
}
