#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

typedef struct nod
{
    int key;
    struct nod* next;
}NodeT;

/// obs:la coada avem insert first si delete last

NodeT* create(int key)
{
    NodeT* node = (NodeT*)malloc(sizeof(NodeT));
    node->key = key;
    node->next = NULL;
    return node;
}

void insert_last(NodeT** first, NodeT** last, int key)
{
    NodeT* nod = create(key);

    if (*first == NULL)
    {
        *first = *last = nod;
        return;
    }
    (*last)->next = nod;
    *last = nod;
}

void insert_first(NodeT** first, int key)
{
    NodeT* node = create(key);

    if (*first == NULL)
    {
        *first = node;
        return;
    }
    node->next = *first;
    *first = node;
}

int delete_first(NodeT** first, NodeT** last)
{
    if (*first == NULL)
        return -1;
    NodeT* deleted = *first;
    NodeT* del_key = (*first)->key;

    *first = (*first)->next;
    free(deleted);

    return del_key;
}

void print_list(NodeT* first)
{
    if (first == NULL)
        return;

    for (NodeT* p = first; p != NULL; p = p->next)
    {
        printf("%d ", p->key);
    }
    printf("\n");
}

int empty(NodeT* first)
{
    if (first == NULL)
        return 1;
    return 0;
}


typedef struct graf
{
    int n;
    int* vizita;
    int* distanta;
    int** mat;

}graf;

void citire_matrice(graf* g, FILE* f)
{
    fscanf(f, "%d", &g->n);
    int a, b;
    g->mat = (int**)calloc(g->n, sizeof(int*));
    g->vizita = (int*)calloc(g->n, sizeof(int*));
    g->distanta = (int*)calloc(g->n, sizeof(int*));
    for (int i = 0; i < g->n; i++)
    {
        g->mat[i] = (int*)calloc(g->n, sizeof(int));
    }

    while (fscanf(f, "%d %d", &a, &b) == 2)
    {
        g->mat[a][b] = g->mat[b][a] = 1;
    }
}


void bfs(graf* g, int i)
{
    NodeT* qf = NULL;
    NodeT* ql = NULL;

    insert_last(&qf, &ql, i);
    g->vizita[i] = 1;
    while (!empty(qf))
    {
        int nod = delete_first(&qf, &ql);
        printf("%d ", nod);
        
        for (int i = 0; i < g->n; i++)
        if(g->mat[i][nod] && !g->vizita[i])
        {
            g->vizita[i] = 1;
            g->distanta[i] = 1 + g->distanta[nod];
            insert_last(&qf, &ql, i);
        }
    }
}


void bfs_vizit(graf* g)
{
    for (int i = 0; i < g->n; i++)
    if(g->vizita[i] == 0) 
    {
        bfs(g, i);
    }
    printf("\n%d\n", g->distanta[6]);
}
int main()
{
    graf g;
    FILE* f = fopen("file.txt", "r");
    citire_matrice(&g, f);
    bfs_vizit(&g);
}