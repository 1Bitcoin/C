#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "IO.h"
#include "proc.h"

int main()
{
    FILE *fin_1 = fopen("in_1.txt", "r");
    printf("%d\n", proc(fin_1));
    fclose(fin_1);

    FILE *fin_2 = fopen("in_2.txt", "r");
    printf("%d\n", proc(fin_2));
    fclose(fin_2);

    FILE *fin_3 = fopen("in_3.txt", "r");
    printf("%d\n", proc(fin_3));
    fclose(fin_3);

    FILE *fin_4 = fopen("in_4.txt", "r");
    printf("%d\n", proc(fin_4));
    fclose(fin_4);

    FILE *fin_5 = fopen("in_5.txt", "r");
    printf("%d\n", proc(fin_5));
    fclose(fin_5);

    FILE *fin_6 = fopen("in_6.txt", "r");
    printf("%d\n", proc(fin_6));
    fclose(fin_6);

    FILE *fin_7 = fopen("in_7.txt", "r");
    printf("%d\n", proc(fin_7));
    fclose(fin_7);

    FILE *fin_8 = fopen("in_8.txt", "r");
    printf("%d\n", proc(fin_8));
    fclose(fin_8);

    FILE *fin_9 = fopen("in_9.txt", "r");
    printf("%d\n", proc(fin_9));
    fclose(fin_9);

    FILE *fin_10 = fopen("in_10.txt", "r");
    printf("%d\n", proc(fin_10));
    fclose(fin_10);

    return 0;
}
