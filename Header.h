#pragma once

#include <iostream>

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
struct TreeAndLevel
{
    Tree* data;
    int level;
};

struct Stack
{
    TreeAndLevel treeAndLevel;
    Stack* ptrNext;
};

void PushFront(Stack** stack, TreeAndLevel* treeAndLevel);
int PopFrontStack(Stack** stack, TreeAndLevel* treeAndLevel);

// Дерево
struct Tree
{
	char data;
	Tree* leftChild;
	Tree* rightChild;
};

void TravelsePreorder(Tree* tree);
Tree* CreateTree(Queue** queue);

// ввод-вывод
int Input(Tree** tree, int& deep);
int Output(Tree* tree, int& level, int& count);

// Основная задача
int CountNodesAtLevel_not(Tree* tree, int targetLevel); //  не рекурсивно
