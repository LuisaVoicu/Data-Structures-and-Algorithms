#include "queue.h"
#include <stdlib.h>


NodeT* create(per key)
{
    NodeT* root = (NodeT*)malloc(sizeof(NodeT));
    root->key = key;
    root->next = NULL;
    return root;
}
void enqueue(per key)
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

per dequeue()
{
    if (first != NULL)
    {
        NodeT* p = first;
        per k = p->key;
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
    per k;
    k.a = -1;
    k.b = -1;
    return k;
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