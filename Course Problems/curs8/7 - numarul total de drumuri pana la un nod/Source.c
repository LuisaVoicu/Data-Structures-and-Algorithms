#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
typedef struct graf
{
    int** m;
    int* dist;
    int* nrdrum;
    int n;
}Graf;
enum { NEVIZITAT, VIZITAT };

void citire(FILE* f, Graf* G)
{
    fscanf(f, "%d", &G->n);

    G->m = (int**)calloc(G->n, sizeof(int*));
    G->dist = (int*)calloc(G->n, sizeof(int));
    G->nrdrum = (int*)calloc(G->n, sizeof(int));

    for (int i = 0; i < G->n; i++)
    {
        // G->cnt[i] = 0;
        G->m[i] = (int*)calloc(G->n, sizeof(int));
    }

    int v, w;

    while (fscanf(f, "%d %d", &v, &w) == 2)
    {
        //printf("%d %d\n", v, w);
        G->m[v][w] = 1;
        G->m[w][v] = 1;
    }
}

void bfs(Graf G, int start)
{
    int* vizita = (int*)calloc(G.n, sizeof(int));
    vizita[start] = VIZITAT;
    enqueue(start);

    while (!empty())
    {
        int v = dequeue();

        for(int i = 0 ; i < G.n ; i++)
            if (G.m[i][v] == 1)
            {
                if (vizita[i] == NEVIZITAT)
                {
                    enqueue(i);
                    vizita[i] = VIZITAT;
                    G.dist[i] = G.dist[v] + 1;
                }

                if (G.dist[v] + 1 == G.dist[i])
                {
                    G.nrdrum[i]++;
                }
            }
    }
}

int main()
{
    FILE* f = fopen("file.txt", "r");

    Graf G;
    citire(f, &G);

    int start = 0;
    bfs(G, start);

    for (int i = 0; i < G.n; i++)
    {
        printf("%d : %d %d\n", i, G.dist[i], G.nrdrum[i]);
    }
   
}