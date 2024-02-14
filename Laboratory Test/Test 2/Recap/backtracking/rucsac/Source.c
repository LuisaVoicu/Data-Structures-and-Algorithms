#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
// de fapt e pb numararii restului


void print_sol(int* a, int* ban, int n)
{
    for (int i = 1; i <= n; i++)
        printf("%d ", ban[i]*a[i]);
    printf("\n");
}

int suma(int* a, int* ban, int k)
{
    int sum = 0;
    for (int i = 1; i <= k; i++)
        sum += a[i] * ban[i];
    return sum;
}

void backtr(int* a, int* ban, int n, int k,int sum)
{

    if (k == n + 1)
    {
        if(suma(a,ban,n)==sum)
        print_sol(a, ban, n);
        return;
    }


    int sum_partiala;
    a[k] = 0;
    sum_partiala = suma(a, ban, k);
    if(sum_partiala<=sum)
    backtr(a, ban, n, k + 1, sum);

    a[k] = 1;
    sum_partiala = suma(a, ban, k);
    if (sum_partiala <= sum)
    backtr(a, ban, n, k + 1, sum);


}




int main()
{
    int n = 6;
    int sum = 30;
    int* a = (int*)malloc(n + 1, sizeof(int));
    int ban[] = { 0,10,10,5,20,5,5 };
    backtr(a, ban, n, 1, sum);
}