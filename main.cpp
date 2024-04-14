// pz3_binaruTree.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Header.h"


int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    Tree* tree = NULL;
    int level = 0;
    int numberOfNodesOnLevel;

    Input(&tree, level);
    TravelsePreorder(tree);

    numberOfNodesOnLevel = CountNodesAtLevel_not(tree, level);
    
    Output(tree, level, numberOfNodesOnLevel);
}

