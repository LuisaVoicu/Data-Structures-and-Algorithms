#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
typedef struct
{
    int n;
    int count;
    int* t;
    int* liste;
}Graf;
enum { NEVIZITAT, VIZITAT };



typedef struct
{
    int a, b;
}arc;

void citesteGraf(FILE* f, Graf* G)
{
    fscanf(f, "%d", &G->n);

    G->count = -1;
    G->t = (int*)calloc(G->n, sizeof(int));

    for (int i = 0; i < G->n; i++)
    {
        G->t[i] = -1;
    }

    G->liste = (int*)calloc(G->n * G->n, sizeof(int));


    int mx = (G->n * (G->n - 1)) / 2;
    int cnt = 0;
    arc* x = (arc*)malloc(sizeof(arc) * mx);

    while (fscanf(f, "%d %d", &x[cnt].a, &x[cnt].b) == 2)
    {
        cnt++;
    }

    G->t[0] = 0;
    for (int k = 0; k < G->n; k++)
    {
        int gasit = 0;
        for (int i = 0; i < cnt; i++)
        {

            if (x[i].a == k)
            {
                G->liste[++G->count] = x[i].b;
                gasit = 1;
            }
            if (x[i].b == k)
            {
                G->liste[++G->count] = x[i].a;
                gasit = 1;
            }
        }
        G->liste[++G->count] = -1;
        if (gasit)
        {
            G->t[k + 1] = G->count+1;
        }
        
    }

}


void print_graph(Graf G)
{


    printf("Tabloul de pozitii este:\n");
    for (int i = 0; i < G.n; i++)
    {
        printf("%d ", G.t[i]);
    }
    printf("\n\nLista statica de adiacenta este  :\n");
    int i = 0;
    for (int i = 0; i < G.n * G.n; i++)
    {
        printf("%d ", G.liste[i]);
    }
    printf("\n\n");
}


void bfs(Graf G, int nodSursa)
{
    int* vizita = (int*)calloc(G.n, sizeof(int));

    for (int i = 0; i < G.n; i++)
    {
        vizita[i] = NEVIZITAT;
    }
    vizita[nodSursa] = VIZITAT;

    enqueue(nodSursa);

    while (!empty())
    {
        int i = dequeue();
        printf("%d ", i);
        if (G.t[i] != -1)
        {
            int k = G.t[i];
            while (G.liste[k] != -1)
            {
                if (vizita[G.liste[k]] == NEVIZITAT)
                {
                    vizita[G.liste[k]] = VIZITAT;
                    enqueue(G.liste[k]);
                }
                k++;
            }
        }
    }
    printf("\n");
}

int main()
{
    FILE* f = fopen("file.txt", "r");

    Graf G;
    citesteGraf(f, &G);
    print_graph(G);

    printf("Parcurgerea in latime a grafului NEORIENTAT este : \n");
    bfs(G, 0);
}