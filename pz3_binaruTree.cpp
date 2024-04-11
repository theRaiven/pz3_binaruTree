// pz3_binaruTree.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Header.h"


int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    Tree* tree = NULL;
    int deep = 0;
    Input(&tree, deep);
    TravelsePreorder(tree);
    Output(tree, deep);
}

