// pz3_binaruTree.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Header.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    Tree* tree = NULL;
    int level = 0;
    int numberOfNodesOnLevel;

    Input(&tree, level);
    TravelsePreorder(tree);

    numberOfNodesOnLevel = CountNodesAtLevel_not(tree, level);
    
    Output(tree, level, numberOfNodesOnLevel);
}

