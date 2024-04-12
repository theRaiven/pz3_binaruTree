#include "Header.h"

void TravelsePreorder(Tree* tree) 
{
    printf("\nУзел имеет значение: %c ", tree->data);

    if (tree->leftChild != NULL)
    {
        TravelsePreorder(tree->leftChild);
    }
    if (tree->rightChild != NULL)
    {
        TravelsePreorder(tree->rightChild);
    }
}


Tree* AddNode(Queue** queue)
{
    char node;

    pop(queue, &node);

    if (node == '(')
    {
        Tree* tree = new Tree;

        pop(queue, &node);

        tree->data = node;
        tree->leftChild = AddNode(queue);
        tree->rightChild = AddNode(queue);

        pop(queue, &node);

        return tree;
    }

    if (node == ',' || node == ' ')
    {
        return AddNode(queue);
    }
    if (node == '0')
    {
        return NULL;
    }

}