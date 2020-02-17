#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MY_FABS() fabs(num - middle_value)

double middle_value(FILE *f, int *flag);
double check_numbers(FILE *f, double middle_value);
void calc(double *difference, double *ans, double num, double middle_value);

int main(int argc, char **argv)
{
    int flag = 0;
    FILE *f;

    if (argc != 2)
    {
        fprintf(stderr, "num_reader.exe <file-name>\n");
        flag = -1;
    }

    f = fopen(argv[1], "r");

    if (f == NULL)
    {
        fprintf(stderr, "I/O error\n");
        flag = -2;
    }

    if (getc(f) == EOF)
    {
        fprintf(stderr, "Empty\n");
        flag = -3;
    }

    if (flag == 0)
    {
        double middle = middle_value(f, &flag);
        fclose(f);

        if (flag == 0)
        {
            f = fopen(argv[1], "r");
            printf("%.4lf", check_numbers(f, middle));
            fclose(f);
        }
    }
    else
        fclose(f);

    return flag;
}

double middle_value(FILE *f, int *flag)
{
    double count = 0;
    double sum = 0;
    double num;

    while (fscanf(f, "%lf", &num) == 1)
    {
        count++;
        sum += num;
    }

    if (fscanf(f, "%lf", &num) != 1 && feof(f) == 0)
        *flag = -4;

    return sum / count;
}

double check_numbers(FILE *f, double middle_value)
{
    double num, ans;
    double difference;

    if (fscanf(f, "%lf", &num) == 1)
        calc(&difference, &ans, num, middle_value);

    while (fscanf(f, "%lf", &num) == 1)
        if (MY_FABS() < difference)
            calc(&difference, &ans, num, middle_value);

    return ans;
}

void calc(double *difference, double *ans, double num, double middle_value)
{
    *difference = MY_FABS();
    *ans = num;
}
