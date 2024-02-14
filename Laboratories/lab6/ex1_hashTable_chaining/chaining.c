#define _crt_secure_no_warnings
#include <stdio.h>
#include <stdlib.h>
#define M 7 //dimensiunea tabelei de dispersie

typedef struct node {
    int val;
    struct node* next;
}NodeT;

NodeT* createNode(int key)
{
    NodeT* node = (NodeT*)malloc(sizeof(NodeT));
    node->val = key;
    node->next = NULL;
}
int hFunction(int key) {
    return key % M;
}

void insert(NodeT* hTable[M], int key) {
    int slot = hFunction(key);
    // insert first
    // hTable[slot] ~ list
    NodeT* node = createNode(key);
    if (hTable[slot] == NULL)
    {
        hTable[slot] = node;
    }
    else
    {
        node->next = hTable[slot];
        hTable[slot] = node;
    }
}


NodeT* search(NodeT* hTable[M], int key) {
    int slot = hFunction(key);
    NodeT* p = hTable[slot];
    while (p != NULL)
    {
        if (p->val == key)
        {
            return p;
        }
        p = p->next;
    }

    return NULL;
}


void deleteKey(NodeT* hTable[M], int key)
{
    // delete

    int slot = hFunction(key);
    NodeT* prev = NULL;
    NodeT* current = hTable[slot];

    while (current != NULL)
    {

        if (current->val == key)
        {
            break;
        }
        prev = current;
        current = current->next;
    }
    if (current != NULL)
    {
        // a fost gasita valoarea

        if (current == hTable[slot])
        {   // val se afla pe prima pozitie
            current = current->next;
            hTable[slot] = current;

        }
        else
        {
            prev->next = current->next;
            free(current);
        }
    }
}

//afisarea tuturor elmentelor din tebela de dispersie
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
                printf(" %d ", p->val);
                p = p->next;
            }
        }
        printf("\n");
    }
    printf("\n");
}


int main() {

    //initializare
    NodeT* hTable[M];
    for (int i = 0; i < M; i++) {
        hTable[i] = NULL;
    }

    //test inserare
    int vals[] = { 36, 18, 6, 43, 72, 10, 5, 15 };
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

    return 0;
}
