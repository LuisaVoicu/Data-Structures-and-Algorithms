#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 20
typedef struct chaining_ht
{
    char key[10];
    struct chaining_ht* next;
}NodeT;


int f1(char* key)
{
    int s = strlen(key);
    int sum = 0;
    for (int i = 0; i < s; i++)
    {
        sum += key[i];
    }
    return sum % s;
}

int f2(int a, int n)
{
    return a % n;
}

NodeT* create(char* key)
{
    NodeT* node = (NodeT*)malloc(sizeof(NodeT));
    strcpy(node->key, key);
    node->next = NULL;
    return node;
}

void insert(NodeT* T[M],int n, char* key)
{
    NodeT* node = create(key);
    int slot = f2(f1(key), n);
    
    if (T[slot] == NULL)
    {
        T[slot] = node;
    }
    else
    {
        node->next = T[slot];
        T[slot] = node;
    }

}

NodeT* search(NodeT* T[M], int n, char* key)
{   
    int slot = f2(f1(key), n);
    NodeT* p = T[slot];
    
    while (p != NULL)
    {
        if (strcmp(p->key, key) == 0)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void print(NodeT* T[M], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d : ", i);
        if (T[i] != NULL)
        {
            NodeT* p = T[i];

            while (p != NULL)
            {
                printf("%s ", p->key);
                p = p->next;
            }
        }
        printf("\n");
    }
    printf("\n\n");
}

int main()
{
    FILE* pf = fopen("file.txt", "r");

    if (pf == NULL)
    {
        printf("creeaza fisierul!!!!\n");
        exit(1);
    }

    char* sir = (char*)malloc(sizeof(char) * 20);
    char* subs = (char*)malloc(sizeof(char) * 20);
    NodeT* T[M];
    int n = 5;
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        T[i] = NULL;
    }

    fscanf(pf, "%s", sir);

    while (!feof(pf))
    {
        fscanf(pf, "%s", subs);
        insert(T, n, subs);
    }

    print(T, n);
    m = strlen(subs);

    int count = 0; 

    for (int i = 0; i < strlen(sir) - m + 1; i++)
    {
        strncpy(subs, sir+i, m);
        printf("\n%s\n", subs);
        NodeT* node = search(T, n, subs);
        if (node == NULL)
        {
            printf("\"%s\" NU exista in tabela!\n", subs);
        }
        else
        {
            count++;
            printf("\"%s\" exista in tabela!\n", subs);
        }
    }

    printf("\nNumarul de pozitii candidat este %d !\n", count);
}