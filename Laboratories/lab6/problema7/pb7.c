#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 20


typedef struct hash_table
{
    char key[10];
    struct hash_table* next;
}NodeT;

int f1(char* s)
{

    int n = strlen(s);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += s[i];
    }
    int res = sum % n;
    return res;
}

int f2(int a,int m)
{
    return a % m;
}
NodeT* create(char* key)
{

    NodeT* node = (NodeT*)malloc(sizeof(NodeT));
    strcpy(node->key, key);
    node->next = NULL;
    return node;
}



void insert(NodeT* T[M], char* key, int m)
{
    int slot = f2(f1(key),m);
    NodeT* node = create(key);

    if (T[slot] == NULL)
    {
        T[slot] = node;
    }
    else
    {

        // insert first
        node->next = T[slot];
        T[slot] = node;
    }

}

void del(NodeT* T[M], char* key, int m)
{
    int slot = f2(f1(key), m);
    NodeT* prev = NULL;
    NodeT* current = T[slot];
    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            break;
        }
        prev = current;
        current = current->next;
    }

    if (current != NULL)
    {
        // am gasit nodul!
        if (current == T[slot])
        {
            T[slot] = T[slot]->next;

        }
        else
        {
            prev->next = current->next;

        }
        free(current);
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

void print(NodeT* T[M],int n)
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

    int n;
    char* sir = (char*)malloc(sizeof(char) * 10);

    fscanf(pf, "%d", &n);
    NodeT* T[M];
    for (int i = 0; i < n; i++) {
        T[i] = NULL;
    }


    for (int i = 0; i < n; i++)
    {
        fscanf(pf, "%s ", sir);
        printf("\n %s\n", sir);
        insert(T, sir,n);
    }

    print(T, n);
    printf("\n");

    sir = "date";
    del(T, sir, n);
    print(T, n);
    printf("\n");

    sir = "structura";
    del(T, sir, n);
    print(T, n);

    // cautare
    sir = "mop";

    NodeT* node = search(T, sir, n);
    if (node == NULL)
    {
        printf("\"%s\" NU exista in tabela!\n", sir);
    }
    else
    {
        printf("\"%s\" exista in tabela!\n", sir);
    }

    del(T, sir, n);
    printf("\n");
    print(T, n);

    node = search(T, sir, n);
    if (node == NULL)
    {
        printf("\"%s\" NU exista in tabela!\n", sir);
    }
    else
    {
        printf("\"%s\" exista in tabela!\n", sir);
    }



}
