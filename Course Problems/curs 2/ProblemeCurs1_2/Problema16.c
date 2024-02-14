#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode
{
    int key;
    struct StackNode* next;
}StackNode;

StackNode* top;

StackNode* CreateNode(int givenKey)
{
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->key = givenKey;
    node->next = NULL;

    return node;
}

void Push(int givenKey)
{ // ~ insert_first
    StackNode* node = CreateNode(givenKey);

    if(NULL == top)
    {
        top = node;
    }
    else
    {
        node->next = top;
        top = node;
    }
}

void Pop()
{
    // ~ delete first
    if(NULL != top)
    {
        top = top->next;
    }
}

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

void SecondHalf(QueueNode** head, QueueNode** tail, int InitialSize)
{
    if(*head == NULL)
    {

    }
    else
    {
        SecondHalf(&((*head)->next), tail,InitialSize);
        if(Size(*head, *tail) <= InitialSize / 2)
        {
            Push((*head)->key);
        }
    }
}

void Merge(QueueNode** head, QueueNode** tail)
{
    QueueNode* newH = NULL;
    QueueNode* newT = NULL;
    int count = 0;
    int InitialSize = Size(*head,*tail);

    while(count < InitialSize / 2)
    {

        Enqueue(&newH,&newT,(*head)->key);
        Enqueue(&newH,&newT,top->key);
        Pop();
        (*head) = (*head)->next;
        count++;
    }
    *head = newH;
    *tail = newT;
}
int main()
{
    QueueNode *head = NULL, *tail = NULL;
    Enqueue(&head,&tail,32);
    Enqueue(&head,&tail,41);
    Enqueue(&head,&tail,25);
    Enqueue(&head,&tail,27);
    Enqueue(&head,&tail,141);
    Enqueue(&head,&tail,49);
    Enqueue(&head,&tail,152);
    Enqueue(&head,&tail,102);

    SecondHalf(&head,&tail,Size(head,tail));

    printf("Coada initiala: ");
    PrintQueue(head);

    Merge(&head,&tail);

    printf("Coada dupa interclasare: ");
    PrintQueue(head);

    return 0;

    ///COMPLEXITATE O(N) ~ P = N + N / 2
}
