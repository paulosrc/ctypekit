#ifndef NODE_H
#define NODE_H

#include <stdlib.h>

/*
    Estrutura de Nó usado em todas as estruturas abstratas de dados.
    Possui os seguintes campos:

    1. data: do tipo "void*" (ponteiro genérico) aponta para o dado a ser armazenado no nó, que
    pode ser um int, char, float, double, string, etc.

    2. links: do tipo "void**" armazena todas as conexões do nó atual com outros nós.

    3. linkCount: do tipo "int", marca a quantidade de conexões que o nó pode realizar
    e é usada para alocar a memória de links
*/
typedef struct node
{
    void* data;
    void** links;
    int linkCount;
} Node;

Node* node_init(int linkCount);
void node_free(Node* node);

#endif