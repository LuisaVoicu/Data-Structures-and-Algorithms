#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct list
{
    int key;
    struct list* next;
}List;

void insert_first(List** l, int key)
{
    List* node = (List*)malloc(sizeof(List));
    node->key = key;
    node->next = NULL;
    if (l == NULL)
    {
        *l = node;
        return;
    }
    node->next = *l;
    *l = node;
}

typedef struct
{
    int n;
    int* height;
    List** t;
}Graf;
enum { NEVIZITAT, VIZITAT };

void citire(FILE* f, Graf* G)
{
    fscanf(f, "%d", &G->n);
    G->t = (List**)calloc(G->n, sizeof(List*));
    G->height = (int*)calloc(G->n, sizeof(int));

    for (int i = 0; i < G->n; i++)
    {
        G->t[i] = NULL;
    }

    int v, w;
    while (fscanf(f, "%d %d", &v, &w) == 2)
    {
        insert_first(&G->t[v], w);
        insert_first(&G->t[w], v);
    }
}



int bfs(Graf G, int nod1, int nod2)
{
    int* vizita = (int*)malloc(G.n * sizeof(int));
    for (int i = 0; i < G.n; i++)
    {
        vizita[i] = NEVIZITAT;
    }

    enqueue(nod1);
    vizita[nod1] = VIZITAT;
    G.height[nod1] = 0;
    while (!empty())
    {
        int v = dequeue();
        List* l = G.t[v];
        while (l != NULL)
        {
            if (vizita[l->key] == NEVIZITAT)
            {
                vizita[l->key] = VIZITAT;
                G.height[l->key] = G.height[v] + 1;
                enqueue(l->key);
            }
            l = l->next;
        }
    }
    return G.height[nod2];
}

void print_graph(Graf G)
{
    for (int i = 0; i < G.n; i++)
        if (G.t[i])
        {
            printf("%d : ", i);
            List* l = G.t[i];
            while (l != NULL)
            {
                printf("%d ", l->key);
                l = l->next;
            }
            printf("\n");
        }
}

int main()
{
    FILE* f = fopen("file.txt", "r");
    Graf G;
    citire(f, &G);
    fclose(f);


    int x = 1;
    int y = 6;
    int k = bfs(G, x, y);

    printf("distanta minima de la %d la %d este %d\n", x, y, k);
}