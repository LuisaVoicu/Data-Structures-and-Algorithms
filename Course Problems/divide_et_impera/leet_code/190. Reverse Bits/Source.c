#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


long long bin(char* a, int n)

{ 
    if (n == 0)
        return 0;
    return 2 * bin(a, n - 1) + a[n - 1] - '0';
}

int main()
{
    char a[] = "0111";
    int n = 4;
    long long k = bin(a, n);
    printf("%d", k);
}