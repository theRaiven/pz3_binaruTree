#include "Header.h"

int Input(Tree** tree, int& deep)
{
    char nodename = 0;
    Queue* queue = NULL;
    FILE* fileTree;
    FILE* fileLevel;


    fopen_s(&fileTree, "Test.txt", "r");
    fopen_s(&fileLevel, "level.txt", "r");

    if (fileTree != NULL && fileLevel != NULL)
    {
        if (!feof(fileLevel))
        {
            fscanf_s(fileLevel, "%d", &deep);
        }

        while (!feof(fileTree))
        {
            fscanf_s(fileTree, "%c", &nodename, 1);
            PushBack(&queue, nodename);
        }

        *tree = AddNode(&queue);
    }
    else
    {
        printf_s("Could not open file result.txt\n");
        exit(0);
    }

    fclose(fileLevel);
    fclose(fileTree);
}



int Output(Tree* tree, int& level)
{
    FILE* resFile;

    int currentLevel = 0;

    fopen_s(&resFile, "result.txt", "w+");

    if (resFile != NULL)
    {
        
        printf("\nКоличество вершин на уровне %d: %d", level,  countNodesAtLevel( tree, level, 0));
        fprintf(resFile, "Количество вершин на уровне % d: % d\n", level, countNodesAtLevel(tree, level, 0));
        
    }
    else
    {
        exit(0);
    }

    fclose(resFile);

    return 0;
}
