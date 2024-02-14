#pragma once
typedef struct node
{
    int key;
    struct node* next;
}NodeT;
NodeT* first;
NodeT* last;

NodeT* create(int key);
void enqueue(int key);
int dequeue();
int empty();
