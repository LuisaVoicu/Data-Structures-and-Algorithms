#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* f = fopen("file.txt", "r");
    
    int n, m;
    fscanf(f, "%d %d", &n, &m);
    printf("%d %d\n", n, m);
    int maze[100][100];

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            fscanf(f, "%d", &maze[i][j]);
            printf("%d ", maze[i][j]);
        }

        printf("\n");
    }
}