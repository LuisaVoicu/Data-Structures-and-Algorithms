#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
typedef struct nod
{
    int key;
    struct nod* next;
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

typedef struct graf
{
    int n;
    List** t;
}Graf;
enum{NEVIZITAT,VIZITAT};

void citireGraf(FILE* f, Graf* GOr, Graf* GNeor)
{
    fscanf(f, "%d", &GOr->n);
    GNeor->n = GOr->n;
    GOr->t = (List**)calloc(GOr->n, sizeof(List*));
    GNeor->t = (List**)calloc(GNeor->n, sizeof(List*));

    for (int i = 0; i < GOr->n; i++)
    {
        GOr->t[i] = NULL;
        GNeor->t[i] = NULL;
    }

    int v, w;

    while (fscanf(f, "%d %d", &v, &w) == 2)
    {
        // graf neorientat:
        insert_first(&GNeor->t[v], w); // (v) -----> (W)
        insert_first(&GNeor->t[w], v); // (w) -----> (v)

        // graf orientat:
        insert_first(&GOr->t[v], w);
    }
}


void print_graph(Graf G)
{
    for (int i = 0; i < G.n; i++)
    if(G.t[i])
    {
        printf("%d : ",i);
        List* l = G.t[i];
        while (l != NULL)
        {
            printf("%d ", l->key);
            l = l->next;
        }
        printf("\n");
    }
}

void bfs(Graf G, int nodSursa)
{
    int* vizita;
    vizita = (int*)calloc(G.n, sizeof(int));

    for (int i = 0; i < G.n; i++)
    {
        vizita[i] = NEVIZITAT;
    }
    vizita[nodSursa] = VIZITAT;

    enqueue(nodSursa);

    while (!empty())
    {
        int v = dequeue();
        printf("%d ", v);
        List* l = G.t[v];
        while (l != NULL)
        {
            if (vizita[l->key] == NEVIZITAT)
            {
                vizita[l->key] = VIZITAT;
                enqueue(l->key);
            }
            l = l->next;
        }
    }
    printf("\n");
}

int main()
{
    FILE* f = fopen("file.txt", "r");
    Graf GO,GN;
    citireGraf(f, &GO,&GN);
    fclose(f);

    //printf("%d", G.n);
    printf("Lista dinamica de adiacenta a grafului NEORIENTAT:\n");
    print_graph(GN);

    printf("Lista dinamica de adiacenta a grafului ORIENTAT:\n");
    print_graph(GO);

    int nod;
    printf("Introduceti un nod: ");
    scanf("%d", &nod);

    printf("\nParcurgerea in latime a grafului NEORIENTAT:\n");
    bfs(GN, nod);

    printf("\nParcurgerea in latime a grafului ORIENTAT:\n");
    bfs(GO, nod);




}
