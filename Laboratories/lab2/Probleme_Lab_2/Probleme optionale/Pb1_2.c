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

    printf("\n");
}

void PO1(NodeT** first)
{
    NodeT* current = *first;
    NodeT* prev = NULL;
    NodeT* next = NULL;

    while(NULL != current)
    {
        // retinem urmatorul element
        next = current->next;

        // "intoarcem" elementul anterior ~ schimbam directia spre care pointeaza acesta
        current->next = prev;

        // procedam analog pentru toate elementele, pana la finalul listei
        prev = current;
        current = next;

    }

    *first = prev;

}
void PO2(NodeT** first, int givenKey)
{
    NodeT* p = *first;
    NodeT* elem = create_list(givenKey);


    // inserare pe prima pozitie
    if(p == NULL)
    {
        *first = elem;
    }
    else
    {
        if(p->next == NULL)
        {
                // inserez pe orice pozitie, nu va afecta monotonia sirului
                elem->next = NULL;
                p->next = elem;
        }
        else
        {
            // inserarea pe prima pozitie
            if((givenKey <= p->key && p->key <= p->next->key) ||
               (givenKey >= p->key && p->key >= p->next->key) )
            {

                elem->next = *first;
                *first = elem;
            }
            else
            {
            // inserare in interiorul listei
                while(NULL != p->next)
                {
                    if((p->key <= givenKey && givenKey <= p->next->key) ||
                        (p->key >= givenKey && givenKey >= p->next->key) )
                    {
                        break;
                    }

                    p = p->next;
                }

                if(NULL != p->next)
                {

                    elem->next = p->next;
                    p->next = elem;

                }
                else
                {
                //inserare dupa ultimul element
                elem->next = NULL;
                p->next = elem;
                }
            }
        }
    }


}

int main()
{
    NodeT* first = NULL;
    NodeT* last = NULL;
    int val;

    insert_last(&first,&last,1);
    insert_last(&first,&last,2);
    insert_last(&first,&last,23);
    insert_last(&first,&last,204);

    PO1(&first);
    printf("Lista inversata este: ");
    print_list(first);

    printf("Introduceti o valoare: ");
    scanf("%d",&val);

    PO2(&first,val);
    printf("Lista (inversata) dupa adaugarea valorii %d este: ", val);
    print_list(first);
    return 0;
}
