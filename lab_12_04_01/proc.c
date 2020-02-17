#include <stdio.h>
#include <stdlib.h>

#include "choice.h"
#include "factorization.h"
#include "IO.h"
#include "list.h"
#include "library_for_task.h"

int proc(FILE *fin, FILE *fout)
{
    char *choice = (char *) malloc(4 * sizeof(char));

    list f_list;
    list s_list;

    f_list.head = NULL;
    s_list.head = NULL;

    int code_error = input_choice(fin, choice);

    if (!code_error)
        code_error = choice_actions(fin, fout, &f_list, &s_list, choice);

    free(choice);

    //fprintf(fout, "%d", code_error);
    return code_error;
}
