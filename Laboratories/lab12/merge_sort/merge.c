#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



void merge(int* a, int l, int mid, int r)
{
    int i = l, j = mid + 1;
    int* aux = (int*)malloc(sizeof(int) * (r - l+1));
    int k = l;

    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
        {
            aux[k++] = a[i++];
        }
        else
        {
            aux[k++] = a[j++];
        }
    }

    while (i <= mid)
    {
        aux[k++] = a[i++];
    }

    while (j <= r)
    {
        aux[k++] = a[j++];
    }

    for (int i = l; i <= r; i++)
    {
        a[i] = aux[i];
    }
}

void mergeSort(int* a, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int mid = (l + r) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);
    merge(a, l, mid, r);
}

int main()
{

    int a[] = {1,9,0,14,3,29,-43};
    int n = 7;

    mergeSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

}