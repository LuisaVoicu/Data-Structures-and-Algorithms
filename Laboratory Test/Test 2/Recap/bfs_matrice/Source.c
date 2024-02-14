#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int key;
    struct list* next;
}NodeT;


// coada => insert last si delete frist

NodeT* create(int key)
{
    NodeT* nod = (NodeT*)malloc(sizeof(NodeT));
    nod->key = key;
    nod->next = NULL;
    return nod;
}


void insert_last(NodeT** first, NodeT** last, int key)
{
    NodeT* node = create(key);

    if (*first == NULL)
    {
        *first = *last = node;
        return;
    }
    (*last)->next = node;
    *last = node;

}

int delete_first(NodeT** first, NodeT** last)
{
    NodeT* deleted = *first;
    int del = deleted->key;
    if (*first == *last)
    {
        *first = *last = NULL;
        free(deleted);
        return del;
    }
    *first = (*first)->next;
    free(deleted);
    return del;
}

int empty(NodeT* l)
{
    if (l == NULL)
    {
        return 1;
    }
    return 0;
}

typedef struct
{
    int n;
    int* visit;
    int** adiacenta;
    int* color;

}graf;
enum{RED,GREEN};

void citeste(FILE* f, graf* g)
{
    fscanf(f, "%d", &g->n);
    g->adiacenta = (int**)calloc(g->n, sizeof(int*));
    g->color = (int*)calloc(g->n, sizeof(int));
    g->visit = (int*)calloc(g->n, sizeof(int));


    for (int i = 0; i < g->n; i++)
    {
        g->adiacenta[i] = (int*)calloc(g->n, sizeof(int));
    }

    int a, b;
    while (fscanf(f, "%d %d", &a, &b) == 2)
    {
        printf("%d %d\n", a, b);
        g->adiacenta[a][b] = g->adiacenta[b][a] = 1;
    }
}


int opposite(int a)
{
    if (a == GREEN)
        return RED;
    return GREEN;
}
int bfs(int ind, graf* g)
{
    NodeT* qf = NULL;
    NodeT* ql = NULL;
    int bipartit = 1;
    insert_last(&qf, &ql, ind);
    g->visit[ind] = 1;
    while (!empty(qf))
    {
        int nod = delete_first(&qf, &ql);
        printf("%d ", nod);
        for(int i=0;i<g->n;i++)
            if (g->adiacenta[i][nod] && !g->visit[i])
            {
                insert_last(&qf, &ql, i);
                g->visit[i] = 1;
                g->color[i] = opposite(g->color[nod]);
            }
            else if (g->adiacenta[i][nod] && g->visit[i])
            {
                if (g->color[i] == g->color[nod])
                {
                    bipartit = 0;
                }
            }
    }
    return bipartit;
}


void bfs_init( graf* g)
{
    for(int i=0;i<g->n;i++)
        if (g->visit[i] == NULL)
        {
            int bp = bfs(i,g);
            printf("\nbipartit: %d\n", bp);
        }

}


int main()
{
    FILE* f = fopen("file.txt", "r");
    graf g;
    citeste(f, &g);
    bfs_init(&g);
   
}