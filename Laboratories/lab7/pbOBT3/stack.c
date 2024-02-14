#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

void push(int key)
{
    St* node = (St*)malloc(sizeof(St));
    node->key = key;
    node->next = NULL;
    if (firstst == NULL)
    {
        firstst = node;
        return;
    }
    node->next = firstst;
    firstst = node;
}

int pop()
{
    if (firstst == NULL)
    {
        return -1;
    }

    int k = firstst->key;
    St* p = firstst;
    firstst = firstst->next;
    free(p);

    return k;
}

int top()
{
    if(firstst!=NULL)
    return firstst->key;
    return -1;
}

int emptys()
{
    if (firstst == NULL)
    {
        return 1;
    }
    return 0;
}

void print_st()
{
    St* p = firstst;
    while (p != NULL)
    {
        printf("%d ", p->key);
        p = p->next;
    }
    printf("\n");
}