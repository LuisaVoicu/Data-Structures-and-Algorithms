#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 7


typedef struct QueueT
{
    int array[CAPACITY];
    int head;
    int tail;
    int count;
};


void enqueue(struct QueueT* q, int key)
{
    if (q->count == 0)
    {
        
        q->head = 0;
        q->tail = 1;
        q->count = 1;
        q->array[0] = key;
        return;
    }

    if (q->count+1 > CAPACITY)
    {
        printf("overflow la %d!\n", key);
        return;
    }

    
    if (q->tail == q->head)
    {
        printf("ocupat la %d\n", key);
        return;
    }
    

    q->array[q->tail] = key;
    q->tail++;
    q->count++;
    
    if (q->tail == CAPACITY)
    {
            q->tail = 0;
    }
    
    
}



int dequeue(struct QueueT* q)
{
    if (q == NULL)
    {
        return -1;
    }

    if (q->count - 1 <= 0)
    {
       printf("underflow \n");
       return -1;
    }

    q->count--;
    if (q->head == q->tail)
    {
        printf("nu mai sunt elemente de sters!\n");
        return -1;
    }
    int el_out = q->array[q->head];
    q->head++;
    if (q->head == CAPACITY)
    {
        q->head = 0;
    }
    return el_out;
}

void print_queue(struct QueueT q)
{
    if (q.head > q.tail)
    {
        for (int i = q.head; i < CAPACITY; i++)
            printf("%d ", q.array[i]);

        for(int i = 0 ; i < q.tail;i++)
            printf("%d ", q.array[i]);
        printf("\n");
        return;
    }
    for (int i = q.head; i < q.tail; i++)
    {
        printf("%d ", q.array[i]);
    }
    printf("\n");

}


int main()
{
    struct QueueT q = { {0} ,0,0,0 };
    enqueue(&q, 1);
    enqueue(&q, 3);
    enqueue(&q, 5);
    enqueue(&q, 2);
    print_queue(q);
    int val; 
    dequeue(&q);
    dequeue(&q);
    print_queue(q);
      
    enqueue(&q, 4);
    enqueue(&q, 9);
    enqueue(&q, 2);
    enqueue(&q, 6); 
    print_queue(q);

    dequeue(&q);
    print_queue(q);

    enqueue(&q, 3);
    enqueue(&q, 7);
    print_queue(q);
    enqueue(&q, 9);


}