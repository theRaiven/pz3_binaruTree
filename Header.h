#pragma once
#pragma execution_character_set("utf-8")

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
int pop(Queue** queue, char* num);

// ����
struct Stack
{
    Tree* data;
    Stack* ptrNext;
    Stack* ptrPrev;

    int level;
};

void PushFront(Stack** stack, Tree* node, int level);
int Pop(Stack** stack, Tree** node, int* level);

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
int Output(Tree* tree, int& deep);

// �������� ������
int �ountNodesAtLevel_not(Tree* tree, int targetLevel); //  �� ����������
int countNodesAtLevel(Tree* tree, int level, int currentLevel); // ����������