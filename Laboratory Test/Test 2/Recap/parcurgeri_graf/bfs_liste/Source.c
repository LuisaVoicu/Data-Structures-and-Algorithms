#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
// bfs ->coada
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

void insert_last(NodeT** first, NodeT**last, int key )
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
    int* visit;
    NodeT** adiacenta;
}graf;



void read_graph(graf* g, FILE*f)
{
    fscanf(f, "%d", &g->n);


    g->adiacenta = (NodeT**)malloc(g->n * sizeof(NodeT*));
    g->visit = (int*)calloc(g->n, sizeof(int));
    for (int i = 0; i < g->n; i++)
    {
        g->adiacenta[i] = NULL;
    }


    int a, b;
    while(fscanf(f, "%d %d", &a, &b) == 2)
    {
        insert_first(&g->adiacenta[a], b);
        insert_first(&g->adiacenta[b], a);
    }
}



void bfs(graf* g, int nod)
{
    NodeT* qf = NULL;
    NodeT* ql = NULL;
    insert_last(&qf, &ql, nod);
    g->visit[nod] = 1;
    while (!empty(qf))
    {
        int nod = delete_first(&qf, &ql);
        
        printf("%d ", nod);
        NodeT* i = g->adiacenta[nod];
        while(i!=NULL) {
           // printf("%d ", i->key);
            if (g->visit[i->key] == 0)
            {
                insert_last(&qf, &ql, i->key);
                g->visit[i->key] = 1;
            }
            i = i->next;
        }
        
    }
}

void bfs_vizita(graf* g)
{
    for (int i = 0; i < g->n; i++)
    {
        if (!g->visit[i])
           bfs(g,i);
    }
    /*for (int i = 0; i < g->n; i++)
    {
        printf("%d :", i);
        for (NodeT* j = g->adiacenta[i]; j != NULL; j = j->next)
            printf("%d ", j->key);
        printf("\n");
    }*/
}
int main()
{
    FILE* f = fopen("file.txt", "r");
    graf g;
    read_graph(&g, f);
    bfs_vizita(&g);
    /*NodeT* first = NULL;
    NodeT* last = NULL;
    insert_last(&first, &last, 1);
   
    int a=delete_first(&first, &last);
    int b= delete_first(&first, &last);
    printf("%d %d", a, b);*/
}