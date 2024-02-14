#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include "queue.h"
typedef struct 
{
    int** m;
    int n;
    int* p;
    int* d;
}Graf;

void citire(FILE* f, Graf* g)
{
    fscanf(f, "%d", &g->n);

    g->m = (int**)calloc(g->n, sizeof(int*));
    g->p = (int*)calloc(g->n, sizeof(int));
    g->d = (int*)calloc(g->n, sizeof(int));

    for (int i = 0; i < g->n; i++)
    {
        g->m[i] = (int*)calloc(g->n, sizeof(int));
    }

    int v, w;
    while (fscanf(f, "%d %d", &v, &w) == 2)
    {
        printf("%d %d\n", v, w);
        g->m[v][w] = g->m[w][v] = 1;
    }
}

void bfs(Graf g,int start,int stop)
{
    int* vizita = (int*)calloc(g.n, sizeof(int));

    enqueue(start);
    vizita[start] = 1;

    while (top() != stop && !empty())
    {
        int v = dequeue();

        for (int i = 0; i < g.n; i++)
        if(g.m[i][v] == 1 && !vizita[i]) 
        {
            enqueue(i);
            vizita[i] = 1;
            g.d[i] = g.d[v] + 1;
            g.p[i] = v;
        }
    }
}


void afisare_lant(Graf g,int k)
{
    if (k)
    {   
        printf("%d ", k);
        afisare_lant(g, g.p[k]);
    }
    else
    {
        printf("\n");
    }
}
int main()
{
    FILE* f = fopen("file.txt", "r");
    if (f == NULL)
    {
        exit(123);
    }

    Graf g;
    citire(f, &g);
    int start = 2;
    int stop = 6;

    bfs(g, start, stop);
    afisare_lant(g, stop);

}