#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


long fibo_bu(int n)
{
    // cu forgetting
    long first = 0;
    long second = 1;
    long third;
    if (n == 0)
        return first;
    if (n == 1)
        return second;
    for (int i = 2; i <= n; i++)
    {
        third = first + second;
        first = second;
        second = third;
    }
    return third;
}
int main()
{
    int num = 7;
    long fibo = fibo_bu(num);
    printf("fibonacci[%d] = % d\n", num, fibo);
}