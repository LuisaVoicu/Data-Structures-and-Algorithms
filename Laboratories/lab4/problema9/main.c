#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct binaryTree
{
    int key;
    struct binaryTree* left;
    struct binaryTree* right;
}NodeT;


NodeT* create_binTree(int** matrix, int*k, int *i , int *j, int n)
{
    NodeT* node = (NodeT*)malloc(sizeof(NodeT));

    if (*j < n - *k)
    {
        printf("%d ", matrix[i][j]);
    }
}


int main()
{
    FILE* pf = fopen("file.txt", "r");
    if (pf == NULL)
    {
        printf("eroare fisier!");
        exit(1);
    }

    int n;
    fscanf(pf, "%d", &n);
    int** matrix = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++)
    {
        matrix[i] = (int*)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++)
        {
            fscanf(pf, "%d", &matrix[i][j]);
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int k = 0; k <= n / 2; k++)
    {
        int i = k, j;
        for (j = k; j < n - k; j++)
        {
            printf("%d ", matrix[i][j]);
        }

        j = n - k - 1;
        for (i = k + 1; i < n - k; i++)
        {
            printf("%d ", matrix[i][j]);

        }

        i = n - k - 1;
        for (int j = n - k - 2; j >= k; j--)
        {
            printf("%d ", matrix[i][j]);
        }

        j = k;
        for (int i = n - k - 2; i > k; i--)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

}