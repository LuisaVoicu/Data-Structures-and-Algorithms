#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define M 7
typedef struct node
{
    int key;
    struct node* next;
}NodeT;

int f(int k)
{
    return k % M;
}


NodeT* create(int key)
{
    NodeT* node = (NodeT*)malloc(sizeof(NodeT));
    node->key = key;
    node->next = NULL;
}


void insert(NodeT* T[M], int key)
{
    int neg = 1;
    if (key < 0)
    {
        key *= (-1);
        neg = -1;
    }
    int slot = f(key);
    NodeT* node = create(key * neg);
    if (T[slot] == NULL)
    {
        T[slot] = node;
        return;
    }

    node->next = T[slot];
    T[slot] = node;
}

void deleteKey(NodeT* T[M], int key)
{
    int neg = 1;
    if (key < 0)
    {
        key *= (-1);
        neg = -1;
    }
    int slot = f(key);
    if (T[slot] == NULL)
    {
        return;
    }
    NodeT* p = T[slot];
    NodeT* prev = NULL;

    while (p != NULL)
    {
        if (p->key == key*neg)
        {
            break;
        }
        prev = p;
        p = p->next;
    }
    
    if (p != NULL)
    {
        if (prev == NULL)
        {
            // delete first
            T[slot] = T[slot]->next;
            free(p);
            return;
        }
        prev->next = p->next;
        free(p);
    }
}


void search(NodeT* T[M], int key)
{
    int neg = 1;
    if (key < 0)
    {
        key *= (-1);
        neg = -1;
    }
    int slot = f(key);
    NodeT* p = T[slot];
    while (p != NULL)
    {
        if (p->key == key*neg)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void showAll(NodeT* hTable[M]) {
    int i;
    for (i = 0; i < M; i++)
    {
        printf(" %d :", i);
        //verificam daca la slotul i am adaugat ceva
        if (hTable[i] != NULL)
        {

            NodeT* p;
            p = hTable[i];
            while (p != NULL)
            {
                printf(" %d ", p->key);
                p = p->next;
            }
        }
        printf("\n");
    }
    printf("\n");
}
int main()
{
    //initializare
    NodeT* hTable[M];
    for (int i = 0; i < M; i++) {
        hTable[i] = NULL;
    }

    //test inserare
    int vals[] = { 36, 18, 6, 43, 72, 10, 5, 15 ,-5 };
    for (int i = 0; i < sizeof(vals) / sizeof(int); i++)
        insert(hTable, vals[i]);
    showAll(hTable);

    // 0:
    // 1: 15 43 36
    // 2: 72
    // 3: 10
    // 4: 18
    // 5: 5
    // 6: 6

    //test stergere
    int todel[] = { 43, 36, 10, 61, -5 };
    for (int i = 0; i < sizeof(todel) / sizeof(int); i++)
        deleteKey(hTable, todel[i]);
    showAll(hTable);

    // 0:
    // 1: 15
    // 2: 72
    // 3:
    // 4: 18
    // 5: 5
    // 6: 6

}