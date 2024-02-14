#include "stdio.h"
#include "cctree.h"
#include "common.h"
#define INITIAL_SIZE 100

static CC_TREE* Insert(CC_TREE* Tree, int Value)
{

    if (NULL == Tree)
    {
        TreeCreate(&Tree);
        Tree->Data = Value;
        Tree->EmptyTree = 0; // valorile ce ajung in aceasta functie NU reprezinta primul element din Arbore
        return Tree;
    }
    else
    {
        if (Value < Tree->Data)
        {
            Tree->Left = Insert(Tree->Left, Value);
        }
        else
        {
            Tree->Right = Insert(Tree->Right, Value);
        }
        return Tree;
    }
}

static CC_TREE* Min_Value(CC_TREE* Tree)
{
    CC_TREE* Aux = (CC_TREE*)malloc(sizeof(CC_TREE));

    if (NULL == Aux)
    {
        return NULL;
    }

    Aux = Tree;
    while (Aux != NULL && Aux->Left != NULL)
    {
        Aux = Aux->Left;
    }
    return Aux;
}

static CC_TREE* Delete(CC_TREE* Tree, int Value)
{
    CC_TREE* Aux;

    if (Tree == NULL)
    {
        return NULL;
    }

    if (Tree != NULL)
    {
        if (Value < Tree->Data)
        {
            Tree->Left = Delete(Tree->Left, Value);
        }

        else if (Value > Tree->Data)
        {
            Tree->Right = Delete(Tree->Right, Value);
        }

        else if (Value == Tree->Data)
        {
            if (Tree->Left != NULL && Tree->Right != NULL)
            {
                // Caz I. nodul are 2 fii
                // nodul il vom inlocui cu cel mai mare element din subarborele stang pe care ulterior il vom sterge

                Aux = Min_Value(Tree->Left);
                Tree->Data = Aux->Data; // elementul sters e de fapt inlocuit cu cel mai mic element mai mic decat acesta

                Tree->Right = Delete(Tree->Right, Aux->Data); // vom sterge elementul cu care inlocuim valoarea initiala

            }

            else
            {
                // Caz II. nodul este frunza sau are doar un fiu
                Aux = Tree;
                if (Tree->Left == NULL)
                {
                    Tree = Tree->Right;
                }

                else if (Tree->Right == NULL)
                {
                    Tree = Tree->Left;
                }
                free(Aux);

            }
        }
        return Tree;
    }
}

static CC_TREE* Depth(CC_TREE* Tree, int Height, int* Max)
{
    if (Height == 0)
    {
        *Max = Height; // conditia va fi indeplinita doar la primul apel al functiei
    }
    if (Height > *Max)
    {
        *Max = Height;
    }
    if (Tree->Left != NULL)
    {
        Depth(Tree->Left, Height + 1, Max);
    }
    if (Tree->Right != NULL)
    {
        Depth(Tree->Right, Height + 1, Max);
    }
}

static int PreOrder(CC_TREE* Tree, int* Count, int Index, int* Value)
{
    if (NULL == Tree)
    {
        return -1;
    }
    (*Count)++;

    if (*Count == Index)
    {
        *Value = Tree->Data;
        return 0; // element gasit
    }

    else if (*Count < Index)
    {
        PreOrder(Tree->Left, Count, Index, Value);
        PreOrder(Tree->Right, Count, Index, Value);
    }

    else if (*Count > Index)
    {
        return 0; // elementul este gasit, insa Count continua sa numere pana la descarcarea completa a stivei
    }

}

static int PostOrder(CC_TREE* Tree, int* Count, int Index, int* Value)
{
    if (NULL == Tree)
    {
        return -1;
    }

    if (*Count <= Index)
    {
        PostOrder(Tree->Left, Count, Index, Value);
        PostOrder(Tree->Right, Count, Index, Value);

        (*Count)++;
        if (*Count == Index)
        {
            *Value = Tree->Data;
        }

    }

    else if (*Count > Index)
    {
        return 0; // elementul este gasit, insa Count continua sa numere pana la descarcarea completa a stivei
    }

}

static int InOrder(CC_TREE* Tree, int* Count, int Index, int* Value)
{
    if (NULL == Tree)
    {
        return -1;
    }

    if (*Count <= Index)
    {
        InOrder(Tree->Left, Count, Index, Value);

        (*Count)++;
        if (*Count == Index)
        {
            *Value = Tree->Data;
        }

        InOrder(Tree->Right, Count, Index, Value);
    }

    else if (*Count > Index)
    {
        return 0; // elementul este gasit, insa Count continua sa numere pana la descarcarea completa a stivei
    }

}

int TreeCreate(CC_TREE** Tree)
{
    CC_UNREFERENCED_PARAMETER(Tree);

    CC_TREE* Tr = NULL;
    Tr = (CC_TREE*)malloc(sizeof(CC_TREE));

    if (NULL == Tr)
    {
        free(Tr);
        return -1; // alocarea dinamica nu se poate realiza
    }

    Tr->Left = NULL;
    Tr->Right = NULL;
    Tr->EmptyTree = 1;
    *Tree = Tr;

    return 0;
}

int TreeDestroy(CC_TREE** Tree)
{
    CC_UNREFERENCED_PARAMETER(Tree);
    CC_TREE* Tr = *Tree;
    if (NULL == Tree)
    {
        return 0;
    }
    free(Tr->Left);
    free(Tr->Right);
    free(Tr);
    *Tree = NULL;

    return 0;
}

int TreeInsert(CC_TREE* Tree, int Value)
{
    CC_UNREFERENCED_PARAMETER(Tree);
    CC_UNREFERENCED_PARAMETER(Value);

    if (Tree == NULL)
    {   // Arborele nu este creat si deci nu are nici un element
        TreeCreate(&Tree);
        Tree->Data = Value;
        Tree->EmptyTree = 0; // exista deja un element in Arbore
       // isRoot++;
        return 0;
    }

    if (Tree->EmptyTree == 1)
    {
        // Arborele este creat dar nu are nici un element
        // se va insera primul element in arbore
        Tree->Data = Value;
        Tree->EmptyTree = 0;
        return 0;
    }
    // Arborele are cel putin un element
    Tree = Insert(Tree, Value);
    return 0;
}

int TreeRemove(CC_TREE* Tree, int Value)
{
    CC_UNREFERENCED_PARAMETER(Tree);
    CC_UNREFERENCED_PARAMETER(Value);

    if (NULL == Tree)
    {
        return -1;
    }

    while (TreeContains(Tree, Value) > 0)
    {
        Delete(Tree, Value);
    }

    return 0;
}

int TreeContains(CC_TREE* Tree, int Value)
{
    CC_UNREFERENCED_PARAMETER(Tree);
    CC_UNREFERENCED_PARAMETER(Value);

    // cautare iterativa
    if (NULL == Tree)
    {
        return -1;
    }
    CC_TREE* Aux = Tree;
    int Found = 0;
    do {
        if (Value == Aux->Data)
        {
            Found = 1;
        }
        else if (Value < Aux->Data)
        {
            Aux = Aux->Left;
        }
        else if (Value > Aux->Data)
        {
            Aux = Aux->Right;
        }
    } while (Aux != NULL && Found == 0);

    return Found;
}

int TreeGetCount(CC_TREE* Tree)
{
    if (NULL == Tree)
    {
        return 0;
    }

    return 1 + TreeGetCount(Tree->Left) + TreeGetCount(Tree->Right);
}

int TreeGetHeight(CC_TREE* Tree)
{
    CC_UNREFERENCED_PARAMETER(Tree);
    if (NULL == Tree)
    {
        return -1;
    }
    CC_TREE* Aux = Tree;
    int Height = 0;
    int Height_Max;
    Depth(Tree, Height, &Height_Max);
    return Height_Max;
}

int TreeClear(CC_TREE* Tree)
{
    CC_UNREFERENCED_PARAMETER(Tree);

    if (NULL == Tree)
    {
        return -1;
    }

    if (Tree->Right == NULL && Tree->Left == NULL)
    {
        // frunza
        TreeRemove(Tree, Tree->Data);
        return 0;
    }

    else
    {
        if (Tree->Right != NULL)
        {
            TreeClear(Tree->Right);
        }

        if (Tree->Left != NULL)
        {
            TreeClear(Tree->Left);
        }

    }

    return 0;
}

int TreeGetNthPreorder(CC_TREE* Tree, int Index, int* Value)
{
    CC_UNREFERENCED_PARAMETER(Tree);
    CC_UNREFERENCED_PARAMETER(Index);
    CC_UNREFERENCED_PARAMETER(Value);

    int Count = 0;
    int k = PreOrder(Tree, &Count, Index, Value);
    return k;
}

int TreeGetNthInorder(CC_TREE* Tree, int Index, int* Value)
{
    CC_UNREFERENCED_PARAMETER(Tree);
    CC_UNREFERENCED_PARAMETER(Index);
    CC_UNREFERENCED_PARAMETER(Value);

    int Count = 0;
    int k = InOrder(Tree, &Count, Index, Value);

    return k;
}

int TreeGetNthPostorder(CC_TREE* Tree, int Index, int* Value)
{
    CC_UNREFERENCED_PARAMETER(Tree);
    CC_UNREFERENCED_PARAMETER(Index);
    CC_UNREFERENCED_PARAMETER(Value);

    int Count = 0;
    int k = PostOrder(Tree, &Count, Index, Value);

    return k;
}

