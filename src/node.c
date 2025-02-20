#include "../include/node.h"

/*
    Recebe a quantidade de ligações que um nó pode realizar;
    Retorna um ponteiro para um nó vazio.
*/
node_t* node_init(int linkCount)
{
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    assert(newNode != NULL);

    newNode->data = NULL;

    newNode->links = (void**)malloc(sizeof(void**) * linkCount);
    assert(newNode->links != NULL);
    
    newNode->linkCount = linkCount;
    
    return newNode;
}

/*
    Recebe um ponteiro para um nó;
    Libera a memória alocada para o nó.
*/
void node_free(node_t* node)
{
    if (node == NULL) return;

    free(node->data);
    if (node->links != NULL)
    {
        free(node->links);
    }
    free(node);
}