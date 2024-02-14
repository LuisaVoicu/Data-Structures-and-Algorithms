#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define CAPACITY

void min_heapify(int* heap, int size,int i)
{
    int l = 2 * i + 1; // heap INDEXAT DE LA 0 !!!!
    int r = 2 * i + 2;
    int lowest;
    if (l <= size && heap[l] < heap[i])
    {
        lowest = l;
    }
    else
    {
        lowest = i;
    }
    if (r <= size && heap[r] < heap[i])
    {
        lowest = r;
    }
    if (lowest != i)
    {
        // am gasit un copil mai mic decat parintele deci ii interschimbarm
        // si verificam prioritatea pentru urmatorul
        int aux = heap[i];
        heap[i] = heap[lowest];
        min_heapify(heap, size, lowest);
    }
}

int* insert_minheap(int* heap, int* size, int key)
{
    if (*size == 0)
    {
        // primul si singurul element din heap
        heap[*size] = key;
        (*size)++;
    }
    else
    {
        heap[*size] = key;
        (*size)++;
       
        int child = (*size - 1);
        int parent = (child - 1) / 2; // pt array indexat de la 0
        printf("%d .. %d %d",key, parent, child);
        while (parent >= 0 && heap[parent] > heap[child])
        {printf("~%d %d", parent, child);
            int aux = heap[parent];
            heap[parent] = heap[child];
            heap[child] = aux;
            child = parent;
            parent = (child - 1) / 2;
        }
        printf("%d \n", heap[child]);
        printf("\ne ok...\n");
    }
    printf("\ne ok...\n");
    return heap;
}

int main()
{
    int* heap = (int*)malloc(sizeof(int));
    int size = 0;
    heap = insert_minheap(heap, &size,1);
    heap = insert_minheap(heap, &size,2);
    heap = insert_minheap(heap, &size,3);


}