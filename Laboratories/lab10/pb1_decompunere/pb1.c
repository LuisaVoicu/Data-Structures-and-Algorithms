#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void quickSort(int* v, int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        int aux = v[l];
        v[l] = v[m];
        v[m] = aux;

        int i = l, j = r, d = 0;
        while (i < j)
        {
            if (v[i] > v[j])
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
                d = 1 - d;
            }
            i += d;
            j -= 1 - d;
        }
        quickSort(v, l, i - 1);
        quickSort(v, i + 1 , r);

    }
}


int main()
{
    FILE* f = fopen("file.txt", "r");

    int n, m = 0;
    fscanf(f, "%d", &n);
    int* v = (int*)malloc(sizeof(int) * n);
    int* w = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        fscanf(f, "%d", &v[i]);
    }
    quickSort(v, 0, n - 1);


    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
    int sum;
    fscanf(f, "%d", &sum);

    for (int i = n - 1; i >= 0; i--)
    {
        while (sum - v[i] >= 0)
        {
            sum = sum - v[i];
            w[m++] = v[i];
            
        }
        if (sum == 0)
            {
                break;
            }
    }

    for (int i = 0; i < m; i++)
    {
        printf("%d ", w[i]);
    }

}