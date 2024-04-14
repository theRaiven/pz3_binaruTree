#include "Header.h"

void PushFront(Stack** stack, Tree* node, int level)
{
    Stack* newNode = new Stack;
    newNode->data = node;
    newNode->level = level;

    if ((*stack) == NULL)
    {
        newNode->ptrNext = newNode;
        newNode->ptrPrev = newNode;
    }
    else
    {
        newNode->ptrNext = (*stack);
        newNode->ptrPrev = (*stack)->ptrPrev;
        (*stack)->ptrPrev->ptrNext = newNode;
        (*stack)->ptrPrev = newNode;
    }

    (*stack) = newNode;
}

int PopFrontStack(Stack** stack, Tree** node, int* level)
{
    if ((*stack) != NULL)
    {
        *node = (*stack)->data;
        *level = (*stack)->level;

        if ((*stack) == (*stack)->ptrNext)
        {
            (*stack) = NULL;
        }
        else
        {
            (*stack) = (*stack)->ptrNext;
            (*stack)->ptrPrev = (*stack)->ptrPrev->ptrPrev;
            (*stack)->ptrPrev->ptrNext = (*stack);
        }

        return 1;
    }
    else
    {
        return -1;
    }
}

