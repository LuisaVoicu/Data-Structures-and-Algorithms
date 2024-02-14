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
    int* color;
    NodeT** t;
}Graf;
enum { WHITE, GRAY, BLACK };

void insert_first(NodeT** list, int key)
{

    NodeT* node = (NodeT*)malloc(sizeof(NodeT));
    node->key = key;
    node->next = *list;
    *list = node;
}

void citesteGraf(FILE* f, Graf* g)
{
    fscanf(f, "%d", &g->n);
    g->t = (NodeT**)calloc(g->n, sizeof(NodeT*));

    if (g->t == NULL)
    {
        printf("alocare esuata!\n");
        return;
    }
    g->d = (int*)calloc(g->n, sizeof(int));
    g->f = (int*)calloc(g->n, sizeof(int));
    g->color = (int*)calloc(g->n, sizeof(int));

    for (int i = 0; i < g->n; i++)
    {
        g->t[i] = NULL;
        g->color[i] = WHITE;
        g->f[i] = -1;
    }

    int v, w;
    while (fscanf(f, "%d %d", &v, &w) == 2)
    {
        //insert_first(&g->t[w], v);
        insert_first(&g->t[v], w);
    }
}


void dfs(int v, Graf* g, int* time, NodeT** top, int* pos)
{
    g->color[v] = GRAY;
    g->d[v] = ++(*time);

    if (!(*pos))
    {
        return;
    }
    while (g->t[v] != NULL)
    {
        int elem = g->t[v]->key;
        if (g->color[elem] == WHITE)
        {
            dfs(elem, g, time, top, pos);
        }
        else if(g->color[elem] == GRAY)
        {
            // daca e GRAY, la elementul elem se poate ajunge si prin alt lant decat cel deja parcurs
                                                        // => ciclu => graful nu poate fi sortat topologic

            *pos = 0;
            break;
        }
        g->t[v] = g->t[v]->next;
    }
    g->color[v] = BLACK;
    g->f[v] = ++(*time);

    insert_first(top, v);


}
int dfs_rec(Graf* g,NodeT** top)
{
    int time = -1;
    int pos = 1;
    for(int i = 0; i < g->n ; i++)
        if (g->color[i] == WHITE)
        {
            dfs(i, g, &time, top, &pos);
        }
    return pos;
}
void sort_topologica(NodeT* lista)
{
    while (lista)
    {
        printf("%d ", lista->key);
        lista = lista->next;
    }
    printf("\n");
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
    Graf G;
    citesteGraf(f, &G);
    fclose(f);

    NodeT* top = NULL;

    int k = dfs_rec(&G, &top);
    if (k)
    {
        printf("sortarea topologica:\n");
        sort_topologica(top);
    }
    else
    {
        printf("graful nu poate fi sortat topologic!\n");
    }

    free_mem(&G);

}
