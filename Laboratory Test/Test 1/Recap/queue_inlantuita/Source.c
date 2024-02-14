#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int key;
    struct node* next;
}NodeT;

NodeT* create(int key)
{
    NodeT* root = (NodeT*)malloc(sizeof(NodeT));
    root->key = key;
    root->next = NULL;
}

void enqueue(NodeT** first, NodeT** last, int key)
{
    NodeT* node = create(key);
    if (*first == NULL)
    {
        *first = *last = node;
        return;
    }
    // insert last
    (*last)->next = node;
    *last = node;
}

int dequeue(NodeT** first, NodeT** last)
{
    if (*first != NULL)
    {
        NodeT* p = *first;
        int k = p->key;
        if (*first == *last)
        {
            *first = *last = NULL;
        }
        else
        {
            *first = (*first)->next;
        }
        free(p);
        return k;
    }
    else
    {
        return -1;
    }
}

void print(NodeT* first)
{
    while (first != NULL)
    {
        printf("%d ", first->key);
        first = first->next;
    }
    printf("\n");
}
int main()
{
    NodeT* first = NULL;
    NodeT* last = NULL;
    enqueue(&first, &last, 1);
    enqueue(&first, &last, 3);
    enqueue(&first, &last, 4);
    enqueue(&first, &last, 6);
    enqueue(&first, &last, 7);
    enqueue(&first, &last, 8);

    print(first);

    dequeue(&first, &last);
    dequeue(&first, &last);
    dequeue(&first, &last);
    dequeue(&first, &last);
    dequeue(&first, &last);
   // dequeue(&first, &last);
    print(first);
}