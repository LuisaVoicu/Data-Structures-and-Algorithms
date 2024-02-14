#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


typedef struct graf
{
    int** m;
    int* dist;
    int* parent;
    int n;
}Graf;

enum { WHITE, RED, GREEN };
enum { NEVIZITAT, VIZITAT };


void citire(FILE* f, Graf* G)
{
    fscanf(f, "%d", &G->n);

    G->m = (int**)calloc(G->n, sizeof(int*));
    G->dist = (int*)malloc(G->n * sizeof(int));
    G->parent = (int*)malloc(G->n * sizeof(int));
    
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



int bfs(Graf G,int* culori, int start, int stop)
{
    int found = 0;
    int count = 0;
    int* vizita = (int*)calloc(G.n, sizeof(int));
    

    enqueue(start);
    vizita[start] = VIZITAT;
    
    while (!empty())
    {
        int v = dequeue();

        for(int i = 0 ; i < G.n ; i++)
            if (G.m[i][v] == 1 && vizita[i] == NEVIZITAT && culori[i] != WHITE)
            {
                
                if (i == stop && count > 1 && (G.dist[v] + 1) % 2 == 0) // -> ne asiguram ca ciclul are lungime impara
                {
    
                    G.dist[i] = G.dist[v] + 1;
                    G.parent[i] = v;
                    found = 1;
                    break;
                }
                else if(i != stop)
                {
                    G.dist[i] = G.dist[v] + 1;
                    G.parent[i] = v;
                    enqueue(i);
                    vizita[i] = VIZITAT;
                    count++;
                }
            }
    }

    return found;

}

void set_free(Graf G)
{
    // coada + valori din graf

    while (!empty())
    {
        dequeue();
    }

    for (int i = 0; i < G.n; i++)
    {
        G.dist[i] = 0;
        G.parent[i] = -1;
    }
}


void afisare_path(Graf G, int nod)
{
    // parcurgem subgraful "inapoi" pe parinti
    if (nod != -1)
    {
        printf("%d <-> ", nod);
        afisare_path(G, G.parent[nod]);
    }
}
void ciclu(Graf G,int* culori,int  nod)
{
    //cautam un vecin (colorat!->nu are sens sa parcurgem nodurile necolorate) ce se poate intoarce la nodul principal pe alt drum
    int found = 0;
    for(int i = 0 ; i < G.n; i++)
        if (G.m[i][nod] == 1 && culori[i] != WHITE)
        {
            set_free(G);
            
            found = bfs(G, culori, i, nod);
            if (found)
            {
                break;
            }
        }
    if (found == 1)
    {
        printf("\nUn ciclu de lungime impara este:\n");
        afisare_path(G, nod);
        printf("%d\n",nod);
    }
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

    while (bip && !empty())
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
    FILE* f = fopen("file.txt", "r");

    Graf G;
    citire(f, &G);

    // print_mat(G);
    bipartit(G, 0);
}