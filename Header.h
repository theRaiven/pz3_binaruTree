#pragma once

#include <iostream>
#include <Windows.h>
using namespace std;

struct Tree;

// �������
struct Queue
{
    char data;
    Queue* ptrNext;
    Queue* ptrPrev;
};

void PushBack(Queue** queue, char number);
int PopFrontQueue(Queue** queue, char* num);

// ����
struct Stack
{
    Tree* data;
    Stack* ptrNext;
    Stack* ptrPrev;

    int level;
};

void PushFront(Stack** stack, Tree* node, int level);
int PopFrontStack(Stack** stack, Tree** node, int* level);

// ������
struct Tree
{
	char data;
	Tree* leftChild;
	Tree* rightChild;
};

void TravelsePreorder(Tree* tree);
Tree* AddNode(Queue** queue);

// ����-�����
int Input(Tree** tree, int& deep);
int Output(Tree* tree, int& level, int& count);

// �������� ������
int CountNodesAtLevel_not(Tree* tree, int targetLevel); //  �� ����������
int CountNodesAtLevel(Tree* tree, int level, int currentLevel); // ����������