#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode
{
    int key;
    struct QueueNode* next;
}QueueNode;

struct QueueHeader
{
    QueueNode* tail, * head;
    int size;
};

QueueNode* CreateNode(int givenKey)
{
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    
    node->key = givenKey;
    node->next = NULL;
    return node;
}

void EnQueue(struct QueueHeader* queue, int givenKey)
{
    // ~ insert_last
    QueueNode* node = CreateNode(givenKey);

    queue->size++;

    if (NULL == queue->head)
    {
        queue->head = queue->tail = node;
    }
    else
    {
        queue->tail->next = node;
        queue->tail = node; // MODIFICAM POZITIA COZII!!!!
    }

}

QueueNode* DeQueue(struct QueueHeader* queue)
{
    QueueNode* node = NULL;

    

    if (NULL != queue->head)
    {
        queue->size--;

        node = queue->head;
        queue->head = queue->head->next;
        
        if (NULL == queue->head)
        {
            // am sters singurul element
            queue->tail = NULL;
        }
    }

    return node;

}

int QueueSize(struct QueueHeader queue)
{
    return queue.size;
}

int QueueFront(struct QueueHeader queue)
{
    return queue.head->key;
}

int isEmpty(struct QueueHeader queue)
{
    if (NULL == queue.head)
    {
        return  1;
    }

    return 0;
}

void PrintQueue(struct QueueHeader queue)
{
    if (NULL == queue.head)
    {
        printf("COADA nu are elemente!");
    }
    else
    {
        while (NULL != queue.head)
        {
            printf("%d ", queue.head->key);
            queue.head = queue.head->next;
        }
    }

    printf("\n");
}

int main()
{
    struct QueueHeader queue = { NULL, NULL, NULL };
    QueueNode* node = NULL;

    // EnQueue  test
    EnQueue(&queue, 1);
    EnQueue(&queue, 2);
    EnQueue(&queue, 3);
    EnQueue(&queue, 4);
    PrintQueue(queue);

    // DeQueue test
    node =  DeQueue(&queue);
    printf("Am extras nodul %d !\n", node->key);
    node = DeQueue(&queue);
    printf("Am extras nodul %d !\n", node->key);
    


    EnQueue(&queue, 32);
    EnQueue(&queue, 43);
    PrintQueue(queue);

    // Front test;
    
    int k = QueueFront(queue);
    printf("Front = %d\n", k);

    // Count test;

    k = QueueSize(queue);
    printf("Count = %d\n", k);

    // isEmpty test;

    k = isEmpty(queue);
    printf("isEmpty = %d\n", k);

    DeQueue(&queue);
    DeQueue(&queue);
    DeQueue(&queue);
    DeQueue(&queue);

    k = isEmpty(queue);
    printf("isEmpty = %d\n", k);

}