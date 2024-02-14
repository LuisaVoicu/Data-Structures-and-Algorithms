#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
typedef struct nod
{
    int key;
    struct nod* next;
}NodeT;

typedef struct
{
    int n;      // nr vf
    NodeT** t;  // tablou de liste
    int* pi;    // vector de parinti
    int* d;     // timp de descoperire
    int* f;     // timp de finalizare
    int* color; // informatii de culoare: white = nedescoperit / gray = descoperit(si nefinalizat) / black = finalizat

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

void citesteGraf(FILE* f, Graf* g)
{
    fscanf(f, "%d", &g->n);
    g->t = (NodeT**)calloc(g->n, sizeof(NodeT*));
    if (g->t == NULL)
    {
        printf("alocare esuata!\n");
        return;
    }
    g->pi = (int*)calloc(g->n, sizeof(int));
    g->d = (int*)calloc(g->n, sizeof(int));
    g->f = (int*)calloc(g->n, sizeof(int));
    g->color = (int*)calloc(g->n, sizeof(int));

    for (int i = 0; i < g->n; i++)
    {
        g->t[i] = NULL;
        g->color[i] = WHITE;
        g->pi[i] = -1;
        g->f[i] = -1;
    }

    int v, w;
    while (fscanf(f, "%d %d", &v, &w) == 2)
    {
        insert(&g->t[w], v);
        insert(&g->t[v], w);
    }
}



void dfs_visit_iterativ(Graf* G, int start)
{
    int time = -1;

    push(start);

    while (!empty())
    {

        int v = pop();
        
        if (G->color[v] == WHITE)
        {
            // elementul v este pentru prima data scos din stiva
            G->d[v] = ++time;
            G->color[v] = GRAY;
            printf("%d ", v);
        }


        int gaseste = 0; // gaseste macar un fiu nevizitat
        NodeT* list = G->t[v]; /// OBS: e mai eficient daca modificam direct lista (memorata in G->t) dar vom avea nevoie de ea si pentru dfs recursiv
        while (list != NULL)
        {
            if (G->color[list->key] == WHITE)
            {
                gaseste = 1;
                G->pi[list->key] = v;
                push(list->key);     //  printf("%d ", lista->key);
                break;
            }

            list = list->next;
        }

        //  CAZUL 1 -> am parcurs ambii subarbori!
        if (gaseste == 0)
        {
            G->f[v] = ++time;
            G->color[v] = BLACK;
        }

        // CAZUL 2 -> am parcurs doar subarborele stang!
        int parinte = G->pi[v];
        if (parinte != -1 && G->f[v] != -1) // explicatii => cond1: nu e radacina ;
                                            // cond2: e necesar ca copilul sa fie finalizat, altfel parintele va fi finalizat mai devreme decat el (ceea ce e imposibil)
        {
            push(parinte);
        }
    }
}

void dfs_iterativ(Graf* G)
{
    for (int i = 0; i < G->n; i++)
    {
        if (G->color[i] == WHITE)
        {
            dfs_visit_iterativ(G, i);
        }
    }
}

void print(int* arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void reInitTraversalData(Graf* G)
{
    for (int i = 0; i < G->n; i++)
    {
        G->d[i] = -1;
        G->pi[i] = -1;
        G->f[i] = -1;
        G->color[i] = WHITE;
    }

}


// TODO: Implementati dfs recursiv cu colorarea nodurilor si marcaje de timp
void dfs_visit(int v, Graf* G, int* time)
{
    G->d[v] = ++(*time);
    G->color[v] = GRAY;
    NodeT* list = G->t[v];
    printf("%d ", v);
    while (list != NULL)
    {
        int w = list->key;
        if (G->color[w] == WHITE)
        {
            G->pi[w] = v;
            dfs_visit(w, G, time);
        }
        list = list->next;
    }
    G->color[v] = BLACK;
    G->f[v] = ++(*time);
}

void dfs_recursiv(Graf* G) {

    int time = -1, i;

    for (i = 0; i < G->n; i++) {
        if (G->color[i] == WHITE) {
            dfs_visit(i, G, &time);
        }
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
    citesteGraf(f, &G);
    fclose(f);

    //varianta iterativa
    printf("DFS varianta iterativa:\n");
    dfs_iterativ(&G);
    printf("\n");

    printf("\nVectorul de parinti:\n");
    print(G.pi, G.n);

    printf("\nVectorul de descoperire:\n");
    print(G.d, G.n);

    printf("\nVectorul de finalizare:\n");
    print(G.f, G.n);

    printf("________________________________________________________");
    reInitTraversalData(&G);
    //varianta recursiva
    printf("\n\nDFS varianta recursiva:\n");
    dfs_recursiv(&G);
    printf("\n");

    printf("\nVectorul de parinti:\n");
    print(G.pi, G.n);

    printf("\nTimpii de descoperire:\n");
    print(G.d, G.n);

    printf("\nTimpii de finalizare:\n");
    print(G.f, G.n);


    //eliberam memoria
    free(G.color);
    free(G.d);
    free(G.f);

    int i;
    for (i = 0; i < G.n; i++) 
    {
        free(G.t[i]); 
    }

    free(G.t);
}