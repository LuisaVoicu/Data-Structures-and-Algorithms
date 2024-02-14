#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include "cchashtable.h"
#include "common.h"
#define INITIAL_SIZE 16



static int Hash_Function(unsigned char* S)
{
    unsigned long Hash = 0;

    for (int i = 0; i < strlen(S); i++)
    {
        Hash += S[i];
    }

    return Hash % INITIAL_SIZE;
}

static CC_HASH_TABLE_ITEMS ItemCreate(char* Key, int Value)
{
    CC_HASH_TABLE_ITEMS Item;

    Item.Key = (char*)malloc(sizeof(char) * (strlen(Key)));
    Item.Key = Key;
    Item.Value = Value;
    return Item;
}

int HtCreate(CC_HASH_TABLE** HashTable)
{
    CC_UNREFERENCED_PARAMETER(HashTable);

    CC_HASH_TABLE* HT = (CC_HASH_TABLE*)malloc(sizeof(CC_HASH_TABLE));

    if (NULL == HashTable)
    {
        return -1;
    }

    if (NULL == HT)
    {
        // tabelul nu poate fi alocat dinamic
        free(HT);
        return -1;
    }
    memset(HT, 0, sizeof(*HT));

    HT->Size = INITIAL_SIZE;
    HT->Count = 0;
    HT->Items = (CC_HASH_TABLE_ITEMS*)malloc(sizeof(CC_HASH_TABLE_ITEMS) * INITIAL_SIZE);

    if (NULL == HT->Items)
    {
        // tabelul nu poate fi alocat dinamic
        free(HT);
        return -1;
    }

    for (int i = 0; i < HT->Size; i++)
    {
        HT->Items[i].Key = (char*)malloc(INITIAL_SIZE * sizeof(char));
        if (NULL == HT->Items[i].Key)
        {
            return -1;
        }
        HT->Items[i].Key = 0;
    }

    *HashTable = HT;
    return 0;
}

int HtDestroy(CC_HASH_TABLE** HashTable)
{
    CC_UNREFERENCED_PARAMETER(HashTable);

    CC_HASH_TABLE* HT = *HashTable;

    if (NULL == HT)
    {
        // tabelul nu este creat
        return -1;
    }

    for (int i = 0; i < HT->Size; i++)
    {
        if (HT->Items[i].Key != NULL)
        {
            HT->Items[i].Key = NULL;
        }
        free(HT->Items[i].Key);
    }
    free(HT->Items);
    free(HT);
    *HashTable = NULL;

    return 0;
}

int HtSetKeyValue(CC_HASH_TABLE* HashTable, char* Key, int Value)
{
    CC_UNREFERENCED_PARAMETER(HashTable);
    CC_UNREFERENCED_PARAMETER(Key);
    CC_UNREFERENCED_PARAMETER(Value);

    int Slot = Hash_Function(Key);
    CC_HASH_TABLE_ITEMS Item;
    CC_HASH_TABLE_ITEMS NewItem = ItemCreate(Key, Value);

    if (NULL == HashTable)
    {
        return -1;
    }

    if (NULL == Key)
    {
        return -1;
    }

    char* HasKey = HashTable->Items[Slot].Key;

    if (HasKey == NULL)
    {
        // cheia nu exista in tabel
        HashTable->Items[Slot] = NewItem;
        HashTable->Count++;
        return 0;
    }
    // cheia exista deja in tabel !
    return -1;

}

int HtGetKeyValue(CC_HASH_TABLE* HashTable, char* Key, int* Value)
{
    CC_UNREFERENCED_PARAMETER(HashTable);
    CC_UNREFERENCED_PARAMETER(Key);
    CC_UNREFERENCED_PARAMETER(Value);

    int Slot = Hash_Function(Key);
    CC_HASH_TABLE_ITEMS* Item = NULL;
    Item = HashTable->Items;

    if (NULL == HashTable)
    {
        return -1;
    }

    if (NULL == Key)
    {
        return -1;
    }

    if (NULL == Item)
    {
        // cheia nu exista in tabel
        return -1;
    }

    // daca NULL != Item  ==> cheia exista in tabel

    for (int i = 0; i < HashTable->Size; i++)
    {
        if (HashTable->Items[i].Key == Key)
        {
            *Value = HashTable->Items[i].Value;
            return 0;
        }
    }

}

int HtRemoveKey(CC_HASH_TABLE* HashTable, char* Key)
{
    CC_UNREFERENCED_PARAMETER(HashTable);
    CC_UNREFERENCED_PARAMETER(Key);

    int Slot = Hash_Function(Key);
    CC_HASH_TABLE_ITEMS* Item = NULL;
    Item = HashTable->Items;

    if (NULL == HashTable)
    {
        // tabelul nu exista
        return -1;
    }

    if (NULL == Key)
    {
        return -1;
    }

    if (NULL == Item)
    {
        // cheia nu exista in tabel
        return -1;
    }

    for (int i = 0; i < HashTable->Size; i++)
    {
        if (HashTable->Items[i].Key == Key)
        {
            //HashTable->Items[i].Key = NULL;
            free(HashTable->Items[i].Key);
            return 0;
        }
    }
    return -1;
}

int HtHasKey(CC_HASH_TABLE* HashTable, char* Key)
{
    int Slot = Hash_Function(Key);

    CC_UNREFERENCED_PARAMETER(HashTable);
    CC_UNREFERENCED_PARAMETER(Key);

    if (NULL == HashTable)
    {
        return -1;
    }
    if (NULL == Key)
    {
        return -1;
    }

    char* HasKey = HashTable->Items[Slot].Key;

    if (HasKey == NULL)
    {
        return 0;
    }

    return 1;
}

int HtGetFirstKey(CC_HASH_TABLE* HashTable, CC_HASH_TABLE_ITERATOR** Iterator, char** Key)
{
    CC_HASH_TABLE_ITERATOR* iterator = NULL;

    CC_UNREFERENCED_PARAMETER(Key);

    if (NULL == HashTable)
    {
        return -1;
    }

    if (NULL == Iterator)
    {
        return -1;
    }

    if (NULL == Key)
    {
        return -1;
    }

    iterator = (CC_HASH_TABLE_ITERATOR*)malloc(sizeof(CC_HASH_TABLE_ITERATOR));
    if (NULL == iterator)
    {
        return -1;
    }

    memset(iterator, 0, sizeof(*iterator));

    iterator->HashTable = HashTable;
    // INITIALIZE THE REST OF THE FIELDS OF iterator
    iterator->Index = 0;
    iterator->CurrentItem.Key = (char*)malloc(sizeof(char) * INITIAL_SIZE);

    if (NULL == iterator->CurrentItem.Key)
    {
        // nu se poate realiza alocarea dinamica
        return -1;
    }

    *Iterator = iterator;

    // FIND THE FIRST KEY AND SET Key
    for (int i = 0; i < HashTable->Size; i++)
    {
        if (NULL != HashTable->Items[i].Key)
        {
            (*Iterator)->CurrentItem.Key = HashTable->Items[i].Key;
            (*Iterator)->CurrentItem.Value = HashTable->Items[i].Value;
            *Key = HashTable->Items[i].Key;
            return 0;
        }
    }

    // nu a fost gasita nici o cheie in tabel
    return -2;
}

int HtGetNextKey(CC_HASH_TABLE_ITERATOR* Iterator, char** Key)
{
    CC_UNREFERENCED_PARAMETER(Key);
    CC_UNREFERENCED_PARAMETER(Iterator);

    if (NULL == Iterator)
    {
        return -1;
    }

    CC_HASH_TABLE* HT = Iterator->HashTable;

    while (Iterator->Index < HT->Size)
    {
        int i = Iterator->Index;
        Iterator->Index++;

        if (NULL != HT->Items[i].Key)
        {
            CC_HASH_TABLE_ITEMS Itm = HT->Items[i];
            Iterator->CurrentItem.Key = Itm.Key;
            Iterator->CurrentItem.Value = Itm.Value;
            *Key = Iterator->CurrentItem.Key;
            return 1;
        }
    }

    // nu a fost gasit nici o cheie
    return -2;
}

int HtReleaseIterator(CC_HASH_TABLE_ITERATOR** Iterator)
{
    CC_UNREFERENCED_PARAMETER(Iterator);

    CC_HASH_TABLE_ITERATOR* IT = *Iterator;

    if (NULL == IT)
    {
        return -1;
    }

    free(IT->CurrentItem.Key);
    free(IT);
    IT->Index = 0;

    return 1;
}

int HtClear(CC_HASH_TABLE* HashTable)
{
    CC_UNREFERENCED_PARAMETER(HashTable);

    if (NULL == HashTable)
    {
        return -1;
    }

    for (int i = 0; i < HashTable->Size; i++)
    {
        if (NULL != HashTable->Items[i].Key)
        {
            HashTable->Items[i].Key = NULL;
            HashTable->Items[i].Value = 0;
        }
    }

    return 0;
}

int HtGetKeyCount(CC_HASH_TABLE* HashTable)
{
    CC_UNREFERENCED_PARAMETER(HashTable);

    if (NULL == HashTable)
    {
        return -1;
    }

    return HashTable->Count;
}

