#ifndef __LIST_H__
#define __LIST_H__

typedef enum
{
    work,
    not_work,
    bad_input,
    error_input_memory
} code;

typedef struct container
{
    int coefficient;
    int degree;
} container;

typedef struct node
{
    void *info;
    struct node *next;
} node;

typedef struct list
{
    struct node *head;
} list;

void push(list *list, int coefficient, int degree);
void delete_list(list *list);
node *get_last(list *list);
void push_back(list *list, int coefficient, int degree);

#endif
