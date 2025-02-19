#include "../include/list.h"

/*
    Recebe a quantidade de ligações que os nós da lista podem realizar;
    Recebe uma variável que define se a lista é circular;
    Retorna um ponteiro para uma lista vazia.
*/
List* list_init(bool isCircular, int linkCount)
{
    List* newList = (List*)malloc(sizeof(List));
    
    newList->head = node_init(linkCount);
    newList->tail = node_init(linkCount);

    newList->head->NEXT = newList->tail;

    if (linkCount > 1) 
    {
        newList->tail->PREV = newList->head;
    }
    
    if (isCircular)
    {
        newList->tail->NEXT = newList->head;

        if (linkCount > 1)
        {
            newList->head->PREV = newList->tail;
        }
    }
}

/*
    Recebe um ponteiro para uma lista;
    Libera a memória alocada para a lista.
*/
void list_free(List* list)
{
    if (list == NULL) return;

    Node* current = list->head;
    
    while (current != NULL)
    {
        Node *next = current->NEXT;
        node_free(current);
        current = next;
    }
    free(list);
}

/*
    Recebe um ponteiro para uma lista;
    Recebe um ponteiro genérico para um dado;
    Insere o dado em um novo nó na lista.
*/
void list_add_node(List* list, void* value)
{

}