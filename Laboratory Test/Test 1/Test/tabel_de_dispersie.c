
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int key;
    struct Node* next;
} NodeT;

// Dimensiunea tabelei de dispersie
#define M 11

void insertFirst(int key, NodeT** head)
{
    NodeT* newNode = (NodeT*)malloc(sizeof(NodeT));
    newNode->key = key;

    newNode->next = (*head);
    (*head) = newNode;
}

int hash(int x)
{
    return x % M;
}

// functia va insera un element in tabela de dispersie
void insertElement(NodeT* hTable[], int key)
{
    // TODO
    int slot = hash(key);
    // fiecare element va fi inserat pe prima pozitie din lista
    insertFirst(key, &(hTable[slot]));
}

// functia va returna nodul gasit, sau NULL daca acesta nu exista
NodeT* findElement(NodeT* hTable[], int key)
{
    int slot = hash(key);
    NodeT* p = hTable[slot];
    while (p != NULL)
    {
        if (p->key == key)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;

}

void printHT(NodeT* hTable[])
{
    for (int i = 0; i < M; i++)
    {
        if (hTable[i] != NULL)
        {
            printf("%d : ", i);
            NodeT* p = hTable[i];
            while (p != NULL)
            {
                printf("%d ", p->key);
                p = p->next;
            }
            printf("\n");
        }
    }

}

int main()
{
    NodeT* hTable[M];
    for (int i = 0; i < M; i++)
    {
        hTable[i] = NULL;
    }
    insertElement(hTable, 25);
    insertElement(hTable, 14);
    insertElement(hTable, 22);
    printf("\n........\n");
    printf("Elementele tabelei sunt: \n");
    printHT(hTable);
    printf("..........\n\n");
    NodeT* rez;
    rez = findElement(hTable, 14);
    if (rez != NULL)
    {
        printf("14: gasit\n");
    }
    else
    {
        printf("14: negasit\n");
    }


    rez = findElement(hTable, 33);
    if (rez != NULL)
    {
        printf("33: gasit\n");
    }
    else
    {
        printf("33: negasit\n");
    }

    return 0;
}
