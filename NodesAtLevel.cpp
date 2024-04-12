#include "Header.h"


int countNodesAtLevel(Tree* tree, int level, int currentLevel)
{
    if (tree == NULL) return 0;

    // ���� ������� ������� ������������� �������� ������, ���������� 1
    if (currentLevel == level) return 1;

    // ���������� ������������ ����� � ������ ���������� � ����������� ������ �� 1
    return countNodesAtLevel(tree->leftChild, level, currentLevel + 1) + countNodesAtLevel(tree->rightChild, level, currentLevel + 1);
}

// �� ����������� (����� ������ pre-order)
int �ountNodesAtLevel_not(Tree* root, int targetLevel)
{
    if (root == NULL) return 0;

    Stack* stack = NULL;
    PushFront(&stack, root, 0);             // ���������� ������ ������ � ���� � ������� 0.

    int count = 0;                          // ������������� �������� ����� �� ������� ������.


    while (stack != NULL)
    {
        Tree* node;
        int level;                          // ������� ���������� � ������ ������ ���� ������ 
        Pop(&stack, &node, &level);
        
        if (level == targetLevel)           // ���� ������� �������� ���� ����� �������� ������:
        {
            count++;                        // ����������� ������� ����� �� ������� ������.
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