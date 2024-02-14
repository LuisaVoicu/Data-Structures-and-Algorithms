#define _CRT_SECURE_NO_WARNINGS
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
NodeT* create(int key)
{
    NodeT* root = (NodeT*)malloc(sizeof(NodeT));
    root->key = key;
    root->next = NULL;
    return root;
}
void enqueue(int key)
{
    NodeT* node = create(key);
    if (first == NULL)
    {
        first = last = node;
        return;
    }
    last->next = node;
    last = node;
}

int dequeue()
{
    if (first != NULL)
    {
        NodeT* p = first;
        int k = p->key;
        if (first == last)
        {
            first = last = NULL;
        }
        else
        {
            first = first->next;
        }

        free(p);
        return k;
    }
    return -1;
}
int empty()
{
    if (first == NULL)
    {
        return 1;
    }
    return 0;
}
void print()
{
    NodeT* p = first;
    while (p != NULL)
    {
        printf("%d ", p->key);
        p = p->next;
    }
    printf("\n");
}