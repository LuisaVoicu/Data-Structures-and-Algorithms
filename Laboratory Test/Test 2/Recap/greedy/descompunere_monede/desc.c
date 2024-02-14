#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[] = { 1, 5, 10, 50, 100, 200, 500 };
    int n = sizeof(a) / sizeof(int);
    int sum = 132;
    for (int i = n - 1; i >= 0; i--)
    {
        while (sum - a[i] >= 0)
        {
            sum -= a[i];
            printf("%d ", a[i]);
        }
    }
}