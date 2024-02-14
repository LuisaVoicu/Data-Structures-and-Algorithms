#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



int valid(int* a, int k)
{
    if (a[0] % 2)return 0;
    int* freq = (int*)calloc(10, sizeof(int));
    for (int i = 0; i <= k; i++)
    {
        freq[a[i]]++;
        if (freq[a[i]] > 2)return 0;
    }/**/
    for (int i = 0; i < k; i++)
        if (a[i] == a[k])
            return 0;
    return 1;
}
int is_sol(int* a, int k,int n)
{
    if (k != n)return 0;
    if (a[n - 1] != 0 && a[n - 1] != 5)return 0;
    int cnt_odd = 0;
    int sum_odd = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2)cnt_odd++;
        if (cnt_odd > 3)return 0;
        if (i % 2)sum_odd += a[i];
    }
    if (sum_odd % 3)return 0;
    return 1;
}

void print_sol(int* a, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d", a[i]);
    printf("\n");
}

void backtr(int* a, int n, int k, int*cnt_sol)
{
   // printf("hello %d %d\n",k, is_sol(a, k, n));
    if (k > n + 1)return;
    
    if (is_sol(a,k,n))
    {
        (*cnt_sol)++;
        print_sol(a, n);
        return;
    }
    
    for (int i = 0; i <= 9; i++)
    {
        a[k] = i;
        if (valid(a, k))
            backtr(a, n, k + 1,cnt_sol);
    }
}

int main()
{
    int n = 6;
    int cnt_sol = 0;
    int* a = (int*)calloc(n, sizeof(int));
    backtr(a, n, 0,&cnt_sol);
    printf("\n nr_sol:%d", cnt_sol);
}