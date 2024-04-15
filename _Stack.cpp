#include "Header.h"

void PushFront(Stack** stack, TreeAndLevel* node)
{
    Stack* newNode = new Stack;

    newNode->treeAndLevel.data = node->data;
    newNode->treeAndLevel.level = node->level;

    newNode->ptrNext = *stack;

    *stack = newNode;
}

int PopFrontStack(Stack** stack, TreeAndLevel* node)
{
    if (*stack == NULL)
    {
        return -1; 
    }

    (node)->data = (*stack)->treeAndLevel.data;
    (node)->level = (*stack)->treeAndLevel.level;
    
    Stack* temp = *stack;
    (*stack) = (*stack)->ptrNext;

    delete temp;
}

