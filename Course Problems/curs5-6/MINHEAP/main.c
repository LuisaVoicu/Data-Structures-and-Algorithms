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
    if (r <= size && heap[r] < heap[lowest])
    {
        lowest = r;
    }
    if (lowest != i)
    {
        // am gasit un copil mai mic decat parintele deci ii interschimbarm
        // si verificam prioritatea pentru urmatorul
        int aux = heap[i];
        heap[i] = heap[lowest];
        heap[lowest] = aux;
        min_heapify(heap, size, lowest);
    }
}

int* insert_minheap(int* heap, int* size, int key)
{
    if (*size == -1)
    {
        // primul si singurul element din heap
        (*size)++;
        heap[*size] = key;

    }
    else
    {
        (*size)++;
        heap[*size] = key;

        int child = *size;
        int parent = (child - 1) / 2; // pt array indexat de la 0

        while (parent >= 0 && heap[parent] > heap[child])
        {
            int aux = heap[parent];
            heap[parent] = heap[child];
            heap[child] = aux;
            child = parent;
            parent = (child - 1) / 2;
        }
    }

    return heap;
}

int get_min(int* heap, int* size)
{
    if(*size >= 0)
    {
        int min = heap[0];

        heap[0] = heap[*size];
        (*size)--;
        min_heapify(heap,*size,0);
    return min;
    }

}

void print_heap(int* heap, int size)
{

    for(int i = 0 ; i <= size;i++)
    {
        printf("%d ",heap[i]);
    }
    printf("\n");
}
int main()
{
    int* heap = (int*)malloc(sizeof(int));
    int size = -1;
    heap = insert_minheap(heap, &size,7);
    insert_minheap(heap, &size,2);
    insert_minheap(heap, &size,9);
    insert_minheap(heap, &size,4);
    insert_minheap(heap, &size,3);
    insert_minheap(heap, &size,5);
  /*  insert_minheap(heap, &size,2);
    */
    //printf("%d %d",heap[0],heap[2]);
    printf("heapul initial este: \n");
    print_heap(heap,size);
    int minim = get_min(heap,&size);
    printf("\nminimul este %d\n",minim);
    printf("\nheapul dupa extragerea minimului este:\n");
    print_heap(heap,size);


}
