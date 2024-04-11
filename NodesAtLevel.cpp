#include "Header.h"


int countNodesAtLevel(Tree* tree, int level, int currentLevel)
{
    if (tree == nullptr) return 0;

    // ≈сли текущий уровень соответствует целевому уровню, возвращаем 1
    if (currentLevel == level) return 1;

    // –екурсивно обрабатываем левое и правое поддеревь€ с увеличением уровн€ на 1
    return countNodesAtLevel(tree->leftChild, level, currentLevel + 1) + countNodesAtLevel(tree->rightChild, level, currentLevel + 1);
}

