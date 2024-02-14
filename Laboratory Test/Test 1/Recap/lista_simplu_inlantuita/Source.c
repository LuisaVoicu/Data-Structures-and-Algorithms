#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node* next;
}NodeT;


NodeT* create_node(int key)
{
    NodeT* node = (NodeT*)malloc(sizeof(NodeT));
    node->key = key;
    node->next = NULL;
    return node;
}

void insert_first(NodeT** first, NodeT** last, int key)
{
    NodeT* node = create_node(key);
    if (*first == NULL)
    {
        *first = *last = node;
        return;
    }
    node->next = *first;
    *first = node;
}

void insert_last(NodeT** first, NodeT** last, int key)
{
    NodeT* node = create_node(key);
    if (*first == NULL)
    {
        *first = *last = node;
        return;
    }
    (*last)->next = node;
    *last = node;
}

void  insert_before_key(NodeT** first, NodeT** last, int givenKey, int key)
{
    NodeT* p = *first;
    NodeT* prev = NULL;
    NodeT* node = create_node(key);

    while (p != NULL)
    {
        if (p->key == givenKey)
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
            node->next = *first;
            *first = node;
            return;
        }
        node->next = p;
        prev->next = node;

    }
}

void insert_after_key(NodeT** first, NodeT** last, int givenKey, int key)
{
    NodeT* p = *first;
   // NodeT* prev = NULL;
    NodeT* node = create_node(key);

    while (p != NULL)
    {
        if (p->key == givenKey)
        {
            break;
        }
        p = p->next;
    }
    if (p != NULL)
    {
        if (*last == p)
        {
            p->next = node;
            *last = node;
            return;
        }
        node->next = p->next;
        p->next = node;

    }

}

void delete_first(NodeT** first, NodeT** last)
{
    NodeT* p = *first;;
    if (*first == NULL)
    {
        
        return;
    }
    if (*first == *last)
    {
        *first = *last = NULL;
        free(p);
        return;
    }
    *first = (*first)->next;
    free(p);
    
}

void delete_last(NodeT** first, NodeT** last)
{
    NodeT* p = *first;
    NodeT* prev = NULL;
    if (*first == NULL)
    {
        return;
    }
    if (*first == *last)
    {
        *first = *last = NULL;
        free(p);
        return;
    }
    while (p!=NULL && p->next != NULL)
    {
        prev = p;
        p = p->next;
    }
    prev->next = NULL;
    *last = prev;
    free(p);
}

void delete_key(NodeT** first, NodeT** last, int key)
{
    NodeT* p = *first;
    NodeT* prev = NULL;

    while (p != NULL)
    {
        if (p->key == key)
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
            (*first) = (*first)->next;
            free(p);
            return;
        }

        prev->next = p->next;
        free(p);

    }
}

NodeT* search(NodeT* first,int key)
{
    while (first != NULL)
    {
        if (first->key == key)
            return first;
        first = first->next;
    }
    return NULL;
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

void main()
{
    NodeT* first = NULL;
    NodeT* last = NULL;
    insert_first(&first, &last, 3);
    insert_first(&first, &last, 2);
    insert_first(&first, &last, 1);
    insert_first(&first, &last, 0);
    print(first);

    insert_last(&first, &last, 4);
    insert_last(&first, &last, 5);
    insert_last(&first, &last, 6);
    print(first);

    insert_after_key(&first, &last, 1, -1);
    insert_after_key(&first, &last, 4, -4);
    insert_after_key(&first, &last, 6, -6);
    print(first);

    insert_before_key(&first, &last, 0, -1);
    insert_before_key(&first, &last, 5, -5);
    insert_before_key(&first, &last, 6, -6);
    print(first);

    delete_first(&first, &last);
    delete_last(&first, &last);
    print(first);

    delete_key(&first, &last, -1);
    delete_key(&first, &last, 0);
    delete_key(&first, &last, 6);
    delete_key(&first, &last, 26);
    print(first);

    NodeT* srch =  search(first, 4);
    if (srch == NULL)
    {
        printf("nue\n");
    }
    else
    {
        printf("gasit %d\n", srch->key);
    }
    srch =  search(first, 24);
    if (srch == NULL)
    {
        printf("nue\n");
    }
    else
    {
        printf("gasit %d\n", srch->key);
    }
}