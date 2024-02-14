// lista simplu inlantuita circulara;
#include <stdio.h>
#include <stdlib.h>

typedef struct NodeType{
    int key;
    struct NodeType * next;
}NodeTC;

NodeTC* create_list(int givenKey)
{
    NodeTC *p = (NodeTC*)malloc(sizeof(NodeTC));
    p->key =givenKey;
    p->next = p; // lista circulara
    return p;

}

void insert_first(NodeTC** pNode, int key)
{
    NodeTC *p = create_list(key);
    NodeTC *q = *pNode;
    NodeTC *oldest = *pNode;
    if(q == NULL)
    {
        q = p;

    }
    else
    {
        while(oldest->next != *pNode)
        {
            oldest=oldest->next;
        }

       p->next = q;
       oldest->next = p;
       q = p;

    }
    *pNode = q;
}

void insert_after_key(NodeTC** pNode, int afterKey, int key)
{
    NodeTC* q =  *pNode;
    NodeTC* p = create_list(key);


    while(*pNode != q->next)
    {
        if(q->key == afterKey)
        {
            break;
        }

        q = q->next;
    }

    if(*pNode != q->next)
    {
        p->next = q->next;
        q->next = p;

    }
    else
    {
        // ultimul element trebuie eliminat
        if(q->key == afterKey)
        {
        p->next = q->next;
        q->next = p;
        }
    }
    //*pNode = q;
}


void delete_key(NodeTC** pNode, int key)
{
    NodeTC *q = *pNode;
    NodeTC *q1 = NULL;

    while(*pNode != q->next)
    {
        if(q->key == key)
        {
            break;
        }
        q1 = q;
        q = q->next;
    }

    if(*pNode != q->next)
    {
        if(q == *pNode)
        {
            // se elimina primul element

            while(q->next != *pNode)
            {
                q = q->next;
            }
            *pNode = (*pNode)->next;
            q->next = *pNode;
        }

        else
        {
            q1->next = q->next;
        }
    }
    else
    {
        // se elimina ultimul element
        q1->next = q->next;
    }

}

NodeTC* search(NodeTC* pNode, int key)
{
    NodeTC* p = pNode;
    while(pNode != p->next)
    {
        if(p->key == key)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void print(NodeTC* pNode)
{
    NodeTC* p = pNode;

    do
    {
        printf("%d ", p->key);
        p = p->next;
    }while(pNode != p);

    printf("\n");
}
int main()
{
    NodeTC* p = NULL;
    int val;

    insert_first(&p,5);
    insert_first(&p,4);
    insert_first(&p,3);
    insert_first(&p,2);
    insert_first(&p,1);
    insert_after_key(&p,1,444);
    insert_after_key(&p,4,555);

    print(p);

    delete_key(&p,3);
    delete_key(&p,1);

    print(p);

    printf("\nIntroduceti o valoare: ");
    scanf("%d",&val);
    NodeTC* t = search(p,val);

    if(t != NULL)
        printf("\na fost gasit elementul %d si este urmat de %d\n", t->key, t->next->key);
    else
        printf("\nelementul nu a fost gasit!");

    return 0;
}
