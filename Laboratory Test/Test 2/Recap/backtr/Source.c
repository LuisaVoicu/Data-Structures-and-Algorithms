#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



int suma(int* a, int* vals, int k)
{
    int s = 0;
    for (int i = 1; i <= k; i++)
    {
        s += vals[a[i]];
    }
    //printf("%d\n",s);
    return s;
}

void print_sol(int* a, int* vals, int k)
{
    for (int i = 1; i <= k; i++)
    {
        printf("%d ", vals[a[i]]);
    }
    printf("\n");
}


int valid(int* a, int k)
{
    for (int i = 1; i < k; i++)
    {
        if (a[i] == a[k])
            return 0;
    }
    return 1;
}


void backtr(int* a, int* vals, int n, int k,int sum)
{
    if (suma(a, vals, k-1) == sum)
 //   if(n==k-1)
    {
        print_sol(a, vals, k-1);
        return;
    }

    for (int i = a[k-1]+1; i <= n; i++)
    {
        //printf("%d\n", i);
        a[k] = i;
        if (valid(a, k) && suma(a, vals, k) <= sum)
        {
            backtr(a, vals, n, k+1, sum);
        }
    }
    
}
    

int main()
{
    int vals[] = { 0,1,-3,5,-7,2,6 };
    int n = sizeof(vals) / sizeof(int);
    n--;
    int* a = (int*)calloc(n + 1, sizeof(int));
    int sum = 6;
    backtr(a, vals, n, 1, sum);
}