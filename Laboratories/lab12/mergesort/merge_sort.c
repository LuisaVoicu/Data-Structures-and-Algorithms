#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



void merge(int* a, int l, int mid, int r)
{
    int i = l, j = mid + 1;
    int* aux = (int*)malloc(sizeof(int) * (r - l));
    int k = l;
    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
        {
            aux[k++] = a[i++];
        }
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
    int a[] = { 1,2 };
    int i = 0;
    printf("%d", a[i++]);

}