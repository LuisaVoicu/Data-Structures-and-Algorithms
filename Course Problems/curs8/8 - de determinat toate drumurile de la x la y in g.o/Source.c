#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
typedef struct
{
    int n;
    int** m;
    int* p;
}Graf;

void citire(FILE* f, Graf* g)
{

    fscanf(f, "%d", &g->n);
    g->m = (int**)malloc(g->n * sizeof(int*));
    g->p = (int*)malloc(g->n * sizeof(int));
    for(int i = 0 ; i <g->n;i++)
    {
        g->m[i] = (int*)calloc(g->n, sizeof(int));
        g->p[i] = -1;
    }

    int v, w;
    
    while (fscanf(f, "%d %d", &v, &w) == 2)
    {
        g->m[v][w] = 1;
        
    }
}

void afis_lant(Graf g, int nod)
{
    if (nod != -1)
    {
        afis_lant(g, g.p[nod]);
        printf("%d -> ", nod);
    }
}
void bfs(Graf g, int start, int stop)
{
    int* vizita = (int*)calloc(g.n, sizeof(int));
    int* parinti = (int*)calloc(g.n, sizeof(int));
    int n = 0;
    enqueue(start);
    vizita[start] = 1;

    while (!empty())
    {
        int v = dequeue();
       
        for (int i = 0; i < g.n; i++)
        {
            if (i == stop && g.m[v][i])
            {
                parinti[n++] = v;
            }
            else 
                if (g.m[v][i] && !vizita[i])
                {  
                    enqueue(i);
                    vizita[i] = 1;
                    g.p[i] = v;
                }
        }
    }

    printf("Exista %d drumuri :\n", n);
    for (int i = 0; i < n; i++)
    {
        
        afis_lant(g,parinti[i]);
        printf("%d\n", stop);
        

    }
    free(parinti);
}
int main()
{
    FILE* f = fopen("file.txt", "r");
    
    Graf g; 
    citire(f,&g);
    fclose(f);
    bfs(g, 0, 5);
}