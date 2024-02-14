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

int tsp_brute_force(int* dist, int* a, int l, int l_curr, int n)
{
    int minCost = 10000;
    if (l == n)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        }
        minCost = l_curr + dist[a[n], a[1]];
        printf("%d\n", minCost);
    }

    for (int i = l + 1; i <= n; i++)
    {
        a[l + 1] = a[i];
        int new_l = l_curr + dist[a[l], a[l + 1]];
        minCost = minim(minCost, tsp_brute_force(dist, a, l + 1, new_l, n));

    }

    return minCost;
}

int main()
{
    FILE* f = fopen("file.txt", "r");

    int n,cnt;
    fscanf(f, "%d %d", &n, &cnt);

    int** dist = (int**)calloc(n+1,sizeof(int*));

    for (int i = 0; i < cnt; i++)
    {
        dist[i] = (int*)calloc(n+1, sizeof(int));

        int a, b, d;
        fscanf(f, "%d %d %d", &a, &b, &d);
        printf("%d %d %d\n", a, b, d);
        dist[a][b] = dist[b][a] = d;
    }
    int* a = (int*)calloc(n + 1, sizeof(int));

}
