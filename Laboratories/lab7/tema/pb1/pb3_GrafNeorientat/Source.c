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
    printf("%d\n", G->n);

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
        
        //printf("%d %d\n", x[cnt].a, x[cnt].b);
        cnt++;
        
    }

    G->t[0] = 0;
    for (int k = 0; k < G->n; k++)
    {
        int gasit = 0;
        for (int i = 0; i < cnt; i++)
        {
            
            if (x[i].a == k)
            {printf("%d : %d %d\n",k,x[i].a, x[i].b);
                G->liste[++G->count] = x[i].b;
                gasit = 1;
            }
            if (x[i].b == k)
            {
                printf("%d : %d %d\n", k, x[i].a, x[i].b);
                G->liste[++G->count] = x[i].b;
                gasit = 1;
            }
        }
        G->liste[++G->count] = -1;
       if(gasit) G->t[k+1] = G->count;
       // break;
    }

    for (int i = 0; i < G->n; i++)
    {
        printf("%d ", G->t[i]);
    }
    printf("\n");


}

int main()
{
    FILE* f = fopen("file.txt", "r");

    Graf G;
    citesteGraf(f, &G);

}