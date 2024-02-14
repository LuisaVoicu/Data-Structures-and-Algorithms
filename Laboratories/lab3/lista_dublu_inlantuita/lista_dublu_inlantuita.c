#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct NodeType
{
    int key;
    struct NodeType* next;
    struct NodeType* prev;
}NodeDL;

struct list_header
{
    NodeDL* first;
    NodeDL* last;
};


NodeDL* CreateNode(int givenKey)
{
    NodeDL* node = (NodeDL*)malloc(sizeof(NodeDL));
    node->key = givenKey;
    node->next = node->prev = NULL;

    return node;
}


void PrintForward(struct list_header list)
{
    if (NULL == list.first)
    {
        printf("Lista este vida!");
    }
    else
    {
        while (NULL != list.first)
        {

        printf("%d ", list.first->key);
        list.first = list.first->next;
        }
    }
    printf("\n");
}

void PrintBackward(struct list_header list)
{
    if (NULL == list.first)
    {
        printf("Lista este vida!");
    }
    else
    {
         while (NULL != list.last)
         {
        printf("%d ", list.last->key);
        list.last = list.last->prev;
         }
    }

    printf("\n");
}

NodeDL* Search(struct list_header list, int givenKey)
{
    while (NULL != list.first)
    {
        if (givenKey == list.first->key)
        {
            return list.first;
        }

        list.first = list.first->next;
    }

    return NULL;
}

void InsertFirst(struct list_header* list, int givenKey)
{
    NodeDL* node = CreateNode(givenKey);

    if (NULL == list->first)
    {
        list->first = list->last = node;
    }
    else
    {printf("%d ", givenKey);
        node->next = list->first;
        list->first->prev = node;
        list->first = node;
        printf("%d \n", list->first->next->key);
    }
}

void InsertLast(struct list_header* list, int givenKey)
{
    NodeDL* node = CreateNode(givenKey);

    if (NULL == list->first)
    {
        list->first = list->last = node;
    }
    else
    {
        node->prev = list->last;
        list->last->next = node;
        list->last = node;
        printf("!!!!!!!! in functie::: %d\n", list->first->key);

    }

}

void InsertAfterKey(struct list_header* list, int afterKey, int givenKey)
{

    NodeDL* q;
    NodeDL * node = CreateNode(givenKey);

    q = Search(*list, afterKey);
    //printf("elementul este %d \n", q->key);
    if (NULL != q)
    {
        node->prev = q;
        node->next = q->next;
        if (NULL != q->next)
        {
            //nu am inserat dupa ultima pozitie
            q->next->prev = node;
        }

        q->next = node;

        if (q == list->last)
        {
            list->last = node;
        }

    }

}

void DeleteFirst(struct list_header* list)
{
    NodeDL* p = list->first;
    list->first = list->first->next;
    free(p);

    if (NULL == list->first)
    {
        list->last = NULL;
    }
    else
    {
        list->first->prev = NULL;
    }

}

void DeleteLast(struct list_header* list)
{
    NodeDL* p = list->last;
    list->last = list->last->prev;

    if (NULL == list->last)
    {
        list->first = NULL;
    }

    else
    {
        list->last->next = NULL;
    }
    free(p);
}

void DeleteKey(struct list_header* list, int givenKey)
{
    NodeDL* q = Search(*list, givenKey);

    if (NULL != q)
    {
        // elementul a fost gasit

        if (q->prev != NULL)
        {
            // nu e primul element
            q->prev->next = q->next;
        }
        else
        {
            // eliminam primul element
            list->first = q->next;
        }

        if (NULL != q->next)
        {
            // nu e ultimul element
            q->next->prev = q->prev;
        }
        else
        {
            list->last = q->prev;
        }
    }

    free(q);
}


int main()
{
    /* initialize list to empty list */
    struct list_header L = { NULL, NULL };

    /* test insertion operations */
    /* insert some elements at the beginning */
    InsertFirst(&L, 3);
    InsertFirst(&L, 4);
    InsertFirst(&L, 2);
    InsertFirst(&L, 1);
    PrintForward(L);
    InsertLast(&L, 6);
    InsertLast(&L, 8);
    InsertLast(&L, 8);
    InsertLast(&L, 8);
    PrintForward(L);
    InsertAfterKey(&L, 4, 111);
    InsertAfterKey(&L, 8, 111);
    PrintForward(L);
    PrintBackward(L);


    /* test search operation */
   //search for two distinct keys...

    int toSearch = 2;
    NodeDL* foundNode = Search(L, toSearch);
    if (foundNode == NULL) {
        printf("Node %d NOT found!\n", toSearch);
    }
    else {
        printf("Node %d found!\n", foundNode->key);
    }

    toSearch = 9;
    foundNode = Search(L, toSearch);
    if (foundNode == NULL) {
        printf("Node %d NOT found!\n", toSearch);
    }
    else {
        printf("Node %d found!\n", foundNode->key);
    }

    DeleteFirst(&L);
    DeleteLast(&L);


    /* print list contents*/
    PrintForward(L);
    PrintBackward(L);

    DeleteKey(&L, 2);
    DeleteKey(&L, 6);

    /* print list contents */
    PrintForward(L);
    PrintBackward(L);

    DeleteKey(&L, 8);
    DeleteKey(&L, 3);
    DeleteKey(&L, 111);
    DeleteKey(&L, 4);

    PrintForward(L);
    PrintBackward(L);

}
