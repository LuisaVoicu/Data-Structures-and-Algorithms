#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node* prev;
    struct node* next;
}NodeT;

NodeT* create(int key)
{
    NodeT* node = (NodeT*)malloc(sizeof(NodeT));
    node->key = key;
    node->prev = node->next = NULL;
    return node;
}

void insert_first(NodeT** first, NodeT** last, int key)
{
    NodeT* node = create(key);
    if (*first == NULL)
    {
        *first = *last = node;
        return;
    }
    node->next = *first;
    (*first)->prev = node;
    *first = node;
}

void insert_last(NodeT** first, NodeT** last, int key)
{
    NodeT* node = create(key);
    if (*first == NULL)
    {
        *first = *last = node;
        return;
    }
    node->prev = *last;
    (*last)->next = node;
    *last = node;
}


void insert_after_key(NodeT** first, NodeT** last, int givenKey, int key)
{
    NodeT* node = create(key);
    NodeT* p = *first;
    
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
        if (p == *last)
        {
            // insert last
            (*last)->next = p;
            p->prev = *last;
            *last = p;
            return;
        }

        node->prev = p;
        node->next = p->next;
        p->next = node;
        p->next->prev = node;

    }


}


void insert_before_key(NodeT** first, NodeT** last, int givenKey,int key)
{

    NodeT* node = create(key);
    NodeT* p = *first;

   // printf("de cautat %d\n", givenKey);
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
        //printf("%d gasit\n", p->key);
        if (p->prev == NULL)
        {
           // insert first
            node->next = *first;
            (*first)->prev = node;
            *first = node;
            return;
        }
        node->prev = p->prev;
        node->next = p;
        p->prev->next = node;
        p->prev = node;

    }
}





void delete_first(NodeT** first, NodeT** last)
{
    if (*first != NULL)
    {
        NodeT* p = *first;
        if (*first == *last)
        {
            *first = *last = NULL;
        }
        else
        {
            (*first)->next->prev = NULL;
            (*first) = (*first)->next;
        }
        free(p);
    }
}

void delete_last(NodeT** first, NodeT** last)
{
    if (*first != NULL)
    {
        NodeT* p = *last;
        if (*first == *last)
        {
            *first = *last = NULL;
        }
        else
        {
            (*last)->prev->next = NULL;
            *last = (*last)->prev;

        }
        free(p);
    }
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
        if (*first == *last)
        {
                *first = *last = NULL;
        }

        else if (*first == p)
        {     

            (*first)->next->prev = NULL;
            (*first) = (*first)->next;
        }
        else if (*last == p)
        {
            (*last)->prev->next = NULL;
            *last = (*last)->prev;
        }
        else
        {
            prev->next = p->next;
            p->next->prev = prev;
        }
        free(p);
    }
}

NodeT* search_key(NodeT* first, int key) 
{
    NodeT* p = first;
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

void print_doubly(NodeT* first)
{
    NodeT* p = first;
    while (p != NULL)
    {
        printf("%d ", p->key);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    NodeT* first = NULL;
    NodeT* last = NULL;
    insert_first(&first, &last, 3);
    insert_first(&first, &last, 2);
    insert_first(&first, &last, 1);
    insert_first(&first, &last, 0);
    print_doubly(first);

    insert_last(&first, &last, 4);
    insert_last(&first, &last, 5);
    insert_last(&first, &last, 6);
    print_doubly(first);

    insert_before_key(&first, &last, 5, -5);
    insert_after_key(&first, &last, 2, -2);
    print_doubly(first);

    delete_first(&first, &last);
    delete_last(&first, &last);
    print_doubly(first);

    delete_key(&first, &last, 1);
    delete_key(&first, &last, -2);
    delete_key(&first, &last, -5);
    delete_key(&first, &last, 5);
    print_doubly(first);
}