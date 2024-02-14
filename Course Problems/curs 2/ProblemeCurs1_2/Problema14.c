#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode
{
    int key;
    struct StackNode* next;
}StackNode;

StackNode* CreateNode(int givenKey)
{
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->key = givenKey;
    node->next = NULL;

    return node;
}

void Push(StackNode** top, int givenKey)
{ // ~ insert_first
    StackNode* node = CreateNode(givenKey);

    if(NULL == *top)
    {
        *top = node;
    }
    else
    {
        node->next = *top;
        *top = node;
    }
}

void Pop(StackNode** top)
{
    // ~ delete first
    if(NULL != *top)
    {
        *top = (*top)->next;
    }
}

int Size(StackNode* top)
{
    int count = 0;

    while(NULL != top)
    {
        count++;
        top = top->next;
    }

    return count;
}

int isEmpty(StackNode* top)
{
    if(NULL == top)
    {
        return 1;
    }

    return 0;
}

int Top(StackNode* top)
{
    if(NULL != top)
    {
        return top->key;
    }
}
void PrintStack(StackNode* top)
{
    while(NULL != top)
    {
        printf("%d ",Top(top));
        top = top->next;
    }
    printf("\n");
}
void ReverseStack(StackNode** top, StackNode** reversed)
{
    if(NULL == *top)
    {
        top = reversed;
    }
    else
    {
        Push(reversed,Top(*top));
        ReverseStack(&((*top)->next),reversed);
    }
}

int main()
{
    StackNode *top = NULL;
    StackNode *rev = NULL;

    Push(&top,1);
    Push(&top,2);
    Push(&top,3);
    Push(&top,4);
    Push(&top,5);


    printf("Stiva initiala: ");
    PrintStack(top);
    ReverseStack(&top,&rev);
    top = rev;

    printf("Stiva inversata: ");
    PrintStack(top);

    return 0;

    /// COMPLEXITATE O(N)
}
