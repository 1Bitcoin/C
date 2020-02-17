#include <stdio.h>
#include <stdlib.h>
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

    return 0;
}
