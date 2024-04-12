#include "Header.h"


int countNodesAtLevel(Tree* tree, int level, int currentLevel)
{
    if (tree == NULL) return 0;

    // Если текущий уровень соответствует целевому уровню, возвращаем 1
    if (currentLevel == level) return 1;

    // Рекурсивно обрабатываем левое и правое поддеревья с увеличением уровня на 1
    return countNodesAtLevel(tree->leftChild, level, currentLevel + 1) + countNodesAtLevel(tree->rightChild, level, currentLevel + 1);
}

// Не рекурсивный (метод обхода pre-order)
int сountNodesAtLevel_not(Tree* root, int targetLevel)
{
    if (root == NULL) return 0;

    Stack* stack = NULL;
    PushFront(&stack, root, 0);             // Добавление корень дерева в стек с уровнем 0.

    int count = 0;                          // Инициализация счетчика узлов на целевом уровне.


    while (stack != NULL)
    {
        Tree* node;
        int level;                          // уровень изымаемого в данный момент узла дерева 
        Pop(&stack, &node, &level);
        
        if (level == targetLevel)           // Если уровень текущего узла равен искомому уровню:
        {
            count++;                        // Увеличиваем счетчик узлов на целевом уровне.
        }

        if (node->leftChild != NULL && level <= targetLevel)
        {
            PushFront(&stack, node->leftChild, level + 1);
        }
        if (node->rightChild != NULL && level <= targetLevel)
        {
            PushFront(&stack, node->rightChild, level + 1);
        }
        
        
    }

    return count;
}