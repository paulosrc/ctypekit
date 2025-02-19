#ifndef LIST_H
#define LIST_H

#include "node.h"

#define NEXT links[0]
#define PREV links[1]

typedef struct list
{
    Node* head;
    Node* tail;
    bool isCircular;
} List;

List* list_init(bool isCircular, int linkCount);
void list_free(List* list);
void list_add_node(List* list, void* value);

#endif