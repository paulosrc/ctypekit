#include "../include/node.h"

/*
    Função que inicializa um nó vazio
    Recebe a quantidade de ligações que o nó faz
    E retorna um Ponteiro para um nó vazio.
*/
Node* node_init(int linkCount)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    assert(newNode != NULL);

    newNode->links = (void**)malloc(sizeof(void**) * linkCount);
    assert(newNode->links != NULL);
    
    newNode->linkCount = linkCount;
    
    return newNode;
}

/*
    Função que recebe um ponteiro para um nó
    E libera a memória alocada para as conexões
    e a memória alocada para o próprio nó.
*/
void node_free(Node* node)
{
    assert(node != NULL);

    free(node->data);
    if (node->links != NULL)
    {
        free(node->links);
    }
    free(node);
}