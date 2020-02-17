#include <stdio.h>
#include <stdlib.h>

#include <malloc.h>
#include "IO.h"
#include "proc.h"

int main()
{
    FILE *fin = fopen("in_1.txt", "r");
    FILE *fout = fopen("out_1.txt", "w");
    proc(fin, fout);
    fclose(fin);
    fclose(fout);

    fin = fopen("in_2.txt", "r");
    fout = fopen("out_2.txt", "w");
    proc(fin, fout);
    fclose(fin);
    fclose(fout);

    fin = fopen("in_3.txt", "r");
    fout = fopen("out_3.txt", "w");
    proc(fin, fout);
    fclose(fin);
    fclose(fout);

    fin = fopen("in_4.txt", "r");
    fout = fopen("out_4.txt", "w");
    proc(fin, fout);
    fclose(fin);
    fclose(fout);

    fin = fopen("in_5.txt", "r");
    fout = fopen("out_5.txt", "w");
    proc(fin, fout);
    fclose(fin);
    fclose(fout);

    fin = fopen("in_6.txt", "r");
    fout = fopen("out_6.txt", "w");
    proc(fin, fout);
    fclose(fin);
    fclose(fout);

    fin = fopen("in_7.txt", "r");
    fout = fopen("out_7.txt", "w");
    proc(fin, fout);
    fclose(fin);
    fclose(fout);

    fin = fopen("in_8.txt", "r");
    fout = fopen("out_8.txt", "w");
    proc(fin, fout);
    fclose(fin);
    fclose(fout);

    fin = fopen("in_9.txt", "r");
    fout = fopen("out_9.txt", "w");
    proc(fin, fout);
    fclose(fin);
    fclose(fout);

    fin = fopen("in_10.txt", "r");
    fout = fopen("out_10.txt", "w");
    proc(fin, fout);
    fclose(fin);
    fclose(fout);

    fin = fopen("in_11.txt", "r");
    fout = fopen("out_11.txt", "w");
    proc(fin, fout);
    fclose(fin);
    fclose(fout);

    fin = fopen("in_12.txt", "r");
    fout = fopen("out_12.txt", "w");
    proc(fin, fout);
    fclose(fin);
    fclose(fout);

    fin = fopen("in_13.txt", "r");
    fout = fopen("out_13.txt", "w");
    proc(fin, fout);
    fclose(fin);
    fclose(fout);

    fin = fopen("in_14.txt", "r");
    fout = fopen("out_14.txt", "w");
    proc(fin, fout);
    fclose(fin);
    fclose(fout);

    fin = fopen("in_15.txt", "r");
    fout = fopen("out_15.txt", "w");
    proc(fin, fout);
    fclose(fin);
    fclose(fout);

    fin = fopen("in_16.txt", "r");
    fout = fopen("out_16.txt", "w");
    proc(fin, fout);
    fclose(fin);
    fclose(fout);

    fin = fopen("in_17.txt", "r");
    fout = fopen("out_17.txt", "w");
    proc(fin, fout);
    fclose(fin);
    fclose(fout);

    fin = fopen("in_18.txt", "r");
    fout = fopen("out_18.txt", "w");
    proc(fin, fout);
    fclose(fin);
    fclose(fout);

    fin = fopen("in_19.txt", "r");
    fout = fopen("out_19.txt", "w");
    proc(fin, fout);
    fclose(fin);
    fclose(fout);

    fin = fopen("in_20.txt", "r");
    fout = fopen("out_20.txt", "w");
    proc(fin, fout);
    fclose(fin);
    fclose(fout);

    return 0;
}
