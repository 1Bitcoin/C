#include <stdio.h>
#include <stdlib.h>

#define TRUE 0
#define FALSE 1

int count(int number, int power);

int main()
{
    int number, power, rc;
    float temp;
    int out = TRUE;

    printf("Input number, power: ");
    rc = scanf("%d %f", &number, &temp);

    power = (int)temp;
    if (rc == 2 && power >= 0 && (temp / power == 1))
        printf("%d", count(number, power));
    else
        out = FALSE;

    return out;
}

int count(int number, int power)
{
    int y = 1;

    while (power > 0)
    {
        y *= number;
        power --;
    }

    return y;
}
