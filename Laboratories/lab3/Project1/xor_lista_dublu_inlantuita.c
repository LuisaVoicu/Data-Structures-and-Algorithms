#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct NodeType
{
    int key;
    struct NodeType* pn;
}NodeDL;

struct list_header
{
    int size;
    NodeDL* first;
    NodeDL* last;
};

NodeDL* create_node(int *givenKey)
{
    NodeDL* node = (NodeDL*)malloc(sizeof(NodeDL));
   
    node->key = *givenKey;
    node->pn = givenKey;
    
    return node;
}

void insert_last(struct list_header* xorList, int* givenKey)
{
   
   
    xorList->size++;
    printf("\n%p %d\n", givenKey, *givenKey);
    if (xorList->size == 1)
    {
        // inseram primul element din lista
        xorList->first = create_node(givenKey);
    }
    else if (xorList->size == 2)
    {
        // inseram ( la final) al doilea element din lista
        xorList->last = create_node(givenKey);
    }
    else
    {
        // exista 2 elemente deja in lista ( il inseram la final pe cel de-al 3 lea)
        // putem parcurge deci lista cu ajutorul formulei
        /*
          A XOR B = C // C = current   = last
          C XOR A = B // B = next      = ????
          C XOR B = A // A = previous  = first
        */
        int* A = NULL, * C = NULL, * B = NULL;

        A = xorList->first->pn;
        C = xorList->last->pn;

        /*int a = (int)A;
        int c = (int)C;
        int b = a ^ c;*/

        B = (int*)((int)A ^ (int)C);
        xorList->first->pn = C;
        
        xorList->first->pn->pn = B;
        xorList->last->pn = B;

        //xorList->last->pn->pn->key = givenKey;
        printf("%d %d %d\n", xorList->first->key, xorList->first->pn->key, xorList->last);
    }


    /*
     else
    {
        int A, B, C;
        C = node->current; // adresa current ~ list->last->current->current
        A = xorList->last->current; // adresa prev
        B = C ^ A; // adresa next list->last->current->current->current
        xorList->last->current->current = C;
        xorList->last->current->current->key = node->key;
        xorList->last->current->current->current = B;


    }
    */
   
}

int main()
{
    //create_node(2);
    struct list_header xor = {NULL, NULL, NULL};
    int a = 1, b = 2 , c=3;
    printf("%p %p\n", &a, &b);
    insert_last(&xor, &a);
    insert_last(&xor, &b);
    insert_last(&xor, &c);
    printf("%p %p\n", xor.first->pn, xor.last->pn);

    /*int* p = NULL;
    int a = 2;
    p = &a;
    int aa = (int)p;
    printf("%p %p", p, aa);*/
}