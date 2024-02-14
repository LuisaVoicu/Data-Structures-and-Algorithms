#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct nod {
    int key;
    struct nod* next;
} NodeT;

typedef struct {
    int n;      // numar de varfuri
    NodeT** t;  // tabloul de liste (va fi alocat dinamic)
    int* disponibil; // = 0 (e disponibil) / = 1 (e testat daca e punct de articulatie)
    int* color; //informatia de culoare
} Graf;     // structura pentru memorarea grafului prin liste de adiacenta dinamice; tine si informatia de parcurgere

enum {
    WHITE, GRAY, BLACK
};

void printErr() {
    printf("Memorie insuficienta!\n");
    exit(1);
}

void insert(NodeT** list, int val)
{
    NodeT* node = (NodeT*)malloc(sizeof(NodeT));
    node->key = val;
    node->next = *list;
    *list = node;

}


void dfs_visit(int v, Graf* g)
{
    if (v != -1) {
        g->color[v] = GRAY;
  
        NodeT* list = g->t[v];
        while (list)
        {
            int w = list->key;
            if (g->color[w] == WHITE && !g->disponibil[w])
            {
                dfs_visit(w, g);
            }
            list = list->next;
        }
        g->color[v] = BLACK;
       
    }
}




void reInitTraversalData(Graf* G)
{
    for (int i = 0; i < G->n; i++)
    {
 
        G->color[i] = WHITE;
    }

}

int conex(Graf G)
{
    for (int i = 0; i < G.n; i++)
    if(!G.disponibil[i]&&G.color[i]==WHITE)
    {
        return 0;
    }
    return 1;
}

void puncte_de_articulatie(Graf* G) {

    for (int i = 0; i < G->n; i++)
    {
        
        G->disponibil[i] = 1;
        int v = 0;
        if (i == 0)
        {
            v++;
        }
        dfs_visit(v, G);
        int con = conex(*G);
        if (con == 0)
        {
            printf("pct de articulatie: %d\n", i);
        }
        G->disponibil[i] = 0;
        reInitTraversalData(G);
    }

    
}


void citesteGraf(FILE* f, Graf* pG) {

    fscanf(f, "%d", &pG->n);  // citeste nr. de varfuri

    pG->t = (NodeT**)calloc(pG->n, sizeof(NodeT*));
    if (pG->t == NULL) printErr();  // alocare esuata


    pG->color = (int*)calloc(pG->n, sizeof(int));
    pG->disponibil = (int*)calloc(pG->n, sizeof(int));

    int i;
    for (i = 0; i < pG->n; i++) {
        pG->t[i] = NULL;
    }

    int v, w;
    while (fscanf(f, "%d%d", &v, &w) == 2) {
        //graful va fi neorientat, se adauga atat arcul (v,w) cat si (w,v)
        insert(&pG->t[w], v);
        insert(&pG->t[v], w);
    }
}

void print(int* arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main()
{
    FILE* f = fopen("graf.txt", "r");
    if (f == NULL) {
        perror("graf.txt");
        exit(1);
    }
    Graf G;
    citesteGraf(f, &G);
    fclose(f);


    puncte_de_articulatie(&G);


    free(G.color);
    free(G.disponibil);

    int i;
    for (i = 0; i < G.n; i++) {
        free(G.t[i]);
    }

    free(G.t);
}