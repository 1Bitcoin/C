#ifndef __FUNC_H__
#define __FUNC_H__

typedef struct
{
    char *name;
    int age;
    int count;
}student_t;

typedef struct _Node
{
    student_t student;
    struct _Node *next;
    struct _Node *prev;
}Node;

typedef struct _DblLinkedList
{
    size_t size;
    Node *head;
    Node *tail;
}DblLinkedList;

DblLinkedList *createDblLinkedList();
student_t popFront(DblLinkedList *list);
void pushBack(DblLinkedList *list, student_t student);
void pushFront(DblLinkedList *list, student_t student);
void insertBeforeElement(DblLinkedList *list, Node* elm, student_t student);
void insertionSort(DblLinkedList **list);
void printDblLinkedList(DblLinkedList *list);
void input_struct(student_t student);



#endif
