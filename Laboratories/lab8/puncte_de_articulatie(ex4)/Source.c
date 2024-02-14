 // se da un graf conex G
// v - nod de articulatie ==> prin elinimarea lui v graful G isi pierde proprietate de conexitate

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
    int* color;
    int* niv; // nivelul unui nod;
    int* nma; // nivelul minim accesibil ( = min(niv_curent, min_niv_noduri legate cu muchie de intoarcere, min_nma_fii)
    NodeT** t;
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

void citireGraf(FILE* f, Graf* G)
{
    fscanf(f, "%d", &G->n);
    G->niv = (int*)calloc(G->n, sizeof(int));
    G->nma = (int*)calloc(G->n, sizeof(int));
    G->color = (int*)calloc(G->n, sizeof(int));
    G->t = (NodeT**)calloc(G->n, sizeof(NodeT*));


    for (int i = 0; i < G->n; i++)
    {
        G->t[i] = NULL;
        G->color[i] = WHITE;
    }

    int v, w;
    while (fscanf(f, "%d %d", &v, &w) == 2)
    {
        insert(&G->t[v], w);
        insert(&G->t[w], v);
    }
}


void dfs_visit(int v, int p,int root, Graf* g)
{
    g->color[v] = GRAY;
    g->niv[v] = g->niv[p] + 1;
    g->nma[v] = g->niv[v];

    NodeT* list = g->t[v];
  
    while (list != NULL)
    {
        int w = list->key;
        if (w != p) {
            if (g->color[w] == WHITE)
            {
                dfs_visit(w, v, root, g);
                // verificam daca niv minim accesibil al fiilor este mai mic decat al nodului v
                if (g->nma[v] > g->nma[w])
                {
                    g->nma[v] = g->nma[w];
                }

                if (g->niv[v] <= g->nma[w] && v != root)
                {
                    printf("-->nodul %d e punct de articulatie\n", v);
                    //dem: (cond1)
                    // pres prin absurd ca d->niv[v] > g->nma[w] => 
                                        // nodul w poate ajunge mai sus in arbore (nu numai la parinte) 
                                                            // fie direct din el printr-o muchie de intoarcere 
                                                            // fie un elemend de mai jos , legat de w , poate sa ajunga mai sus in arbore decat nodul v
                                                            // deci nodurile sunt "prinse" si prin alt lant decat muchia (v,w)
                    // altfel daca g->niv[v] < g->nma[w] => nu se poate ajunge la un descendent (mai "mare" decat v) decat daca se trece prin (v,w) (muchie unica)
                    // altfel daca  g->niv[v] == g->nma[w] => poate sa existe o muchie de intoarcere (din subarborele cu radacina v) chiar pana la v -> va fi eliminata odata cu nodul de articulatie
                    /////
                    //cond2 : v!= root 
                        // radacina arborelui nu poate fi pct de articulatie ( din constructia arborelui el e minimal) ???
                }
            }
            else
            {
                // verificam daca nivelul nodurilor ce se leaga printr-o muchie de intoarcere este mai mic decat nma[v]
                if (g->nma[v] > g->niv[w])
                {
                    g->nma[v] = g->niv[w];
                }
            }
        }
        list = list->next;
    }
    
}

void print(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
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

    G.niv[0] = 1;
    G.nma[0] = 1;
    G.color[0] = GRAY;

    dfs_visit(G.t[0]->key, 0, 0, &G);

    printf("\nnivelul fiecarui nod:\n");
    print(G.niv, G.n);
    printf("\nnivelul minim accesibil fiecarui nod:\n");
    print(G.nma, G.n);
}