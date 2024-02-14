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
    if(NULL == top)
    {
        printf("Stiva este goala!");
    }
    else
    {
        while(NULL != top)
        {
            printf("%d ",Top(top));
            top = top->next;
        }
    }

    printf("\n");
}

void DeleteMiddle(StackNode** top,int InitialSize)
{
    if(Size(*top) == (InitialSize + 1)/2)
    {
        // am gasit mijlocul
        Pop(top);
    }

    else
    {
        DeleteMiddle(&((*top)->next),InitialSize);
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
    Push(&top,6);
    Push(&top,7);

    printf("Stiva initiala: ");
    PrintStack(top);

    DeleteMiddle(&top,Size(top));
    printf("\nStiva dupa eliminarea elementului din mijloc: ");
    PrintStack(top);

    return 0;

    /// COMPLEXITATE O(N) ~ P = N / 2
}
