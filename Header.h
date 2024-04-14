#pragma once

#include <iostream>
#include <Windows.h>
using namespace std;

struct Tree;

// Очередь
struct Queue
{
    char data;
    Queue* ptrNext;
    Queue* ptrPrev;
};

void PushBack(Queue** queue, char number);
int PopFrontQueue(Queue** queue, char* num);

// стек
struct Stack
{
    Tree* data;
    Stack* ptrNext;
    Stack* ptrPrev;

    int level;
};

void PushFront(Stack** stack, Tree* node, int level);
int PopFrontStack(Stack** stack, Tree** node, int* level);

// Дерево
struct Tree
{
	char data;
	Tree* leftChild;
	Tree* rightChild;
};

void TravelsePreorder(Tree* tree);
Tree* AddNode(Queue** queue);

// ввод-вывод
int Input(Tree** tree, int& deep);
int Output(Tree* tree, int& level, int& count);

// Основная задача
int CountNodesAtLevel_not(Tree* tree, int targetLevel); //  не рекурсивно
int CountNodesAtLevel(Tree* tree, int level, int currentLevel); // рекурсивно