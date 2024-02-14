#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define M 20

typedef struct tabela
{
    int a;
    int b;
}elemT;
typedef struct direct_addresing
{
    elemT val;
    int status;
}Cell;
enum{FREE,OCCUPIED};
int f(int k, int i,int n)
{
    return ((k % n) + i) % n;
}
void insert_ht(Cell*T,int n, elemT key)
{
    printf("se insereaza %d %d pe slotul : ", key.a, key.b);
    int i = 0;
    int slot = f(key.a, i, n);
    if (T[slot].status == FREE)
    {
        printf("%d\n", slot);
        T[slot].val = key;
        T[slot].status = OCCUPIED;
    }
    else
    {
        int collision = slot;
        i++;
        slot = f(key.a, i, n);
        while (T[slot].status != FREE && slot != collision)
        {
            i++;
            slot = f(key.a, i, n);
        }
        if (slot == collision)
        {
            printf("Eroare! Tabela e plina!\n");
        }
        else
        {
            printf("%d\n", slot);
            T[slot].val = key;
            T[slot].status = OCCUPIED;
        }
    }
}

int search_ht(Cell* T, int n, elemT key)
{
    // cautam al doilea element al perechei!!
    int i = 0;
    int slot = f(key.b, i, n);
  
    if (T[slot].status == FREE)
    {
     
        return -1; // celula nu e ocupata!
    }

    if (T[slot].val.a == key.b && T[slot].val.b == key.a)
    {
        return slot;
    }
    int collision = slot;
    i++;
    slot = f(key.b, i, n);
    
    while (collision != slot)
    {

        if (T[slot].val.b == key.a && T[slot].val.b == key.a)
        {
            return slot;
        }
        i++;
        slot = f(key.b, i, n);
    }

    return -1;
}

void set_free(Cell* T, int n)
{
    for (int i = 0; i < n; i++)
    {
        T[i].status = FREE;
    }
}

void print_ht(Cell* T, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d : %d %d\n",i, T[i].val.a, T[i].val.b);
    }
    printf("\n");
}
int main()
{
    FILE* pf = fopen("file.txt", "r");
    if (pf == NULL)
    {
        exit(123);
    }

    int n;
    
    fscanf(pf, "%d", &n);
    elemT* v = (elemT*)malloc(sizeof(elemT) * n);
    Cell* T = (Cell*)malloc(sizeof(Cell));
    set_free(T, n);
    for (int i = 0; i < n; i++)
    {
        // primul element din pereche e unic!!
        // deci punem in hash_table primul element din fiecare
        // dupa caut cel de-al doilea element din perece in ht ->daca l-am gasit, verific daca perechea lui e aceeasi cu cea cea din perechea initiala

        fscanf(pf, "%d %d", &v[i].a, &v[i].b);
        
        printf("%d %d\n", v[i].a, v[i].b);
        // inseram prima pereche in fie
        insert_ht(T, n, v[i]);
    }
    print_ht(T, n);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int k = search_ht(T, n, v[i]);
        printf("%d %d %d\n", v[i].a, v[i].b, k);
        if (k != -1)
        {
            count++;
        }
    }

    printf("au fost gasite %d\n perechi", count / 2);
}