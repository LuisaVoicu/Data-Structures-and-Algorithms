#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int key;
    struct list* next;
}NodeT;

typedef struct
{
    int n;
    int* d;
    int* f;
    int* pi;
    int* color;
    NodeT** t;
}Graf;

enum {WHITE,GRAY,BLACK};

void insert(NodeT** list, int val)
{
    // inserare pe prima pozitie
    NodeT* node = (NodeT*)malloc(sizeof(NodeT));
    node->key = val;
    node->next = *list;
    *list = node;
}

void citireGraf(FILE* f, Graf* G)
{
    fscanf(f, "%d", &G->n);
    G->d = (int*)calloc(G->n, sizeof(int));
    G->f = (int*)calloc(G->n, sizeof(int));
    G->pi = (int*)calloc(G->n, sizeof(int));
    G->color = (int*)calloc(G->n, sizeof(int));
    G->t = (NodeT**)calloc(G->n, sizeof(NodeT*));


    for (int i = 0; i < G->n; i++)
    {
        G->t[i] = NULL;
        G->color[i] = WHITE;
        G->pi[i] = -1;

    }

    int v, w;
    while (fscanf(f, "%d %d", &v, &w) == 2)
    {
        insert(&G->t[v] , w);
    }
}


void afiseaza_ciclu(int v,int w, Graf G)
{

    if (v != w)
    {
        afiseaza_ciclu(G.pi[v], w, G);
        printf("%d <-> ", v);
    }
}

void dfs_visit(int v, Graf* g, int* time, int* found)
{   
    NodeT* lista = g->t[v];
    //printf("%d ", v);
    if (!(*found))
    {
        g->d[v] = ++(*time);
        g->color[v] = GRAY;
        
    }
    while (lista&&!(*found))
    {
       
        int w = lista->key;
        if (g->color[w] == WHITE)
        {
            g->pi[w] = v;
            dfs_visit(w, g,time, found);
        }
        else if (g->color[w] == GRAY)
        {
            // inchide un ciclu!
   
            *found = 1;
            printf("%d <-> ", w);
            afiseaza_ciclu(v,w,*g);
            printf("%d\n", w);
            break;
        }
        lista = lista->next;
    }
    g->f[v] = ++(*time);
    g->color[v] = BLACK;
}


void print(int* ar, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ar[i]);
    }
    printf("\n");
}
void dfs(Graf* g)
{
    int time = 0,found = 0;
    for (int i = 0; i < g->n; i++)
        if (g->color[i] == WHITE)
        {
            dfs_visit(i, g, &time, &found);
        }
}
int main()
{
    FILE* f = fopen("graf.txt", "r");
    if (f == NULL) {
        printf("eroare!\n");
        exit(1);
    }
    Graf G;

    citireGraf(f, &G);
    fclose(f);
    dfs(&G);

   // print(G.pi, G.n);
  //  print(G.d, G.n);

}