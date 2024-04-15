#include "Header.h"

int CountNodesAtLevel_not(Tree* tree, int targetLevel)
{
    if (tree == NULL) return 0;

    TreeAndLevel node;

    node.data = tree;
    node.level = 0;

    Stack* stack = NULL;
    PushFront(&stack, &node);             // Добавление корень дерева в стек с уровнем 0.

    int countNodes = 0;                          // Инициализация счетчика узлов на целевом уровне.


    while (stack != NULL)
    {

        PopFrontStack(&stack, &node);

        if (node.level == targetLevel)           // Если уровень текущего узла равен искомому уровню:
        {
            countNodes++;                        // Увеличиваем счетчик узлов на целевом уровне.
        }

        // Добавляем левого потомка текущего узла в стек, если он существует и его уровень меньше или равен целевому уровню.
        if (node.data->leftChild != NULL && node.level <= targetLevel)
        {
            TreeAndLevel temp = node;
            temp.data = temp.data->leftChild;
            temp.level += 1;
            PushFront(&stack, &temp);
        }

        // Добавляем правого потомка текущего узла в стек, если он существует и его уровень меньше или равен целевому уровню.
        if (node.data->rightChild != NULL && node.level <= targetLevel)
        {
            TreeAndLevel temp = node;
            temp.data = temp.data->rightChild;
            temp.level += 1;
            PushFront(&stack, &temp);
        }
    }

    return countNodes;
}

