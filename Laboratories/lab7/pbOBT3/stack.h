#pragma once
typedef struct stack
{
    int key;
    struct stack* next;
}St;

St* firstst;

void push(int key);
int pop();
int emptys();
void print_st();
int top();