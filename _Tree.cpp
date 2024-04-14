#include "Header.h"


void TravelsePreorder(Tree* tree) 
{
    printf("Узел имеет значение: %c\n", tree->data);

    if (tree->leftChild != NULL)
    {
        TravelsePreorder(tree->leftChild);
    }
    if (tree->rightChild != NULL)
    {
        TravelsePreorder(tree->rightChild);
    }
}


Tree* CreateTree(Queue** queue)
{
    char node;

    PopFrontQueue(queue, &node);

    if (node == '(')
    {
        Tree* tree = new Tree;

        PopFrontQueue(queue, &node);

        tree->data = node;
        tree->leftChild = CreateTree(queue);
        tree->rightChild = CreateTree(queue);

        PopFrontQueue(queue, &node);

        return tree;
    }

    if (node == ',' || node == ' ')
    {
        return CreateTree(queue);
    }
    if (node == '0')
    {
        return NULL;
    }
}

