#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int di[8] = { -1,-1,-1,0,0,1,1,1 };
int dj[8] = { -1,0,1,-1,1,-1,0,1 };

int istop, jstop;
int istart, jstart;


int valid(int** mat, int n, int m, int i, int j)
{
    if (i < 0 || j < 0 || i >= n || j >= m)
        return 0;
    if (mat[i][j] == -1)//obst
        return 0;
    return 1;
}

void print_sol(int** mat, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void backtr(int** mat, int n, int m, int i, int j)
{printf("%d %d %d %d\n", i, j, istop,jstop);
    if (i == istop && j == jstop)
    {
        
        print_sol(mat, n, m);
        return;
    }
    for (int k = 0; k < 8; k++)
    {
        int inew = i + di[k];
        int jnew = j + dj[k];

        if (valid(mat, n, m, inew, jnew))
        {
            if (mat[inew][jnew] == 0 || mat[inew][jnew] > mat[i][j] + 1)
            {
                mat[inew][jnew] = mat[i][j] + 1;
                backtr(mat, n, m, inew, jnew);
            }
        }
    }
}

int main()
{
    FILE* f = fopen("file.txt", "r");
    
    int n, m;
    fscanf(f, "%d %d", &n, &m);
    int** mat = (int**)malloc((n ) * sizeof(int*));
    printf("%d %d\n", n, m);
    for (int i = 0; i < n; i++)
    {
        mat[i] = (int*)malloc((m ) * sizeof(int));
        for (int j = 0; j < m; j++)
        {
            fscanf(f, "%d", &mat[i][j]);
        }

    }

    fscanf(f, "%d %d %d %d", &istart, &jstart, &istop, &jstop);

    /*for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }*/


    backtr(mat, n, m, istart, jstart);
    printf("\n%d ", mat[istop][jstop]);
}