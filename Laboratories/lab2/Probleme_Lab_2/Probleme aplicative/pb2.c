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

void print_list(NodeT* first)
{
    NodeT* p;
    p = first;

    if(NULL == p)
    {
        printf("Lista vida!");
    }

    while(NULL != p)
    {
        printf("%d ",p->key);
        p = p->next;
    }

}


void intersection_list(NodeT* a, NodeT* b, NodeT** first, NodeT** last)
{
    NodeT* p = a;
    NodeT* q = b;
    NodeT* frst = NULL , * lst = NULL;

    while( NULL != p && NULL != q)
    {
        if(p->key < q->key)
        {
            p = p->next;
        }
        else if(p->key > q->key)
        {
            q = q->next;
        }
        else if(p->key == q->key)
        {
            insert_last(&frst, &lst, p->key);
            p = p->next;
            q = q->next;
        }
    }

    //printf("inters in fct: ");
    //print_list(frst);
    *first = frst;
    *last = lst;
    free(p);
    free(q);
}

void union_list(NodeT* a, NodeT* b, NodeT** first, NodeT** last)
{
    NodeT* p = a;
    NodeT* q = b;
    NodeT* frst = NULL , * lst = NULL;

    while( NULL != p && NULL != q)
    {
        if(p->key < q->key)
        {
            insert_last(&frst, &lst, p->key);
            p = p->next;
        }
        else if(p->key > q->key)
        {
            insert_last(&frst, &lst, q->key);
            q = q->next;
        }
        else if(p->key == q->key)
        {
            insert_last(&frst, &lst, p->key);
            p = p->next;
            q = q->next;
        }
    }

    *first = frst;
    *last = lst;
    /*
    free(p);
    free(q)
    */ // ---------> de ce nu pot face dealocare?
}


int main()
{
    FILE *pf , *qf;
    pf = fopen("F1.txt","r");
    qf = fopen("F2.txt","r");

    if(NULL == pf)
    {
        printf("Eroare! Fisierul F1 nu poate fi deschis!");
        exit(1);
    }

    if(NULL == qf)
    {
        printf("Eroare! Fisierul F2 nu poate fi deschis!");
        exit(2);
    }

    NodeT *firstA = NULL, *lastA = NULL, *firstB = NULL, *lastB = NULL;
    int nr;
    char ch;

    do
    {
        fscanf(pf,"%d%c",&nr,&ch);
        insert_last(&firstA,&lastA,nr);

    }while(ch == ' ');

    do
    {
        fscanf(qf,"%d%c",&nr,&ch);
        insert_last(&firstB,&lastB,nr);

    }while(ch == ' ');

    NodeT *interF , *interL;
    intersection_list(firstA,firstB,&interF,&interL);
    printf("Intersetie: ");
    print_list(interF);

    NodeT *unionF , *unionL;
    union_list(firstA,firstB,&unionF,&unionL);
    printf("\nReuniune: ");
    print_list(unionF);


    return 0;
}
