#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



int valid(int* a, int k)
{
    for (int i = 1; i < k; i++)
        if (a[i] == a[k])
            return 0;
    return 1;
}


void print_solution(int* a, int k)
{
    for (int i = 1; i < k; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void backtr(int* a, int n, int k)
{
  
        if(k==n+1)
        print_solution(a, k);
        if (k > n + 1)
            return;

        for (int i = 1; i <= n; i++)
        {
            a[k] = i;
            if (valid(a, k))
            {
                backtr(a, n, k + 1);
            }
        }

    

}


int main()
{
    int n = 3;
    int* a = (int*)malloc((n+1)*sizeof(int));

    backtr(a, n, 1);
}