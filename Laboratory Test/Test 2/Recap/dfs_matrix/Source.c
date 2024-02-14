#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct gr
{
    int n;
    int* color;
    int* pi;
    int* d;
    int* f;
    int** adiacenta;
}graf;
enum { WHITE,GRAY,BLACK};

void citeste(FILE* f, graf* g)
{
    fscanf(f, "%d", &g->n);
    g->adiacenta = (int**)calloc(g->n, sizeof(int*));
    g->color = (int*)calloc(g->n, sizeof(int));
    g->d = (int*)calloc(g->n, sizeof(int));
    g->pi = (int*)calloc(g->n, sizeof(int));
    g->f = (int*)calloc(g->n, sizeof(int));
    
    for (int i = 0; i < g->n; i++)
    {
        g->adiacenta[i] = (int*)calloc(g->n, sizeof(int));
    }

    int a, b;
    while (fscanf(f, "%d %d",&a,&b) == 2)
    {
        printf("%d %d\n", a, b);
        g->adiacenta[a][b] = g->adiacenta[b][a] = 1;
    }

}


void dfs(int ind, graf* g, int* timer)
{

    g->color[ind] = GRAY;
    g->d[ind] = ++(*timer);
    printf("%d ", ind);
    for(int i=0;i<g->n;i++)
        if (g->adiacenta[ind][i] == 1 && g->color[i] == WHITE)
        {
            g->pi[i] = ind;
            dfs(i, g, timer);
        }
    g->color[ind] = BLACK;
    g->f[ind] = ++(*timer);

}

void dfs_init(graf* g)
{
    int timer = 0;
    for (int i = 0; i < g->n; i++)
    if(g->color[i] == WHITE) 
    {
        dfs(i, g,&timer);
    }
}

int main()
{
    FILE* f = fopen("file.txt", "r");
    graf g;
    citeste(f, &g);
    dfs_init(&g);
}
