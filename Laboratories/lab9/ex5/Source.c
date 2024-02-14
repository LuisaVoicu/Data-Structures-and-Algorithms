#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int di[4] = { -1,1,0,0 };
int dj[4] = { 0,0,-1,1 };



void print_maze(int maze[100][100], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int valid(int maze[100][100], int ni, int nj, int n, int m)
{
    if (ni < 0 || nj < 0 || ni >= n || nj >= m)
    {
        return -1;
    }
    if (maze[ni][nj] == -1 || maze[ni][nj] != 0)
    {
        return -1;
    }
    return 1;
}
void backtr_maze(int maze[100][100], int i, int j, int sti, int stj, int* cnt, int n, int m)
{
    if (i == sti && j == stj)
    {
        printf("gasit!\n");
        print_maze(maze, n, m);
        (*cnt)++;
        return;
    }

    for (int k = 0; k < 4; k++)
    {
        int ni = i + di[k];
        int nj = j + dj[k];
       // printf("%d %d\n", ni, nj);
        if (valid(maze, ni, nj, n, m) == 1)
        {
            printf("%d %d..\n", ni, nj);
            maze[ni][nj] = maze[i][j] + 1;
            backtr_maze(maze, ni, nj, sti, stj, cnt, n, m);
        }
    }
}

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

    int starti, startj,stopi, stopj;
    fscanf(f, "%d %d %d %d", &starti, &startj, &stopi, &stopj);

    int cnt = 5;
    maze[starti][startj] = 1;
    backtr_maze(maze, starti, startj, stopi, stopj,&cnt, n, m);
    

}