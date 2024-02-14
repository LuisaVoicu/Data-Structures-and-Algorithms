#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode
{
    int key;
    struct QueueType* next;
}QueueNode;


QueueNode* create_node(int givenKey)
{
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    node->key = givenKey;
    node->next = NULL;

    return node;
}

void Enqueue(QueueNode** head, QueueNode** tail, int givenKey)
{
    // ~ insert_last
    QueueNode* node = create_node(givenKey);

    if(NULL == *tail)
    {
        *head = *tail = node;
    }
    else
    {
       (*tail)->next = node;
       (*tail) = node;
    }


}

void Dequeue(QueueNode** head, QueueNode** tail)
{
    // ~ delete_first
    if(NULL != *head)
    {
       *head = (*head)->next;

       if(NULL == *head)
       {
            *tail = NULL;
       }
    }

    else
    {
        // coada nu are elemente
        return NULL;
    }

}

int isEmpty(QueueNode* head)
{
    if(NULL == head)
    {
        return 1;
    }

    return 0;
}

int Front(QueueNode* head)
{
    if(NULL != head)
    {
        return head->key;
    }
}

int Size(QueueNode* head, QueueNode* tail)
{
    if(NULL == head)
    {
        // nu exista elemente in codata
        return 0;
    }

    int count = 1;
    while(head != tail)
    {
        count++;
        head = head->next;
    }

    return count;
}

void PrintQueue(QueueNode* H)
{
    while(NULL != H)
    {
        printf("%d ",H->key);
        H = H->next;
    }
    printf("\n");
}

void ReverseQueue(QueueNode** H, QueueNode** T)
{
    if(*H == *T)
    {
        // conditie de oprire
    }
    else
    {

        ReverseQueue(&((*H)->next),T);

        int k = Front(*H);
        Dequeue(H,T);
        Enqueue(H,T,k);
    }
}
int main()
{
    int k;

    QueueNode *head = NULL, *tail = NULL;
    Enqueue(&head,&tail,1);
    Enqueue(&head,&tail,2);
    Enqueue(&head,&tail,3);
    Enqueue(&head,&tail,4);
    Enqueue(&head,&tail,5);

    printf("Coada initiala: ");
    PrintQueue(head);

    ReverseQueue(&head,&tail);

    printf("Coada inversata: ");
    PrintQueue(head);

    return 0;

    /// COMPLEXITATE O(N)
}
