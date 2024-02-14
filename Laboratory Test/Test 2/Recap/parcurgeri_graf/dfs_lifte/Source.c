#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct graf
{
    int n;
    int* pi;
    int* d;
    int* f;
    int* color;
    int** mat;
}graf;

enum {WHITE, GRAY, BLACK};

void citeste(graf* g, FILE* f)
{
    fscanf(f, "%d", &g->n);
    g->mat = (int**)calloc(g->n, sizeof(int*));
    g->color = (int*)calloc(g->n, sizeof(int));
    g->d = (int*)calloc(g->n, sizeof(int));
    g->f = (int*)calloc(g->n, sizeof(int));
    g->pi = (int*)calloc(g->n, sizeof(int));

    for (int i = 0; i < g->n; i++)
    {
        g->mat[i] = (int*)calloc(g->n, sizeof(int));
    }

    int a, b;
    while (fscanf(f, "%d %d", &a, &b) == 2)
    {
        g->mat[a][b] = g->mat[b][a] = 1;
    }

}

void dfs(graf* g, int index, int* cnt)
{

    printf("%d ", index);
    g->color[index] = GRAY;
    g->d[index] = ++(*cnt);
    for(int i=0;i<g->n;i++)
        if (g->mat[i][index] && g->color[i] == WHITE)
        {
            g->pi[i] = index;
            dfs(g, i, cnt);
        }
    g->f[index] = ++(*cnt);
    g->color[index] = BLACK;
}


void dfs_init(graf* g)
{
    int cnt;
    for (int i = 0; i < g->n; i++)
    {
        if (g->color[i] == WHITE)
        {
            cnt = 0;
            dfs(g, i, &cnt);
        }
    }

    printf("\n");
    for (int i = 0; i < g->n; i++)
    {
        printf("%d ", g->d[i]);
    }
    printf("\n");
    for (int i = 0; i < g->n; i++)
    {
        printf("%d ", g->f[i]);
    }
    printf("\n");

}

int main()
{
    FILE* f = fopen("file.txt", "r");
    graf g;
    citeste(&g, f);
    dfs_init(&g);
}
