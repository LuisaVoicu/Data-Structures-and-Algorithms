#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>




int partitie(int* a, int low, int high)
{
    int pivot = a[high];
    int nod = low - 1;

    for (int i = low; i < high; i++)
    {
        if (a[i] <= pivot)
        {
            // incrementam nod
            nod++;
            // interschimb elementul curent cu elementul din nod
            int aux = a[i];
            a[i] = a[nod];
            a[nod] = aux;
        }
    }

    nod++;
    int aux = a[high];
    a[high] = a[nod];
    a[nod] = aux;
    return nod;
}


void quick_sort(int* a, int low, int high)
{
    if (low >= high)
        return;

    int part = partitie(a, low, high);
    quick_sort(a, low, part - 1);
    quick_sort(a, part + 1, high);
}

int main()
{
    int a[] = { 4,89,-12,53,0,12 };
    int n = sizeof(a) / sizeof(int);
    
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    quick_sort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");


}