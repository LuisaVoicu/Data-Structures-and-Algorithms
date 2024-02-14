#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
typedef struct
{
    int n;
    int* t;
    int* liste;
}Graf;
enum {NEVIZITAT,VIZITAT};


void citesteGraf(FILE* f, Graf* G)
{
    fscanf(f, "%d", &G->n);

    G->t = (int*)calloc(G->n, sizeof(int));

    
    for (int i = 0; i < G->n; i++)
    {
        G->t[i] = -1;
    }

    G->liste = (int*)calloc(G->n * G->n, sizeof(int));
    
    int v, w;
    int ant;
    int count = 0;
    fscanf(f, "%d %d", &v, &w);
   
    G->t[v] = count;
    G->liste[count] = w;
    ant = v;
    while (fscanf(f, "%d %d", &v, &w) == 2)
    {
        //printf("%d %d\n", v, w);
        count++;
        if (ant != v)
        {
            G->liste[count] = -1;
            count++;
            G->t[v] = count;
        }
        G->liste[count] = w;
        ant = v;
    }
    G->liste[++count] = -1;
}

void print_graph(Graf G)
{
   
    
    printf("Tabloul de pozitii este:\n");
    for (int i = 0; i < G.n; i++)
    {
        printf("%d ", G.t[i]);
    }
    printf("\n\nLista statica de adiacenta (dar scrisa ca lista dinamica :) )  este  :\n");
    int i = 0;
    while (i < G.n)
    {
        if (G.t[i] == -1)
        {
            i++;
        }
        else
        {
            printf("%d : ", i);
            int j = G.t[i];
            while (G.liste[j] != -1)
            {
                printf("%d ", G.liste[j]);
                j++;
            }
            printf("\n");
            i++;
        }
    } 
    printf("\n");
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
        if (G.t[i]!=-1 )
        {
            int k = G.t[i];
            while(G.liste[k]!=-1)
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
    printf("Graf ORIENTAT\n\n");
    print_graph(G);
    

    printf("Introduceti un nod: ");
    int nod;
    scanf("%d", &nod);

    printf("Parcurgerea in latime pentru un graf ORIENTAT:\n");
    bfs(G, nod);

}