#include <stdio.h>
#include <stdlib.h>
void heapify(int* h, int size,int i)
{
    int l = 2*i+1;
    int r = 2*i+2;
    int lowest;
    if(l < size && h[l] < h[i])
    {
        lowest = l;
    }
    else
    {
        lowest = i;
    }
    if(r < size && h[r] < h[lowest])
    {
        lowest = r;
    }
    if(lowest != i)
    {
        int aux = h[i];
        h[i] = h[lowest];
        h[lowest] = aux;
        heapify(h,size,lowest);
    }
}
int* insert_minheap(int*h, int* size,int key)
{
    (*size)++;
    h[*size] = key;

    int child = *size;
    int parent = (child - 1)/2;

    while(parent >= 0 && h[parent]>h[child])
    {
        int aux = h[parent];
        h[parent] = h[child];
        h[child] = aux;
        child = parent;
        parent = (child - 1)/2;

    }
    return h;

}

int get_min(int* h, int* size)
{
    if(*size >= 0)
    {
        int min = h[0];
        h[0] = h[*size];
        (*size)--;
        heapify(h,*size,0);
        return min;
    }
    return -1;
}
void print_heap(int* heap, int size)
{

    for(int i = 0 ; i <= size;i++)
    {
        printf("%d ",heap[i]);
    }
    printf("\n");
}

int min_rope(int* h, int size)
{
    int rope;
    int sum_min_rope = 0;
    if(size == 1)
    {

        return h[0]+h[1];
    }
    else
    {
        // avem cel putin 3 elem

        while(size >= 2)
        {
        int min = 1;
        int max = 2;
        if(h[1] > h[2])
        {
            min = 2;
            max = 1;
        }
        rope = h[0]+h[min];
        sum_min_rope += rope;
       // rope2 = rope1+ h[max];
        printf("%d \n",rope);

        h[0] = rope;
        h[min] = h[size];
        size--;
        heapify(h,size,0);

        //print_heap(h,size);
        printf("\n\n");
        }
        sum_min_rope += h[0]+h[1];
        return sum_min_rope;
    }

}
int main()
{
    int* heap = (int*)malloc(sizeof(int));
    int size = -1;
    /*insert_minheap(heap, &size,3);
    insert_minheap(heap, &size,7);
    insert_minheap(heap, &size,4);
    insert_minheap(heap, &size,6);
    insert_minheap(heap, &size,1);
    insert_minheap(heap, &size,2);*/

    insert_minheap(heap,&size,4);
    insert_minheap(heap,&size,3);
    insert_minheap(heap,&size,2);
    insert_minheap(heap,&size,6);



    printf("heapul initial este: \n");
    print_heap(heap,size);
    printf("dimensiunea este %d\n",size);
    printf("\n");

    /*int minim = get_min(heap,&size);
    printf("\nminimul este %d\n",minim);
    printf("\nheapul dupa extragerea minimului este:\n");
    print_heap(heap,size);
    */
    int sum = min_rope(heap,size);
    printf("suma minima este %d\n",sum);
}
