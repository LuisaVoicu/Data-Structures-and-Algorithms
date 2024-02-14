#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct Data{
    char *nume;
    int nota;
}Data;

typedef struct NodeType{
    Data key;
    struct NodeType* next;
}NodeT;

NodeT* create_list(Data key)
{
    NodeT* q = (NodeT*)malloc(sizeof(NodeT));

    if(NULL == q)
    {
        // nu se poate realiza alocarea dinamica
        exit(1);
    }

    //q->key.nume = (char*)malloc(MAX * sizeof(char));

   // if(NULL == q->key.nume)
    {
        // nu se poate realiza alocarea dinamica
      //  exit(2);
    }

    q->key = key;
    q->next = NULL;
    return q;

}

void insert_last(NodeT** first, NodeT** last, Data givenKey)
{
    NodeT* p = *first;
    NodeT* q = *last;
    NodeT* elem = create_list(givenKey);

    if(NULL == p)
    {
        p = elem;
        q = elem;
    }
    else if( NULL != q)
    {
        q->next = elem;
        q = elem;
    }

    *first = p;
    *last = q;
}

void delete_key(NodeT** first, NodeT** last, NodeT* p)
{

    NodeT* frst = *first;
    NodeT* lst = *last;
    NodeT* p1 = p;
    p = p->next;

    if(p != NULL)
    {
      if(p == frst)
    {
        //eliminarea primului element dintr-o lista
        frst = (frst)->next;

        if(NULL == frst)
        {
            // am eliminat singurul element din lista
            lst = NULL;
        }
    }
    else
    {
        //exista mai mult de un element in lista
        p1->next = p->next;

        if(p == lst)
        {
            // cheia eliminata se afla la capatul listei
            lst = p1;
        }
    }
    }

}

int main()
{
    int n;
    Data aux;
    aux.nume = (char*)malloc(MAX * sizeof(char));

    if(NULL == aux.nume)
    {
        printf("Nu poate fi alocata memorie!");
        exit(3);
    }

    NodeT* first = NULL;
    NodeT* last = NULL;
    NodeT* p ;
    printf("introduceti numarul de elevi: ");
    scanf("%d",&n);
    printf("introduceti numele si nota fiecarui elev:\n");
    for(int i = 1 ; i <= n; i++)
    {
        printf("%d : ", i);
        scanf("%s %d", aux.nume, &aux.nota);
        printf("nume %s\n",aux.nume);
        insert_last(&first, &last, aux);
        printf("nume %s\n",first->key.nume);
        /*
        in enuntul problemei se precizeaza ca este dat un poiner
        la un elev cu nota < 5 ;
        adaptare: retin din citire adresa unui elev ce are nota < 5
        */
        if(aux.nota < 5)
        {
            p = last;
           // printf(".. %p %p\n",p, first->next);
        }

    }
    printf("%p %p\n", p->next, first->next->next);
printf("%s\n",first->next->next->key.nume);

printf("%s\n", first->key.nume);
    delete_key(&first, &last, p);

    //printf("%d %s %s", first->key.nota, first->next->key.nume, first->next->next->key.nume);
    printf("%s\n", first->key.nume);
    return 0;
}
