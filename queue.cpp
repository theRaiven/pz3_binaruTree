#include "Header.h"

void PushBack(Queue** queue, char number)
{
    // Выделяем память для нового узла.
    Queue* new_node = new Queue;

    // Инициализируем поля нового узла.
    new_node->data = number;
    new_node->ptrNext = new_node;
    new_node->ptrPrev = new_node;

    // Если список пуст, делаем новый элемент головным узлом.
    if (*queue == NULL)
    {
        *queue = new_node;
        new_node->ptrNext = *queue;
        new_node->ptrPrev = *queue;
        return;
    }

    // Находим последний элемент списка.
    Queue* last_node = *queue;
    last_node = last_node->ptrPrev;

    // Вставляем новый элемент в конец списка.
    last_node->ptrNext = new_node;
    new_node->ptrPrev = last_node;
    new_node->ptrNext = *queue;
    (*queue)->ptrPrev = new_node;
}

int pop(Queue** queue, char* num)
{
    if ((*queue) != NULL)
    {
        *num = (*queue)->data;

        if ((*queue) == (*queue)->ptrNext)
        {
            (*queue) = NULL;
        }
        else
        {
            (*queue) = (*queue)->ptrNext;
            (*queue)->ptrPrev = (*queue)->ptrPrev->ptrPrev;
            (*queue)->ptrPrev->ptrNext = (*queue);
        }

        return 1;
    }
    else
    {
        return -1;
    }
}

bool Empty(Queue** queue)
{
    return *queue == NULL;

}