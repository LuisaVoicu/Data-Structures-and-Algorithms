#include <stdio.h>
#include <stdlib.h>

typedef struct NodeType {
    int key;
    struct NodeType* next;
}NodeT;


void merge_list(NodeT** a_first, NodeT** a_last, NodeT** b_first, NodeT** b_last)
{
    NodeT* pf = *a_first;
    NodeT* pl = *a_last;
    NodeT* qf = *b_first;
    NodeT* ql = *b_last;

    while(NULL != pf && NULL != qf)
    {

        if(pf->key > qf->key)
        {
            insert_before_key(a_first,a_last,pf->key,qf->key);
            qf = qf->next;
        }
        else if(pf->key < qf->key)
        {
            // nu se efectueaza nici o modificare la lista pf
            pf = pf->next;
        }
        else if(pf->key == qf->key)
        {
            pf = pf->next;
            qf = qf->next;
        }
    }
    while( NULL != qf)
    {
        insert_last(a_first,a_last,qf->key);
        qf = qf->next;
    }

    *b_first = qf;
    *b_last = qf;
}

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

NodeT* Search(NodeT* first, int givenKey)
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
        p = (*first)->next;
        *first = (*first)->next;
        //free(p);   ////////////// <( --- eroare??
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

    printf("\n");
}

void swap_list_element(NodeT* p, NodeT* q)
{
    int aux = p->key;
    p->key = q->key;
    q->key = aux;
}

void sort_list(NodeT** first, NodeT** last)
{
    // bubble sort
    NodeT* p;
    NodeT* p1 = NULL;
    int swapped;

     do{
        swapped = 0;
        p = *first;

        while( p->next != p1)
        {
            if(p->key > (p->next)->key)
            {
               swap_list_element(p,p->next);
               swapped = 1;
            }
            p = p->next;
        }
        p1 = p;

    }while(swapped);

}

int main()
{
    FILE *pf = fopen("input.txt","r");

    if(NULL == pf)
    {
        printf("Eroare! Nu poate fi deschis fisierul!");
        exit(1);
    }


    char **s = (char**)malloc(sizeof(char*) * 6);
    if(NULL == s)
    {
        printf("Eroare! Tabloul nu poate fi alocat dinamic.");
        exit(2);
    }

    for(int i = 0 ; i < 10; i++)
    {
        s[i] = (char*)malloc(sizeof(char) * 100);
        if(NULL == s[i])
        {
            printf("Eroare! Tabloul nu poate fi alocat dinamic");
            exit(3);
        }
    }

    NodeT *first1 = NULL , *last1 = NULL;
    NodeT *first2 = NULL , *last2 = NULL;
    int nr=2;
    create_list(nr);

    while(!feof(pf))
    {
        char sir[100], c;

        fscanf(pf,"%s%c",sir,&c);
        if(!feof(pf))
        {
            if(sir[0] == 'i')
        {
            char index = sir[1];
            do{
            fscanf(pf,"%s%c", sir, &c);

            //conversie de la string la numar
            int nr;
            sscanf(sir,"%d", &nr);

            if(index == '1')
            {
                insert_last(&first1,&last1,nr);
            }

            if(index == '2')
            {
                insert_last(&first2,&last2,nr);
            }

            }while(c==' ');

            if(index == '1')
            {
                sort_list(&first1,&last1);
            }

            if(index == '2')
            {
                sort_list(&first2,&last2);
            }

        }

        if(sir[0] == 'p')
        {   // operatie de tipul afisare
            char index = sir[1];

            if(index == '1')
            {
               print_list(first1);
            }

            if(index == '2')
            {
                print_list(first2);
            }
        }

        if(sir[0] == 'm')
        {
            // operatie de tipul interclasare
            merge_list(&first1,&last1,&first2,&last2);

        }
        }
    }



    return 0;
}
