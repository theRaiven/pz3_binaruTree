#include "Header.h"


int CountNodesAtLevel(Tree* tree, int level, int currentLevel)
{
    if (tree == NULL) return 0;
    
    // ≈сли текущий уровень соответствует целевому уровню, возвращаем 1
    if (currentLevel == level) return 1;

    // –екурсивно обрабатываем левое и правое поддеревь€ с увеличением уровн€ на 1
    return CountNodesAtLevel(tree->leftChild, level, currentLevel + 1) + CountNodesAtLevel(tree->rightChild, level, currentLevel + 1);
}

// Ќе рекурсивный (метод обхода pre-order)
int CountNodesAtLevel_not(Tree* tree, int targetLevel)
{
    if (tree == NULL) return 0;

    Stack* stack = NULL;
    PushFront(&stack, tree, 0);             // ƒобавление корень дерева в стек с уровнем 0.

    int countNodes = 0;                          // »нициализаци€ счетчика узлов на целевом уровне.


    while (stack != NULL)
    {
        Tree* node; 
        int level;                          // уровень изымаемого в данный момент узла дерева 

        PopFrontStack(&stack, &node, &level);
       // printf("”зел имеет значение: %c\n", node->data);

        if (level == targetLevel)           // ≈сли уровень текущего узла равен искомому уровню:
        {
            countNodes++;                        // ”величиваем счетчик узлов на целевом уровне.
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

