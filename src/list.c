#include "../include/list.h"

/*
    1. Recebe a quantidade de ligações que os nós da lista podem realizar
    2. Recebe uma variável que define se a lista é circular
    3. Retorna um ponteiro para uma lista vazia
*/
list_t* list_init(bool isCircular, int linkCount)
{
    list_t* newList = (list_t*)malloc(sizeof(list_t));
    
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
    return newList;
}

// Função auxiliar que verifica se lista está vazia
bool is_list_empty(list_t* list)
{
    return (list->head->NEXT == list->tail);
}

/*
    1. Recebe um ponteiro para uma lista
    2. Retorna o tamanho da lista
*/
size_t list_size(list_t* list)
{
    size_t size = 0;
    
    if (is_list_empty(list)) return size;

    node_t* aux = list->head->NEXT;                   // Começa após o head
    while (aux != list->tail && size < LIST_MAX_SIZE) // Termina antes do tail
    {
        size++;
        aux = aux->NEXT;
    }
    return size;
}

/*
    1. Recebe um ponteiro para uma lista
    2. Libera a memória alocada para a lista
*/
void list_free(list_t* list)
{
    if (list == NULL) return;

    node_t* current = list->head;
    
    int i = 0;
    while (current != NULL && i < LIST_MAX_SIZE)
    {
        node_t *next = current->NEXT;
        node_free(current);
        current = next;
        i++;
    }
    free(list);
}

/*
    1. Recebe um ponteiro para um lista
    2. Recebe um índice
    3. Retorna um ponteiro para o nó correspondente ao índice
*/
node_t* get_node_at_index(list_t* list, size_t index)
{
    if (is_list_empty(list)) return;

    node_t* aux = list->head;
    size_t control = 0;

    while (aux && control < index && control < LIST_MAX_SIZE)
    {
        aux = aux->NEXT;
        control++;
    }
    return aux;
}


/*
    Funções auxiliares de 'list_add_node'
*/

// Adiciona nó em uma lista vazia
static inline void list_add_node_EMPTY(list_t* list, node_t* newNode)
{
    list->head->NEXT = newNode;
    newNode->NEXT = list->tail;

    if (list->head->linkCount > 1) // Caso a lista seja duplamente encadeada
    {
        newNode->PREV = list->head;
        list->tail->PREV = newNode;
    }
}

// Adiciona nó em uma lista NÃO vazia no índice especificado
static inline void list_add_node_AT_INDEX(list_t* list, node_t* newNode, size_t index)
{
    node_t* prev = list->head;
    node_t* current = list->head->NEXT;
    size_t currentIndex = 0;
    size_t control = 0;

    while (current != list->tail && currentIndex < index && control < LIST_MAX_SIZE)
    {
        prev = current;
        current = current->NEXT;
        currentIndex++;
    }

    prev->NEXT = newNode;
    newNode->NEXT = current;

    if (list->head->linkCount > 1) // Caso a lista seja duplamente encadeada
    {
        newNode->PREV = prev;
        if (current != list->tail)
        {
            current->PREV = newNode;
        }
        else
        {
            list->tail->PREV = newNode;
        }
    }
}

/*
    1. Recebe um ponteiro para uma lista
    2. Recebe um ponteiro genérico para um dado
    3. Recebe o índice onde o novo nó deve ser inserido
    4. Insere o dado em um novo nó na lista no índice especificado
*/
void list_add_node(list_t* list, void* value, size_t index)
{
    if (list_size(list) >= LIST_MAX_SIZE)
    {
        return; // Limite máximo de elementos atingido
    }

    // Aloca memória para novo Nó
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    newNode->data = malloc(sizeof(*value));
    memcpy(newNode->data, value, sizeof(*value));
    newNode->NEXT = NULL;
    newNode->PREV = NULL;
    newNode->data = value; // Atribui void* value ao novo nó
    
    // Insere nó na lista caso esteja vazia
    if (is_list_empty(list))
        list_add_node_EMPTY(list, newNode);
    // Insere nó na lista no índice especificado
    else
        list_add_node_AT_INDEX(list, newNode, index);
}

void list_remove_node(list_t* list, size_t index)
{
    if (is_list_empty(list)) return;

    node_t* prev = get_node_at_index(list, index-2);
    node_t* remove = prev->NEXT;
    node_t* next = remove->NEXT;

    prev->NEXT = next;

    if (list->head->linkCount > 1)
    {
        next->PREV = prev;
    }
    node_free(remove);
}