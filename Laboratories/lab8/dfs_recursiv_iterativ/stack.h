#pragma once
typedef struct stack
{
    int key;
    struct stack* next;
}St;

St* firstst;

void push(int key);
int pop();
int empty();
void print_st();
int top();