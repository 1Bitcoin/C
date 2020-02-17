#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "func.h"
#include "string.h"

DblLinkedList *createDblLinkedList()
{
    DblLinkedList *tmp = (DblLinkedList*) malloc(sizeof(DblLinkedList));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;

    return tmp;
}

student_t popFront(DblLinkedList *list)
{
    Node *prev;
    student_t tmp;

    prev = list->head;
    list->head = list->head->next;
    if (list->head)
        list->head->prev = NULL;

    if (prev == list->tail)
        list->tail = NULL;

    tmp = prev->student;
    free(prev);

    list->size--;
    return tmp;
}

void pushBack(DblLinkedList *list, student_t student)
{
    Node *tmp = (Node*) malloc(sizeof(Node));

    tmp->student = student;
    tmp->next = NULL;
    tmp->prev = list->tail;
    if (list->tail)
        list->tail->next = tmp;

    list->tail = tmp;

    if (list->head == NULL)
        list->head = tmp;

    list->size++;
}

void pushFront(DblLinkedList *list, student_t student)
{
    Node *tmp = (Node*) malloc(sizeof(Node));

    tmp->student = student;
    tmp->next = list->head;
    tmp->prev = NULL;
    if (list->head)
        list->head->prev = tmp;

    list->head = tmp;

    if (list->tail == NULL)
        list->tail = tmp;

    list->size++;
}

void insertBeforeElement(DblLinkedList *list, Node* elm, student_t student)
{
    Node *ins = NULL;

    if (!elm->prev)
        pushFront(list, student);// ï

    ins = (Node*) malloc(sizeof(Node));
    ins->student = student;
    ins->prev = elm->prev;
    elm->prev->next = ins;
    ins->next = elm;
    elm->prev = ins;

    list->size++;
}


void insertionSort(DblLinkedList **list)
{
    DblLinkedList *out = createDblLinkedList();
    Node *sorted = NULL;
    Node *unsorted = NULL;

    pushFront(out, popFront(*list));

    unsorted = (*list)->head;
    while (unsorted)
    {
        sorted = out->head;
        while (sorted && unsorted->student.age > sorted->student.age)
            sorted = sorted->next;

        if (sorted)
            insertBeforeElement(out, sorted, unsorted->student);
        else
            pushBack(out, unsorted->student);

        unsorted = unsorted->next;
    }

    free(*list);
    *list = out;
}


void printDblLinkedList(DblLinkedList *list)
{
    Node *tmp = list->head;
    while (tmp)
    {
        printf("%s ", tmp->student.name);
        printf("%d ", tmp->student.age);
        printf("%d ", tmp->student.count);
        printf("\n");
        tmp = tmp->next;
    }
    printf("\n");
}

void input_struct(student_t student)
{
    char *buf_ar = (char *)malloc(256 * sizeof(char));
    printf("stop input: input nothing in field name\n");
    printf("Input name, age, count: ");
    while (strcmp(buf_ar, "nothing"))
    {
        //scanf();
    }

    free(buf_ar);
}
