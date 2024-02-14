#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



int minim(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

int tsp_brute_force(int** dist, int* a, int l, int l_curr, int n)
{
    
    int minCost = 10000;
    if (l == n)
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", a[i]);
        }
        minCost = l_curr + dist[a[n], a[1]];
        printf("%d\n", minCost);
    }
    
    for (int i = l + 1; i <= n; i++)
    {
        
        a[l + 1] = i;

        int new_l = l_curr + dist[a[l], a[l + 1]];
        minCost = minim(minCost, tsp_brute_force(dist, a, l + 1, new_l, n));
        //a[l + 1] = aux;
    }

    return minCost;
}

int main()
{
    FILE* f = fopen("file.txt", "r");

    int n,cnt;
    fscanf(f, "%d %d", &n, &cnt);

    int dist[100][100];

    for (int i = 0; i < cnt; i++)
    {
        for (int j = 0; j < n+1; j++)
        {
            dist[i][j] = 0;
        }
        int a, b, d;
        fscanf(f, "%d %d %d", &a, &b, &d);
        printf("%d %d %d\n", a, b, d);
        dist[a][b] = dist[b][a] = d;

    }
    int* a = (int*)calloc(n + 1, sizeof(int));
   
    tsp_brute_force(dist, a, 0, 0, n);
}