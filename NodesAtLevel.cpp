#include "Header.h"


int CountNodesAtLevel(Tree* tree, int level, int currentLevel)
{
    if (tree == NULL) return 0;
    
    // ���� ������� ������� ������������� �������� ������, ���������� 1
    if (currentLevel == level) return 1;

    // ���������� ������������ ����� � ������ ���������� � ����������� ������ �� 1
    return CountNodesAtLevel(tree->leftChild, level, currentLevel + 1) + CountNodesAtLevel(tree->rightChild, level, currentLevel + 1);
}

// �� ����������� (����� ������ pre-order)
int CountNodesAtLevel_not(Tree* tree, int targetLevel)
{
    if (tree == NULL) return 0;

    Stack* stack = NULL;
    PushFront(&stack, tree, 0);             // ���������� ������ ������ � ���� � ������� 0.

    int countNodes = 0;                          // ������������� �������� ����� �� ������� ������.


    while (stack != NULL)
    {
        Tree* node; 
        int level;                          // ������� ���������� � ������ ������ ���� ������ 

        PopFrontStack(&stack, &node, &level);
       // printf("���� ����� ��������: %c\n", node->data);

        if (level == targetLevel)           // ���� ������� �������� ���� ����� �������� ������:
        {
            countNodes++;                        // ����������� ������� ����� �� ������� ������.
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

