#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node* next;
}NodeT;

NodeT* create(int key)
{
    NodeT* node = (NodeT*)malloc(sizeof(NodeT));
    node->key = key;
    node->next = NULL;
    return node;
}

void push(NodeT** first, int key)
{
    NodeT* node = create(key);

    if (*first == NULL)
    {
        *first = node;
        return;
    }
    node->next = *first;
    *first = node;

}

int pop(NodeT** first)
{
    if (*first == NULL)
    {
        printf("underflow!\n");
        return -1;
    }
    int el_out = (*first)->key;
    NodeT* p = *first;

    *first = (*first)->next;
    free(p);
    return el_out;
}
void print_stack_contents(NodeT* stack)
{
    while (stack != NULL)
    {
        printf("%d ", stack->key);
        stack = stack->next;
    }
    printf("\n");
}


int main()
{
    NodeT* stack = NULL; //this is the top of the stack (the reference to ...)

    push(&stack, 8);
    push(&stack, 4);
    push(&stack, 3);
    push(&stack, 6);

    print_stack_contents(stack); //6 3 4 8

    pop(&stack);
    pop(&stack);

    print_stack_contents(stack); //4 8

    push(&stack, 2);
    push(&stack, 6);

    print_stack_contents(stack); //6 2 4 8

    pop(&stack);
    pop(&stack);
    pop(&stack);

    print_stack_contents(stack); //8

    pop(&stack);
    pop(&stack);


}