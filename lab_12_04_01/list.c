#include <stdio.h>
#include <stdlib.h>

#include "list.h"

node *get_last(list *list)
{
    node *buf = list->head;
    if (buf)
        while (buf->next)
            buf = buf->next;
    return buf;
}

void push_back(list *list, int coefficient, int degree)
{
    node *buf = list->head;
    node *tmp = (node*) malloc(sizeof(node));
    tmp->info = malloc(sizeof(container));

    ((container *)tmp->info)->coefficient = coefficient;
    ((container *)tmp->info)->degree = degree;

    if (!(buf))
    {
        tmp->next = list->head;
        list->head = tmp;
    }
    else
    {
        node *last = get_last(list);
        tmp->next = NULL;
        last->next = tmp;
    }
}

void push(list *list, int coefficient, int degree)
{
    node *tmp = (node*) malloc(sizeof(node));
    tmp->info = malloc(sizeof(container));

    ((container *)tmp->info)->coefficient = coefficient;
    ((container *)tmp->info)->degree = degree;

    tmp->next = list->head;
    list->head = tmp;
}

void delete_list(list *list)
{
    node *prev = NULL;
    while (list->head)
    {
        prev = list->head;
        list->head = list->head->next;
        free(prev->info);
        free(prev);
    }
    free(list->head);
}
