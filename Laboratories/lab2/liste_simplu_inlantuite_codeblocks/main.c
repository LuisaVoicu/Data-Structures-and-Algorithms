#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct NodeType {
    int key;
    struct NodeType* next;
}NodeT;

NodeT* create_list(int givenkey)
{
    NodeT* q = (NodeT*)malloc(sizeof(NodeT));

    if (NULL == q)
    {
        // nu se poate realiza alocarea dinamica
        exit(1);
    }

    q->key = givenkey;
    q->next = NULL;

    return q;
}

void insert_first(NodeT** first, NodeT** last, int givenKey)
{
    NodeT* p_first = *first;
    NodeT* p_last = *last;
    NodeT* elem = create_list(givenKey);

    if (NULL == p_first)
    {
        //nu exista niciun element in lista
        p_first = elem;
        p_last = elem;
    }

    else if (NULL != p_first)
    {
        elem->next = p_first;
        p_first = elem;
    }

    *first = p_first;
    *last = p_last;

}

void insert_last(NodeT** first, NodeT** last, int givenKey)
{
    NodeT* p_first = *first;
    NodeT* p_last = *last;
    NodeT* elem = create_list(givenKey);

    if (NULL == p_first)
    {
        p_first = elem;
        p_last = elem;
    }

    else if (NULL != p_last)
    {
        p_last->next = elem;
        p_last = elem;
    }
     *first = p_first;
     *last = p_last;
}

void insert_before_key(NodeT** first, NodeT** last, int beforeKey, int givenKey)
{
    NodeT* q = *first;
    NodeT* q1 = NULL;
    NodeT* elem = create_list(givenKey);
    // pas 1 -> cautam cheia in lista simplu inlantuita

    while (NULL != q)
    {
        if (q->key == beforeKey)
        {
            break;
        }

        q1 = q;
        q = q->next;
    }

    if (q == *first)
    {
        // inserare inaintea primului element
        elem->next = *first;
        *first = elem;
    }

    else
    {
        q1->next = elem;
        elem->next = q;
    }

}

void insert_after_key(NodeT** first, NodeT** last, int afterKey, int givenKey)
{
    NodeT* q = *first;
    NodeT* elem = create_list(givenKey);

    // pas 1. cautarea elementului

    while (NULL != q)
    {
        if (q->key == afterKey)
        {
            break;
        }
        q = q->next;
    }

    // pas 2. adaugarea propriu zisa

    if (NULL != q)
    {
        // cheia a fost gasita

        elem->next = q->next;
        q->next = elem;

        if (q == *last)
        {
            // cheia data e pe ultima pozitie
            *last = elem;
        }
    }
}

NodeT* search(NodeT* first, int givenKey)
{
    NodeT* p = first;
    while (NULL != p)
    {
        if (p->key == givenKey)
        {
            // cheia a fost gasita - cautarea se opreste
            return p;
        }
        p = p->next;
    }

    // cheia nu  a fost gasita
    return NULL;
}

void delete_first(NodeT** first, NodeT** last)
{
    NodeT* p;

    if (*first != NULL)
    {
        p = (*first);
        *first = (*first)->next;
        free(p);
        if (*first == NULL)
        {
            //lista avea doar un element pe care l-am sters
            *last = NULL;
        }
    }
}


void delete_last(NodeT** first, NodeT** last)
{
    // pas 1.  ajungem cu first in capatul listei
    // pas 2. stergem ultimul element

    NodeT* p = *first;
    NodeT* p1 = NULL;

    while (p != *last)
    {
        p1 = p;
        p = p->next;
    }

    if (p == *first)
    {
        // este doar un element in lista pe care il stergem
        *first = *last = NULL;
    }

    else
    {
        p1->next = NULL;
        *last = p1;
    }
    free(p);
}

void delete_key(NodeT** first, NodeT** last, int givenKey)
{
    // pas1. cautam cheia data
    // pas2. stergem cheia si refacem legaturile

    NodeT* p = *first;
    NodeT* p1 = NULL;

    while (NULL != p)
    {
        if (p->key == givenKey)
        {
            break;
        }
        p1 = p;
        p = p->next;
    }

    if (NULL != p)
    {
        if (p == *first)
        {
            //cheia se afla pe prima pozitie din lsi
            (*first) = (*first)->next;
            free(p);

            if (NULL == *first)
            {
                *last = NULL;
            }
        }
        else
        {
            p1->next = p->next;

            if (p == *last)
            {
                *last = p1;
            }

            free(p);
        }
    }
}

int main()
{
    NodeT* first, * last;
    first = last = NULL;
    insert_first(&first, &last, 333);
    //insert_before_key(&first, &last, 1222, 333);

    NodeT* p;
    p = first;
    printf("%d\n", first->key);
    insert_last(&first, &last, 777);
    //printf("%d\n", ((p->next)->next)->key);

    insert_after_key(&first, &last, 777, 1222);
    insert_after_key(&first, &last, 777, 8888);
    printf("%d %d %d %d\n", p->key, (p->next)->key, ((p->next)->next)->key, (((p->next)->next)->next)->key);

    NodeT* srch = search(first, 774447);

    if (srch == NULL)
    {
        printf("eroare! cheia nu se afla in lsi!\n");
    }
    else
    {
        printf("%d %d\n", srch->key, (srch->next)->key);
    }
   printf("%d\n",first->key);
   delete_first(&first,&last);
   printf("%d\n",last->key);


   // delete_key(&first, &last, 777);
    //printf("%d\n", (first->next)->key);

}
