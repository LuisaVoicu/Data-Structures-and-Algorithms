#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void merge(int* a, int low, int mid, int high)
{

    int* aux = (int*)malloc((high - low + 1) * sizeof(int));
    int index = 0;
    int i = low;
    int j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            aux[index++] = a[i++];
        }
        else 
        {
            aux[index++] = a[j++];
        }
    }
    while (i <= mid)
    {
        aux[index++] = a[i++];
    }
    while (j <= high)
    {
        aux[index++] = a[j++];
    }

    for (int i = 0; i < index; i++)
        a[low + i] = aux[i];
}


void merge_sort(int* a, int low, int high)
{
    if (low == high)
        return;
    int mid = (low + high) / 2;
    merge_sort(a, low, mid);
    merge_sort(a, mid + 1, high);
    merge(a, low, mid, high);
}



int main()
{
    int n;
    scanf("%d", &n);
    int* a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);


    merge_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

}