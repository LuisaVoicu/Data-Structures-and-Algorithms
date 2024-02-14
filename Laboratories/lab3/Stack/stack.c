#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode
{
    int key;
    struct StackNode* next;
}StackNode;

struct StackHeader
{
    StackNode* top;
    int size;
};

StackNode* CreateNode(int givenKey)
{
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->key = givenKey;
    node->next = NULL;
    return node;
}

void Push(struct StackHeader* stack, int givenKey)
{
    // ~ insert_first

    StackNode* node = CreateNode(givenKey);
    stack->size++;

    if (NULL == stack->top)
    {
        stack->top = node;
    }
    else
    {
        node->next = stack->top;
        stack->top = node;
    }

}

StackNode* Pop(struct StackHeader* stack)
{
    // ~delete_first

    StackNode* node = NULL;
    stack->size--;

    if (NULL != stack->top)
    {
        node = stack->top;
        stack->top = stack->top->next;
    }

    return node;
}

int StackSize(struct StackHeader stack)
{
    return stack.size;
}

int Top(struct StackHeader stack)
{
    return stack.top->key;
}

int isEmpty(struct StackHeader stack)
{
    if (NULL == stack.top)
    {
        return 1;
    }

    return 0;
}

void PrintStack(struct StackHeader stack)
{
    if (NULL == stack.top)
    {
        printf("Stiva nu are elemente!");
    }
    else
    {
        while (NULL != stack.top)
        {
            printf("%d ", stack.top->key);
            stack.top = stack.top->next;
        }
    }

    printf("\n");

}
int main()
{
    struct StackHeader stack = { NULL, NULL };
    
    // test Push
    Push(&stack, 1);
    Push(&stack, 2);
    Push(&stack, 3);
    Push(&stack, 4);
    PrintStack(stack);

    // test Pop
    StackNode *node = Pop(&stack);
    node = Pop(&stack);
    node = Pop(&stack);
    node = Pop(&stack);
    printf("A fost extras elementul %d !\n", node->key);
    PrintStack(stack);

    // test Top
    Push(&stack, 11);
    Push(&stack, 22);
    Push(&stack, 33);
    PrintStack(stack);
    int k = Top(stack);
    printf("Top = %d\n", k);

    // test Size
    k = StackSize(stack);
    printf("Size = %d\n", k);

    // test isEmpty;
    k = isEmpty(stack);
    printf("Empty = %d\n", k);
    Pop(&stack);
    Pop(&stack);
    Pop(&stack);
    k = isEmpty(stack);
    printf("Empty = %d\n", k);
}