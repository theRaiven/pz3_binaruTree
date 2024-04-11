#pragma once

#include <iostream>
#include <Windows.h>
using namespace std;

// Очередь
struct Queue
{
    char data;
    Queue* ptrNext;
    Queue* ptrPrev;
};

void PushBack(Queue** queue, char number);
int pop(Queue** queue, char* num);
bool Empty(Queue** queue);


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
int Output(Tree* tree, int& level);

// Основная задача
int countNodesAtLevel(Tree* tree, int level, int currentLevel);