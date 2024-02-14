#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"
typedef struct graf
{
    int** m;
    int* dist;
    int n;
}Graf;

enum {WHITE,RED,GREEN};
enum {NEVIZITAT,VIZITAT};

void citire(FILE* f, Graf* G)
{
    fscanf(f, "%d", &G->n);
 
    G->m = (int**)calloc(G->n, sizeof(int*));
    G->dist = (int*)calloc(G->n, sizeof(int));

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

void print_mat(Graf G)
{
    for (int i = 0; i < G.n; i++)
    {
        for (int j = 0; j < G.n; j++)
        {
            printf("%d ", G.m[i][j]);
        }
        printf("\n");
    }
}


int drum(Graf G,int* culori, int start, int stop)
{
    int count=0;
    int* vizita = (int*)malloc(G.n * sizeof(int));
    for (int i = 0; i < G.n; i++)
    {
        vizita[i] = NEVIZITAT;
    }
    push(start);
    vizita[start] = VIZITAT;
    
    while (top() != stop && !emptys())
    {
        int v = pop();
        for (int i = 0; i < G.n; i++)
        if(G.m[i][v] == 1 && culori[i] != WHITE && vizita[i] == NEVIZITAT)
        {   
            
            if (i == stop && count > 1)
            {
                vizita[i] = VIZITAT;
                G.dist[i] = G.dist[v] + 1;
                push(i);
                break;
            }
            else if (i != stop)
            {
                vizita[i] = VIZITAT;
                G.dist[i] = G.dist[v] + 1;
                push(i);
                count++;
            }
        }
    }

    if (stop == top())
    {
        return 1;
    }
    return 0;
}
void ciclu(Graf G,int* culori, int nod)
{


    int gasit;
    int start;
    for (int k = 0; k < G.n; k++)
    {
        if (G.m[k][nod] == 1 && culori[k] != WHITE)
        {
            for (int i = 0; i < G.n; i++)
            {
              G.dist[i] = 0;
            }
            gasit = drum(G,culori, k, nod);
             // printf("distantaa %d\n", G.dist[nod]);
            // trebuie sa ne asiguram ca lungimea ciclului este impara ( adica distanta propriu-zisa e para)
            if (gasit == 1 && G.dist[nod] % 2 == 0)
            {
                start = k;
                break;
            }
        }
    }

    if (gasit == 1)
    {
        printf("\nCiclul de lungime impara este: \n\n");
        push(nod);
        int dst = G.dist[nod];
        while (!emptys())
        {
            int v = pop();
            printf("%d <-> ", v);
            if (v == start)
            {
                break;
            }

            for (int i = 0; i < G.n; i++)
                if (G.m[i][v] == 1 && G.dist[i] + 1 == G.dist[v])
                {
                    push(i);
                    break;
                }
        }
        printf("%d\n",nod);
    }
    return gasit;
}

int bipartit(Graf G, int start)
{
    int* culoare = (int*)malloc(G.n * sizeof(int));
    int bip = 1;
    int nod;

    for (int i = 0; i < G.n; i++)
    {
        culoare[i] = WHITE;
    }

    enqueue(start);
    culoare[start] = RED;

    while (!empty())
    {
        int v = dequeue();
        for (int j = 0; j < G.n; j++)
            if (G.m[v][j] == 1)
            {
                if (culoare[j] == WHITE)
                {
                    culoare[j] = RED;
                    if (culoare[v] == RED)
                    {
                        culoare[j] = GREEN;
                    }
                    enqueue(j);
                }
                else
                {
                    int corect = RED;
                    if (culoare[v] == RED)
                    {
                        corect = GREEN;
                    }
                    if (culoare[j] != corect)
                    {
                        bip = 0;
                        nod = j;
                        break;// nu e bipartit => are un ciclu de lungime impara
                    }
                }

            }    
    }

    if (bip == 0)
    {
        printf("Graful NU este bipartit!\n");
        ciclu(G, culoare,nod);
    }
    else
    {
        printf("Graful este bipartit!\n");
    }
    return bip;
}

int main()
{
    FILE* f = fopen("file.txt","r");

    Graf G;
    citire(f, &G);

   // print_mat(G);
    bipartit(G, 0);
}