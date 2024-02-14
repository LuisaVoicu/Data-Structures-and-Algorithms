#include "ccstack.h"
#include "common.h"
#include "ccvector.h"

#define MAXIMUM_CAPACITY 100
int StCreate(CC_STACK** Stack)
{
    CC_STACK* St = NULL;
    CC_UNREFERENCED_PARAMETER(Stack);

    St = (CC_STACK*)malloc(sizeof(CC_STACK));
    if (NULL == St)
    {
        free(St);
        return -1; // nu poate fi alocata memorie stivei
    }

    St->Capacity = MAXIMUM_CAPACITY;
    St->Top = -1;
    St->Array = (int*)malloc(MAXIMUM_CAPACITY * sizeof(int));

    if (NULL == St->Array)
    {
        free(St);
        return -1; // nu poate fi alocata memorie vectorului
    }

    *Stack = St;
    return 0;
}

int StDestroy(CC_STACK** Stack)
{
    CC_UNREFERENCED_PARAMETER(Stack);

    if (NULL == Stack)
    {
        return -1; // stiva nu exista
    }

    CC_STACK* St = *Stack;
    free(St->Array);
    free(St);
    *Stack = NULL;

    return 0;
}

int StPush(CC_STACK* Stack, int Value)
{
    CC_UNREFERENCED_PARAMETER(Stack);
    CC_UNREFERENCED_PARAMETER(Value);

    if (NULL == Stack)
    {
        return -1; //stiva nu exista
    }

    if (Stack->Top > Stack->Capacity - 1)
    {
        //stiva este plina
        return -1;
    }

    Stack->Array[++Stack->Top] = Value;

    return 0;
}

int StPop(CC_STACK* Stack, int* Value)
{
    CC_UNREFERENCED_PARAMETER(Stack);
    CC_UNREFERENCED_PARAMETER(Value);

    if (NULL == Stack)
    {
        return -1;
    }

    if (StIsEmpty(Stack) == 1)
    {
        return -1; // stiva este goala
    }

    *Value = Stack->Array[Stack->Top];
    Stack->Top--;

    return 0;
}

int StPeek(CC_STACK* Stack, int* Value)
{
    CC_UNREFERENCED_PARAMETER(Stack);
    CC_UNREFERENCED_PARAMETER(Value);

    if (NULL == Stack)
    {
        return -1;
    }

    if (StIsEmpty(Stack) == 1)
    {
        return -1;
    }
    *Value = Stack->Array[Stack->Top];
    return 0;
}

int StIsEmpty(CC_STACK* Stack)
{
    CC_UNREFERENCED_PARAMETER(Stack);
    if (NULL == Stack)
    {
        return -1;
    }

    if (Stack->Top == -1)
        return 1;

    return 0;
}

int StGetCount(CC_STACK* Stack)
{
    CC_UNREFERENCED_PARAMETER(Stack);

    if (NULL == Stack)
    {
        return -1;
    }

    return Stack->Top + 1;

}

int StClear(CC_STACK* Stack)
{
    CC_UNREFERENCED_PARAMETER(Stack);

    if (NULL == Stack)
    {
        return -1;
    }

    while (Stack->Top >= 0)
    {
        int Value;
        StPop(Stack, &Value);
    }

    free(Stack->Array);
    free(Stack);
    return 0;
}

int StPushStack(CC_STACK* Stack, CC_STACK* StackToPush)
{
    CC_UNREFERENCED_PARAMETER(Stack);
    CC_UNREFERENCED_PARAMETER(StackToPush);
    if (NULL == Stack || NULL == StackToPush)
    {
        return -1;
    }

    CC_STACK* Aux_St = NULL;
    StCreate(Aux_St);

    while (StIsEmpty(StackToPush) == 0)
    {
        int Value;
        StPop(StackToPush, &Value);
        StPush(Aux_St, Value);
    }

    StDestroy(StackToPush);

    while (StIsEmpty(Aux_St))
    {
        int Value;
        StPop(Aux_St, &Value);
        StPush(Stack, Value);
    }

    StDestroy(Aux_St);

    return 0;
}
