#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int key;
    struct Node* next;
} NodeT;

// functia va insera intre fiecare doua elemente produsul acestora
void insertProduct(NodeT* head)
{

    NodeT* q = head;
    while (q != NULL && q->next != NULL)
    {
        NodeT* p = (NodeT*)malloc(sizeof(NodeT));
        p->key = q->key * q->next->key;
        p->next = q->next;
        q->next = p;
        q = q->next->next;
    }
}

// functia va sterge fiecare al treilea element, incepand cu primul
void deleteEveryThird(NodeT** head)
{
    if (*head == NULL)
    {
        return;
    }

    int count = 0;
    NodeT* p = *head;
    NodeT* prev = NULL;
    while (p != NULL)
    {
        if (count % 3 == 0)
        {
            NodeT* aux = (NodeT*)malloc(sizeof(NodeT));

            // stergem
            if (prev == NULL)
            {
                // delete first;
                aux = p;
                *head = (*head)->next;
                p = p->next;
                free(aux);

            }
            else if(p->next == NULL)
            {
                // delete last;
                aux = p;
                prev->next = NULL;
                free(aux);
            }
            else
            {
                // stergem din interiorul listei
                aux = p;
                prev->next = p->next;
                prev = p;
                p = p->next;
                free(aux);
            }
        }
        else
        {
            prev = p;
            p = p->next;
        }
        count++;
    }

}

void insertFirst(int key, NodeT** head)
{
    NodeT* newNode = (NodeT*)malloc(sizeof(NodeT));
    newNode->key = key;

    newNode->next = (*head);
    (*head) = newNode;
}

void printList(NodeT* head)
{
    while (head)
    {
        printf("%d ", head->key);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    NodeT* head = NULL;

    insertFirst(7, &head);
    insertFirst(9, &head);
    insertFirst(6, &head);
    insertFirst(3, &head);
    insertFirst(5, &head);
    printf("Inainte de insertProduct: ");
    printList(head); // 5 3 6 8 7

    insertProduct(head);
    printf("Dupa insertProduct: ");
    printList(head); // 5 15 3 18 6 54 9 63 7

    deleteEveryThird(&head);
    printf("Dupa deleteEveryThird: ");
    printList(head); // 15 3 6 54 63 7

    return 0;
}
