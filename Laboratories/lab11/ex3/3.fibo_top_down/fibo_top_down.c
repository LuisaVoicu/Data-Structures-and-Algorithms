#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define UNKNOWN -1



long fibo(int* f, int n)
{
    if (f[n] == UNKNOWN)
        f[n] = fibo(f, n - 1) + fibo(f, n - 2);
    return f[n];
}


long fibo_initializare(int n)
{
    int* f = (int*)calloc(n+1, sizeof(int));
    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        f[i] = UNKNOWN;
    }
    
    return fibo(f, n);

}

int main()
{
    int num = 7;
    long fib = fibo_initializare(num);
    printf("fibonacci[%d] = %ld\n",num, fib);
}