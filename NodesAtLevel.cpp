#include "Header.h"


int countNodesAtLevel(Tree* tree, int level, int currentLevel)
{
    if (tree == nullptr) return 0;

    // ���� ������� ������� ������������� �������� ������, ���������� 1
    if (currentLevel == level) return 1;

    // ���������� ������������ ����� � ������ ���������� � ����������� ������ �� 1
    return countNodesAtLevel(tree->leftChild, level, currentLevel + 1) + countNodesAtLevel(tree->rightChild, level, currentLevel + 1);
}

