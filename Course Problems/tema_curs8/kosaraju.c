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
    int* f;
    int* d;
    int* color;
    int** t;
}Graf;

enum { WHITE, GRAY, BLACK };

void insert(NodeT** list, int val)
{
    // inserare pe prima pozitie
    NodeT* node = (NodeT*)malloc(sizeof(NodeT));
    node->key = val;
    node->next = *list;
    *list = node;
}

void citesteGraf(FILE* f, Graf* g, Graf* gt)
{
    fscanf(f, "%d", &g->n);
    g->t = (NodeT**)calloc(g->n, sizeof(NodeT*));
    gt->t = (NodeT**)calloc(g->n, sizeof(NodeT*));
    if (g->t == NULL)
    {
        printf("alocare esuata!\n");
        return;
    }
    g->d = (int*)calloc(g->n, sizeof(int));
    gt->d = (int*)calloc(g->n, sizeof(int));
    g->f = (int*)calloc(g->n, sizeof(int));
    gt->f = (int*)calloc(g->n, sizeof(int));
    g->color = (int*)calloc(g->n, sizeof(int));
    gt->color = (int*)calloc(g->n, sizeof(int));

    for (int i = 0; i < g->n; i++)
    {
        g->t[i] = NULL;
        gt->t[i] = NULL;
        g->color[i] = WHITE;
        gt->color[i] = WHITE;
        g->f[i] = -1;
        gt->f[i] = -1;
    }

    int v, w;
    while (fscanf(f, "%d %d", &v, &w) == 2)
    {
        insert(&g->t[v], w);
        insert(&gt->t[w], v);
    }
}

NodeT* top; // lista cu sortare topologica
int print;

void dfs_visit(int v, Graf* g, int* time )
{
    g->d[v] = ++(*time);
    g->color[v] = GRAY;
    if (print == 1)
    {
        printf("%d ", v);
    }
    NodeT* list = g->t[v];

    while (list != NULL)
    {
        int w = list->key;
        if (g->color[w] == WHITE) 
        {
            dfs_visit(w, g, time,top);
        }
        list = list->next;
    }
    g->color[v] = BLACK;
    g->f[v] = ++(*time);
    insert(&top, v);
}

void dfs(Graf* G)
{

    int time = -1;

    for (int i = 0; i < G->n; i++) 
    {
        if (G->color[i] == WHITE)
        {
            dfs_visit(i, G, &time,top);
        }
    }
}

void dfs_transp(Graf* Gt)
{
    int time = -1;
    int count = 0;
    NodeT* list = top;
    print = 1; // afisam elem fiecarei comp tare conexe
    while (list != NULL)
    {
        
        if (Gt->color[list->key] == WHITE)
        {
            ++count;
            printf("\n\nElementele componentei %d sunt: \n", count);
            dfs_visit(list->key, Gt, &time);
        }
        list = list->next;
    }
}


void free_mem(Graf* G)
{
    free(G->color);
    free(G->d);
    free(G->f);

    int i;
    for (i = 0; i < G->n; i++)
    {
        free(G->t[i]);
    }

    free(G->t);
}

int main()
{
    FILE* f = fopen("file.txt", "r");
    if (f == NULL) {
        printf("eroare!\n");
        exit(1);
    }
    Graf G, Gt;
    citesteGraf(f, &G, &Gt);
    fclose(f);

    dfs(&G); 
    dfs_transp(&Gt);
    printf("\n");

    free_mem(&G);
    free_mem(&Gt);
}