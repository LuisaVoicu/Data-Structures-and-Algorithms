#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct cell
{
    int key;
    int status;
}Cell;

enum { FREE, OCCUPIED };


int f(int k, int n, int i)
{
    // linear probing

    return (k % n + i) % n;
}
void insert_ht(Cell* T, int n, int k)
{
    int nk = k;
    if (k < 0)
    {
        k = k * (-1);
        int div = k / n + 1;
        k = n * div - k;
    }
    int i = 0;
    int slot = f(k, n, i);

    if (T[slot].status == FREE)
    {
        T[slot].key = nk;
        T[slot].status = OCCUPIED;
        return;
    }

    int collision = slot;
    do
    {
        i++;
        slot = f(k, n, i);
    } while (collision != slot && T[slot].status == OCCUPIED);

    if (slot == collision)
    {
        printf("\ncoliziune la %d\n", nk);
        return;
    }
    T[slot].key = nk;
    T[slot].status = OCCUPIED;
}

int search_key(Cell* T, int n, int k)
{
    int nk = k;
    if (k < 0)
    {
        k *= (-1);
        int div = k / n + 1;
        k = div * n - k;
    }

    int i = 0;
    int slot = f(k, n, i);
    int collision = slot;
   
    do
    {
        if (T[slot].status == OCCUPIED && T[slot].key == nk)
        {
            return slot;
        }
        i++;
        slot = f(k, n, i);
    } while (collision != slot);
        
    return -1;
}

void set_free(Cell* T, int n)
{
    for (int i = 0; i < n; i++)
    {
        T[i].status = FREE;
    }
}

void afisare(Cell* T, int m)
{
    printf("\n\nTabela de dispersie este \n");
    for (int i = 0; i < m; i++)
    {
        if (T[i].status == OCCUPIED)
            printf("T[%d]=%d\n", i, T[i]);
        else
            printf("T[%d]= --\n", i);
    }
}

int main()
{
    int m = 7;
    Cell* T = (Cell*)malloc(sizeof(Cell) * m);

    set_free(T,m);
    int vals[] = { 19, 36, 5, 21, 4, 26, 14, 17 };
    for (int i = 0; i < sizeof(vals) / sizeof(int); i++)
    insert_ht(T, m, vals[i]);
    afisare(T, m);
    /*set_free(T, m);
    insert_ht(T, m, -3);
    afisare(T, m);*/

    for (int i = 0; i < sizeof(vals) / sizeof(int); i++) {
        int pos = search_key(T, m, vals[i]);
        if (pos != -1) {
            printf("cheia %d este pe pozitia %d\n", vals[i], pos);
        }
        else
            printf("cheia %d nu se gaseste in tabela\n", vals[i]);

    }

    int key = -100;
    int pos = search_key(T, m, key);
    if (pos != -1) {
        printf("cheia %d este pe pozitia %d\n", key, pos);
    }
    else
        printf("cheia %d nu se gaseste in tabela\n", key);
}