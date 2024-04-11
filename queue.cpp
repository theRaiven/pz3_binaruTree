#include "Header.h"

void PushBack(Queue** queue, char number)
{
    // �������� ������ ��� ������ ����.
    Queue* new_node = new Queue;

    // �������������� ���� ������ ����.
    new_node->data = number;
    new_node->ptrNext = new_node;
    new_node->ptrPrev = new_node;

    // ���� ������ ����, ������ ����� ������� �������� �����.
    if (*queue == NULL)
    {
        *queue = new_node;
        new_node->ptrNext = *queue;
        new_node->ptrPrev = *queue;
        return;
    }

    // ������� ��������� ������� ������.
    Queue* last_node = *queue;
    last_node = last_node->ptrPrev;

    // ��������� ����� ������� � ����� ������.
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