#pragma once

#include <iostream>
#include <Windows.h>
using namespace std;

// �������
struct Queue
{
    char data;
    Queue* ptrNext;
    Queue* ptrPrev;
};

void PushBack(Queue** queue, char number);
int pop(Queue** queue, char* num);
bool Empty(Queue** queue);


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
int Output(Tree* tree, int& level);

// �������� ������
int countNodesAtLevel(Tree* tree, int level, int currentLevel);