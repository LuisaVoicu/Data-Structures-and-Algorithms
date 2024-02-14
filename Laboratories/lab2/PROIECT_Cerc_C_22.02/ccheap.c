#include "ccheap.h"
#include "common.h"

static CC_HEAP* Create_Heap(CC_HEAP* Heap, int Max_Capacity)
{
    Heap = (CC_HEAP*)malloc(sizeof(CC_HEAP));
    Heap->Array = (int*)malloc(Max_Capacity * sizeof(int));
    Heap->Capacity = Max_Capacity;
    Heap->Count = 0;
    return Heap;
}

int Maximum(int A, int B)
{
    if (A > B)
    {
        return A;
    }

    return B;
}

int Minimum(int A, int B)
{
    if (A < B)
    {
        return A;
    }

    return B;
}

static void Swapping(int* A, int* B)
{
    int aux = *A;
    *A = *B;
    *B = aux;
}

static void Heapify(int* Array, int Index, int Size, int(*f)(int, int))
{
    int Left_Child = 2 * Index + 1;
    int Right_Child = 2 * Index + 2;
    int Aux = Index;

    if (Left_Child < Size && f(Array[Left_Child], Array[Aux]) != Array[Aux]) // fiul stang este mai mare (mic) decat parintele
    {
        Aux = Left_Child;
    }

    if (Right_Child < Size && f(Array[Right_Child], Array[Aux]) != Array[Aux]) // fiul stang este mai mare (mic) decat parintele
    {
        Aux = Right_Child;
    }

    if (Aux != Index)
    {
        Swapping(&Array[Aux], &Array[Index]);
        Heapify(Array, Aux, Size, f);
    }

}


int HpCreateMaxHeap(CC_HEAP** MaxHeap, CC_VECTOR* InitialElements)
{
    CC_UNREFERENCED_PARAMETER(MaxHeap);
    CC_UNREFERENCED_PARAMETER(InitialElements);

    /*if (NULL == InitialElements)
    {
        return -1;
    }*/

    /*if (InitialElements->Count == 0)
    {
        return -1;
    }*/


    for (int i = InitialElements->Count / 2; i >= 0; i--)
    {

        Heapify(InitialElements->Array, i, InitialElements->Count, Maximum);
    }

    CC_HEAP* Heap = NULL;
    Heap = Create_Heap(Heap, InitialElements->Size);
    Heap->Array = InitialElements->Array;
    Heap->Count = InitialElements->Count;
    Heap->Capacity = InitialElements->Size;

    *MaxHeap = Heap;

    return 0;

}

int HpCreateMinHeap(CC_HEAP** MinHeap, CC_VECTOR* InitialElements)
{
    CC_UNREFERENCED_PARAMETER(MinHeap);
    CC_UNREFERENCED_PARAMETER(InitialElements);


    if (NULL == InitialElements)
    {
        // vector vid ---> initializam vectorul
        VecCreate(&InitialElements);
    }

    for (int i = InitialElements->Count / 2 - 1; i >= 0; i--)
    {
        Heapify(InitialElements->Array, i, InitialElements->Count, Minimum);
    }

    CC_HEAP* Heap = NULL;
    Heap = Create_Heap(Heap, InitialElements->Size);
    Heap->Array = InitialElements->Array;
    Heap->Count = InitialElements->Count;
    Heap->Capacity = InitialElements->Size;
    Heap->Type = 0;
    *MinHeap = Heap;

    return 0;
}

int HpDestroy(CC_HEAP** Heap)
{
    CC_UNREFERENCED_PARAMETER(Heap);
    CC_HEAP* Hp = *Heap;
    if (NULL == Heap)
    {
        return -1;
    }
    free(Hp->Array);
    free(Hp);
    *Heap = NULL;
    return 0;
}

int HpInsert(CC_HEAP* Heap, int Value)
{
    CC_UNREFERENCED_PARAMETER(Heap);
    CC_UNREFERENCED_PARAMETER(Value);

    if (NULL == Heap)
    {
        return -1;
    }

    //pas I. adaugam elementul la finalul heap-ului
    int Index = Heap->Count;
    Heap->Array[Index] = Value;
    Heap->Count++;

    if (Index == 0)
    {
        // nu exista nici un  element in heap deci nu este necesara nici o modificare
        return 0;
    }

    // pas II. pentru a reechilibra heap-ul inlocuim fiul cu parintele pana cand P < F (pt min) sau P > F (pt max)

    int isMax = 1, isMin = 0;
    if (Heap->Type == 0)
    {
        isMax = 0; isMin = 1;
    }

    int A = Heap->Array[Index];
    int B = Heap->Array[(Index - 1) / 2];


    while (Index != 0 && (isMax * Maximum(A, B) != isMax * B || isMin * Minimum(A, B) != isMin * B))
    {
        Swapping(&Heap->Array[Index], &Heap->Array[(Index - 1) / 2]);
        Index = (Index - 1) / 2;
        A = Heap->Array[Index];
        B = Heap->Array[(Index - 1) / 2];
    }

    return 0;
}

int HpRemove(CC_HEAP* Heap, int Value)
{
    CC_UNREFERENCED_PARAMETER(Heap);
    CC_UNREFERENCED_PARAMETER(Value);

    if (NULL == Heap)
    {
        return -1;
    }

    int isMax = 1, isMin = 0;
    if (Heap->Type == 0)
    {
        isMax = 0;
        isMin = 1;
    }

    int Contains_Value = 0;

    for (int i = 0; i < Heap->Count; i++)
    {
        if (Heap->Array[i] == Value)
        {
            Contains_Value++;
            Heap->Array[i] = Heap->Array[Heap->Count - 1];
            Heap->Count--;
            i--; // daca toate valorile egale cu Value se afla la final, una din ele nu va fi stearsa daca indexul i nu este decrementat
        }
    }

    if (Contains_Value != 0)
    {
        if (isMax == 1)
        {
            for (int i = Heap->Count / 2; i >= 0; i--)
            {
                Heapify(Heap->Array, i, Heap->Count, Maximum);
            }
        }

        else if (isMin == 1)
        {
            for (int i = Heap->Count / 2; i >= 0; i--)
            {
                Heapify(Heap->Array, i, Heap->Count, Minimum);
            }
        }

    }

    return 0;
}

int HpGetExtreme(CC_HEAP* Heap, int* ExtremeValue)
{
    CC_UNREFERENCED_PARAMETER(Heap);
    CC_UNREFERENCED_PARAMETER(ExtremeValue);

    if (NULL == Heap)
    {
        return -1;
    }

    if (Heap->Count == 0)
    {
        return -1;
    }

    *ExtremeValue = Heap->Array[0];

    return 0;
}

int HpPopExtreme(CC_HEAP* Heap, int* ExtremeValue)
{
    CC_UNREFERENCED_PARAMETER(Heap);
    CC_UNREFERENCED_PARAMETER(ExtremeValue);

    if (NULL == Heap)
    {
        return -1;
    }

    if (Heap->Count == 0)
    {
        return -1;
    }

    HpGetExtreme(Heap, ExtremeValue);
    HpRemove(Heap, *ExtremeValue);

    if (Heap->Type == 1)
    {
        for (int i = Heap->Count / 2; i >= 0; i--)
        {
            Heapify(Heap->Array, i, Heap->Count, Maximum);
        }
    }
    else if (Heap->Type == 0)
    {
        for (int i = Heap->Count / 2; i >= 0; i--)
        {
            Heapify(Heap->Array, i, Heap->Count, Minimum);
        }
    }

    return 0;
}

int HpGetElementCount(CC_HEAP* Heap)
{
    CC_UNREFERENCED_PARAMETER(Heap);

    if (NULL == Heap)
    {
        return -1;
    }

    return Heap->Count;
}

int HpSortToVector(CC_HEAP* Heap, CC_VECTOR* SortedVector)
{
    CC_UNREFERENCED_PARAMETER(Heap);
    CC_UNREFERENCED_PARAMETER(SortedVector);
    if (NULL == Heap)
    {
        return -1;
    }

    while (Heap->Count > 0)
    {
        for (int i = Heap->Count / 2; i >= 0; i--)
        {
            Heapify(Heap->Array, i, Heap->Count, Minimum);
        }

        VecInsertTail(SortedVector, Heap->Array[0]);

        Heap->Array[0] = Heap->Array[Heap->Count - 1];
        Heap->Count--;
    }

    return 0;
}
