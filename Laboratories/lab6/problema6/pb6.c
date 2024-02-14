#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct direct_addressing
{
    int key;
    int status;
}Cell;
enum { FREE, OCCUPIED};

int f(int k,int n, int i)
{
    return (k + i) % n;
}

void insert(Cell* T, int n, int k)
{
   /* int already_inTH = 0;
    int kneg = 0;
    if (k < 0)
    {
        kneg = k;
        k *= (-1);
        int div = k / n;
        div++;
        k = n * div - k;
    }
    int i = 0;
    int slot = f(k, i, n); 

    if (T[slot].status == FREE)
    {
        if (kneg == 0)
        {
            T[slot].key = k;
        }
        else
        {
            T[slot].key = kneg;
        }
        T[slot].status = OCCUPIED;

    }
    else
    {
        int collision = slot;
        i++;
        slot = f(k, n, i);

        while (T[slot].status != FREE && slot != collision)
        {
            if (T[slot].key == k)
            {
                already_inTH = 1;
                break;
            }
            i++;
            slot = f(k, n, i);
        }

        if (already_inTH == 0)
        {
            if (slot == collision)
            {
                printf("\nTabelul de dispersie este plin !");
            }
            else
            {
                if (kneg == 0)
                {
                    T[slot].key = k;
                }
                else
                {
                    T[slot].key = kneg;
                }
                T[slot].status = OCCUPIED;
            }
        }
    }*/

    int kneg = 0;
    int already_inTH = 0;
    if (k < 0)
    {
        kneg = k;
        k *= (-1);
        int div = k / n;
        div++;

        k = n * div - k;

    }
    int i = 0;
    int slot = f(k,n, i);

    if (T[slot].status == FREE)
    {
        if (kneg == 0)
        {
            T[slot].key = k;
        }
        else
        {
            T[slot].key = kneg;
        }
        T[slot].status = OCCUPIED;

    }
    else
    {
        if (T[slot].key != k)
        {


            int collision = slot;
            i++;
            slot = f(k, n, i);

            while (T[slot].status != FREE && slot != collision)
            {
                //printf("status %d\n", T[hash_func(k, m, i)].status);
                if (T[slot].key == k)
                {
                    printf("gasit!\n");
                    already_inTH = 1;
                    break;
                }
                i++;
                slot = f(k, n, i);
            }
            if (already_inTH == 0)
            {
                if (slot == collision)
                {
                    printf("\nTabelul de dispersie este plin!\n");
                }
                else
                {
                    // printf("-->entru cheia %d locul %d este liber\n", k, i);

                    if (kneg == 0)
                    {
                        T[slot].key = k;
                    }
                    else
                    {
                        T[slot].key = kneg;
                    }
                    T[slot].status = OCCUPIED;
                }
            }
        }
    }
}

void printHT(Cell* T, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (T[i].status == OCCUPIED)
        {
            printf("%d ", T[i].key);
        }
    }
    printf("\n");
}

void set_free(Cell* T, int n)
{
    for (int i = 0; i < n; i++)
    {
        T[i].status = FREE;
    }
}
int main()
{
    FILE* pf = fopen("file.txt", "r");
    if (pf == NULL)
    {
        printf("eroare");
        exit(1);
    }

    int n; 
    fscanf(pf, "%d", &n);
    Cell* T = (Cell*)malloc(sizeof(Cell) * n);
    set_free(T, n);

    printf("Array-ul initial: \n");
    for (int i = 0; i < n; i++)
    {
        int key;
        fscanf(pf, "%d", &key);
        printf("%d ",key);
        insert(T, n, key);

    }
    printf("\n\nArray-ul fara duplicate: \n");
    printHT(T, n);
}