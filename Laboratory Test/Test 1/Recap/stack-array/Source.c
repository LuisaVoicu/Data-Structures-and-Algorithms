#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 6

struct St
{
    int array[CAPACITY];
    int top;
    int count;
};

void push(struct St* s, int key)
{
    if(s->count + 1 > CAPACITY)
    { 
        printf("overflow pt %d\n", key);
        return;
    }
    s->array[s->top] = key;
    s->count++;
    s->top++;

}

int pop(struct St* s)
{
    if (s->count <= 0)
    {
        printf("underflow!\n");
    }
    int ret = s->array[s->top-1];
    //printf(".....ret %d\n", ret);
    s->count--;
    s->top--;
    return ret;
}

void print_stack(struct St s)
{
    for (int i = 0; i < s.top; i++)
    {
        printf("%d ", s.array[i]);
    }
    printf("\n");
}
int main()
{
    struct St s = { {0},0,0 };
    push(&s, 2);
    push(&s, 5);
    push(&s, 7);
    push(&s, 1);
    print_stack(s);
    int k = pop(&s);
    printf("s-a scos %d\n", k);
    print_stack(s);
    push(&s, 21);
    push(&s, 31);
    push(&s, 41);
    push(&s, 51);
    print_stack(s);

}