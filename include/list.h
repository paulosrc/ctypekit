#ifndef LIST_H
#define LIST_H

#include "node.h"

#define NEXT links[0]
#define PREV links[1]

#define LIST_MAX_SIZE 10000
typedef struct list
{
    node_t* head;
    node_t* tail;
    bool isCircular;
} list_t;

list_t* list_init(bool isCircular, int linkCount);
bool is_list_empty(list_t* list);
void list_free(list_t* list);
size_t list_size(list_t* list);
node_t* get_node_at_index(list_t* list, size_t index);
void list_add_node(list_t* list, void* value, size_t index);
void list_remove_node(list_t* list, size_t index);

#endif