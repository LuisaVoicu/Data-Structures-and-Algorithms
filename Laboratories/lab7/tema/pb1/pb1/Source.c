#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int n;
    int** m;
}Graf;
enum{NEVIZITAT,VIZITAT};


void citesteGraf(FILE* f, Graf* GOr, Graf* GNeor)
{
    fscanf(f, "%d", &GOr->n);

    GOr->m = (int**)calloc(GOr->n, sizeof(int*));
    GNeor->m = (int**)calloc(GOr->n, sizeof(int*));
    GNeor->n = GOr->n;

    for (int i = 0; i < GOr->n; i++)
    {
        GOr->m[i] = (int*)calloc(GOr->n,sizeof(int));
        GNeor->m[i] = (int*)calloc(GNeor->n,sizeof(int));
    }

    int v, w;
    while (fscanf(f, "%d %d", &v, &w) == 2)
    { 
        GNeor->m[v][w] = GNeor->m[w][v] = 1; // pentru graf orientat
        GOr->m[v][w] = 1; // pentru graf orientat
    }
}


void printMatAdiacenta(Graf G)
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
        int nodNou = dequeue();
        printf("%d ", nodNou);
        for (int j = 0; j < G.n; j++)
        {
            if (G.m[nodNou][j] == 1 && vizita[j] == NEVIZITAT)
            {
                vizita[j] = VIZITAT;
                enqueue(j);
            }
        }
    }
    printf("\n");
}


int main()
{
    FILE* f = fopen("file.txt", "r");

    Graf GO,GN;
    citesteGraf(f, &GO,&GN);
    fclose(f);


    printf("Matricea de adiacenta a grafului NEORIENTAT: \n");
    printMatAdiacenta(GN);
    
    printf("Matricea de adiacenta a grafului ORIENTAT: \n");
    printMatAdiacenta(GO);

    
    printf("\nIntroduceti un nod: ");
    int nod;
    scanf("%d", &nod);

    printf("\nParcurgere in latime pentru graful NEORIENTAT:\n");
    bfs(GN, nod);

    printf("\nParcurgere in latime pentru graful ORIENTAT:\n");
    bfs(GO, nod);




}