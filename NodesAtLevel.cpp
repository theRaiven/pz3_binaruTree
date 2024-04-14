#include "Header.h"


int CountNodesAtLevel(Tree* tree, int level, int currentLevel)
{
    if (tree == NULL) return 0;
    
    // Если текущий уровень соответствует целевому уровню, возвращаем 1
    if (currentLevel == level) return 1;

    // Рекурсивно обрабатываем левое и правое поддеревья с увеличением уровня на 1
    return CountNodesAtLevel(tree->leftChild, level, currentLevel + 1) + CountNodesAtLevel(tree->rightChild, level, currentLevel + 1);
}

// Не рекурсивный (метод обхода pre-order)
int CountNodesAtLevel_not(Tree* tree, int targetLevel)
{
    if (tree == NULL) return 0;

    Stack* stack = NULL;
    PushFront(&stack, tree, 0);             // Добавление корень дерева в стек с уровнем 0.

    int countNodes = 0;                          // Инициализация счетчика узлов на целевом уровне.


    while (stack != NULL)
    {
        Tree* node; 
        int level;                          // уровень изымаемого в данный момент узла дерева 

        PopFrontStack(&stack, &node, &level);
       // printf("Узел имеет значение: %c\n", node->data);

        if (level == targetLevel)           // Если уровень текущего узла равен искомому уровню:
        {
            countNodes++;                        // Увеличиваем счетчик узлов на целевом уровне.
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

    return countNodes;
}

