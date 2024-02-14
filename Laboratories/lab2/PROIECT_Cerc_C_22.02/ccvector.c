#include "ccvector.h"
#include "common.h"
#include "string.h"

#define INITIAL_SIZE    100
#define SWAP(tip,A,B) \
              { tip C ; C = A ; A = B ; B = C; }
int VecCreate(CC_VECTOR** Vector)
{
    CC_VECTOR* vec = NULL;

    CC_UNREFERENCED_PARAMETER(Vector);

    /* if (NULL == Vector)
     {
         return -1;
     }*/

    vec = (CC_VECTOR*)malloc(sizeof(CC_VECTOR));
    if (NULL == vec)
    {
        free(vec);
        return -1;
    }

    memset(vec, 0, sizeof(*vec));

    vec->Count = 0;
    vec->Size = INITIAL_SIZE;
    vec->Array = (int*)malloc(sizeof(int) * INITIAL_SIZE);
    if (NULL == vec->Array)
    {
        free(vec);
        return -1;
    }

    *Vector = vec;

    return 0;
}

int VecDestroy(CC_VECTOR** Vector)
{
    CC_VECTOR* vec = *Vector;

    if (NULL == Vector)
    {
        return -1;
    }

    free(vec->Array);
    free(vec);

    *Vector = NULL;

    return 0;
}
int VecInsertTail(CC_VECTOR* Vector, int Value) // inserare la sfarsit
{
    CC_UNREFERENCED_PARAMETER(Vector); //
    CC_UNREFERENCED_PARAMETER(Value); //

    if (NULL == Vector)
    {
        return -1;
    }

    if (Vector->Count >= Vector->Size)
    {
        /// REALLOC
        int SizeRealloc = Vector->Count;
        int* Re = realloc(Vector->Array, SizeRealloc * sizeof(int));

    }

    Vector->Array[Vector->Count] = Value;
    Vector->Count++;

    return 0;
}

int VecInsertHead(CC_VECTOR* Vector, int Value)
{
    CC_UNREFERENCED_PARAMETER(Vector);
    CC_UNREFERENCED_PARAMETER(Value);

    if (NULL == Vector)
    {
        return -1;
    }

    if (Vector->Count >= Vector->Size)
    {
        /// REALLOC
        int SizeRealloc = Vector->Count;
        int* Re = realloc(Vector->Array, SizeRealloc * sizeof(int));
    }

    for (int i = Vector->Count - 1; i >= 0; i--)
    {
        Vector->Array[i + 1] = Vector->Array[i];
    }
    Vector->Array[0] = Value;
    Vector->Count++;

    return 0;
}

int VecInsertAfterIndex(CC_VECTOR* Vector, int Index, int Value)
{
    CC_UNREFERENCED_PARAMETER(Vector);
    CC_UNREFERENCED_PARAMETER(Index);
    CC_UNREFERENCED_PARAMETER(Value);

    if (NULL == Vector)
    {
        return -1;
    }
    if (Index > Vector->Count)
    {
        return -1;
    }
    if (Vector->Count >= Vector->Size)
    {
        /// REALLOC
        int SizeRealloc = Vector->Count;
        int* Re = realloc(Vector->Array, SizeRealloc * sizeof(int));
    }

    for (int i = Vector->Count - 1; i > Index; i--)
    {
        Vector->Array[i + 1] = Vector->Array[i];
    }
    Vector->Array[Index + 1] = Value;
    Vector->Count++;

    return 0;
}

int VecRemoveByIndex(CC_VECTOR* Vector, int Index)
{
    CC_UNREFERENCED_PARAMETER(Vector);
    CC_UNREFERENCED_PARAMETER(Index);

    if (Index > Vector->Count)
    {
        return -1;
    }

    for (int i = Index; i < Vector->Count - 1; i++)
        Vector->Array[i] = Vector->Array[i + 1];
    Vector->Count--;

    return 0;
}

int VecGetValueByIndex(CC_VECTOR* Vector, int Index, int* Value)
{
    CC_UNREFERENCED_PARAMETER(Vector);
    CC_UNREFERENCED_PARAMETER(Index);
    CC_UNREFERENCED_PARAMETER(Value);

    if (Index > Vector->Count)
    {
        return -1;
    }

    *Value = Vector->Array[Index];
    return 0;
}
int VecGetCount(CC_VECTOR* Vector)
{
    CC_UNREFERENCED_PARAMETER(Vector);
    if (NULL == Vector)
    {
        return -1;
    }
    return Vector->Count;
}

int VecClear(CC_VECTOR* Vector)
{
    CC_UNREFERENCED_PARAMETER(Vector);
    if (Vector == NULL)
    {
        return -1;
    }

    Vector->Array = NULL;
    Vector->Size = 0;
    Vector->Count = 0;
    return 0;
}

int VecSort(CC_VECTOR* Vector)
{
    CC_UNREFERENCED_PARAMETER(Vector);
    if (Vector == NULL)
    {
        return -1;
    }
    for (int i = 0; i < Vector->Count - 1; i++)
        for (int j = i + 1; j < Vector->Count; j++)
            if (Vector->Array[i] < Vector->Array[j])
                SWAP(int, Vector->Array[i], Vector->Array[j]);

    return 0;
}

int VecAppend(CC_VECTOR* DestVector, CC_VECTOR* SrcVector)
{
    CC_UNREFERENCED_PARAMETER(DestVector);
    CC_UNREFERENCED_PARAMETER(SrcVector);
    if (DestVector == NULL || SrcVector == NULL)
    {
        return -1;
    }
    int Index = DestVector->Count;
    DestVector->Count += SrcVector->Count;
    if (DestVector->Count > DestVector->Size)
    {
        /// REALLOC
        int SizeRealloc = DestVector->Count;
        int* Re = realloc(DestVector->Array, SizeRealloc * sizeof(int));
    }
    for (int i = 0; i < SrcVector->Count; i++)
    {
        DestVector->Array[i + Index] = SrcVector->Array[i];
    }
    return -1;
}
