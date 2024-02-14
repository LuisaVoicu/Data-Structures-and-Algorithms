#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct lista_copii
{
    int key;
    struct lista_copii* next;


}NodeT;

typedef struct multicai
{
    int key;
    int inaltime;
    struct multicai* parinte;
    struct multicai* auxiliar;
    struct multicai* next;
    struct multicai* primul_copil;
}NodeM;



// operatii cu liste
NodeT* create_list(int givenKey)
{
    NodeT* p = (NodeT*)malloc(sizeof(NodeT));

    if (NULL == p)
    {
        //nu se poate aloca memorie
        exit(1);
    }

    p->key = givenKey;
    p->next = NULL;
    return p;
}
void insert_first(NodeT** list, int givenKey)
{
    NodeT* node = create_list(givenKey);

    if (*list == NULL)
    {
        *list = node;
    }
    else
    {
        node->next = *list;
        *list = node;
    }

}
NodeM* creeaza_nod_m(int key)
{
    NodeM* root = (NodeM*)malloc(sizeof(NodeM));
    root->key = key;
    root->inaltime = 0;
    root->parinte = NULL;
    root->auxiliar = NULL;
    root->next = NULL;
    root->primul_copil = NULL;

    return root;
}

NodeM* creeaza_arbore_multicai(NodeM* root, NodeT** list, int key)
{

    NodeM* newR = creeaza_nod_m(key);
    if (root == NULL)
    {
        root = newR;

        NodeT* node = list[key];
        if (node != NULL)
        {
            root->auxiliar = creeaza_arbore_multicai(root->auxiliar, list, node->key);
            root->primul_copil = root->auxiliar;
            if (node->next != NULL)
            {

                node = node->next;

                while (node != NULL)
                {


                    root->auxiliar->next = creeaza_arbore_multicai(root->auxiliar->next, list, node->key);
                    root->auxiliar->next->parinte = root;
                    root->auxiliar = root->auxiliar->next;

                    node = node->next;
                }
            }
        }
    }
    return root;
}

void afisare_arbore_multicai(NodeM* root)
{

    /*
    se va afisa in ordine : radacina(implicit primul copil), fratele din dreapta
    */
    if (root != NULL)
    {


        afisare_arbore_multicai(root->primul_copil);
        afisare_arbore_multicai(root->next);
        printf("%d ", root->key);
    }
}

int inaltime_arbore_multicai(NodeM* root)
{
    if (root == NULL)
    {
        return 0;
    }

    int h = inaltime_arbore_multicai(root->primul_copil);
    inaltime_arbore_multicai(root->next);

    if (root->inaltime < h)
    {
        root->inaltime = h;
    }
    else
    {
        h = root->inaltime;
    }

    if (root->parinte != NULL)
    {
        if (root->parinte->inaltime < root->inaltime + 1)
            root->parinte->inaltime = root->inaltime + 1;
    }

    return h + 1;
}
int main()
{
    FILE* pf = fopen("file.txt", "r");

    int nb;
    fscanf(pf, "%d", &nb);
    int* parent = (int*)malloc(sizeof(int) * (nb + 1));
    int root;
    for (int i = 1; i <= nb; i++)
    {
        fscanf(pf, "%d", &parent[i]);
        if (parent[i] == 0)
        {
            root = i;
        }

    }

    // pas 1. Transformarea in reprezentarea de arbore multi-cai (fiecare nod va avea o lista de noduri copil)
    NodeT** list = (NodeT**)malloc((nb + 1) * sizeof(NodeT*));
    for (int i = 1; i <= nb; i++)
    {

        list[i] = NULL;

        //vom parcurge sirul de elemente in ordine inversta
        // si vom adauga pe prima pozitie in lista elementele 
        // astfel acestea apar in ordine crescatoare
        // deci nu e nevoie sa folosim "insert_last" pentru care este nevoie sa retinem adresa atat primului element cat si cea aultimului din lista

        for (int j = nb; j >= 1; j--)
        {
            if (parent[j] == i)
            {

                insert_first(&list[i], j);
            }

        }

    }

     // pas 2.
    NodeM* rad = NULL;


    rad = creeaza_arbore_multicai(rad, list, root);
    printf("\nElementele arborelui multicai este:\n");
   
    afisare_arbore_multicai(rad);

    // pas 3. inaltimea
    inaltime_arbore_multicai(rad);
    printf("\n\nInaltimea arborelui multicai este %d !\n", rad->inaltime);
}