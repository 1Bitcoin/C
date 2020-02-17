#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

int main()
{
    DblLinkedList *list = createDblLinkedList();
    student_t first_st, second_st, third_st, new_st;
    //student_t *array;

    first_st.name = "dima";
    first_st.age = 19;
    first_st.count = 4;

    second_st.name = "ivan";
    second_st.age = 200;
    second_st.count = 5;

    third_st.name = "vasya";
    third_st.age = 5;
    third_st.count = 1;

    new_st.name = "katya";
    new_st.age = 22;
    new_st.count = 5;

    pushFront(list, first_st);
    pushFront(list, second_st);
    pushFront(list, third_st);


    insertionSort(&list); //sorting by age

    printDblLinkedList(list);
    printf("\n");

    pushBack(list, first_st); //push back

    printf("length %ld\n\n", list->size);
    printDblLinkedList(list);

    pushBack(list, new_st); //push back

    printf("length %ld\n\n", list->size);
    printDblLinkedList(list);

    insertionSort(&list); //sorting by age

    printDblLinkedList(list);

    return 0;
}
