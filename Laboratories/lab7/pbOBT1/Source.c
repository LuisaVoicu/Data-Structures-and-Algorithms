#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct lista
{
    int key;
    struct lista* next;
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
    List** t;
}Graf;

enum{NEVIZITAT,VIZITAT};

void citire(FILE* f, Graf* G)
{
    fscanf(f,"%d",&G->n);
    G->t = (List**)calloc(G->n, sizeof(List*));

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

int conectate(Graf G, int nodSursa, int nodCautat)
{
    int* vizita = (int*)malloc(sizeof(int) * G.n);
    
    for (int i = 0; i < G.n; i++)
    {
        vizita[i] = NEVIZITAT;
    }

    enqueue(nodSursa);
    vizita[nodSursa] = VIZITAT;

    while (!empty())
    {
        int v = dequeue();

        List* l = G.t[v];
        
        while (l != NULL)
        {
            if (vizita[l->key] == NEVIZITAT)
            {
                vizita[l->key] = VIZITAT;
                if (l->key == nodCautat)
                {
                    return 1;
                }
                enqueue(l->key);
            }
            
            l = l->next;
        }
    }   
    return 0;

}

int main()
{
    FILE* f = fopen("file.txt", "r");
    Graf G;
    citire(f, &G);
    fclose(f);

    int x = 3;
    int y = 8;
    int r = conectate(G, x, y);\

    if (r == 0)
    {
        printf("%d si %d NU sunt conectate\n",x, y);
    }
    else
    {
        printf("%d si %d sunt conectate\n", x, y);
    }
    
}