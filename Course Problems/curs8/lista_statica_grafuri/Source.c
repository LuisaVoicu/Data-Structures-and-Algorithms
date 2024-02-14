#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int n;
    int* t;
    int* liste;
}Graf;
enum { NEVIZITAT, VIZITAT };


void citesteGraf(FILE* f, Graf* GO)
{
    fscanf(f, "%d", &GO->n);

    GO->t = (int*)calloc(GO->n, sizeof(int));


    for (int i = 0; i < GO->n; i++)
    {
        GO->t[i] = -1;
    }

    GO->liste = (int*)calloc(GO->n * GO->n, sizeof(int));

    for (int i = 0; i < GO->n*GO->n; i++)
    {
        GO->liste[i] = -1;
    }
    int v, w;
    int count = -1;
    while (fscanf(f, "%d %d", &v, &w) == 2)
    {
        // graf orientat
        count++;
        GO->t[v] = count;
        GO->liste[GO->t[v]] = w;
    }

    for (int i = 0; i < GO->n; i++)
    {
        printf("%d ", GO->t[i]);
    }  
    printf("\n");
    for (int i = 0; i < GO->n* GO->n; i++)
    {
        printf("%d ", GO->liste[i]);
    }

}

int main()
{
    FILE* f = fopen("file.txt", "r");

    Graf G;
    citesteGraf(f, &G);
}