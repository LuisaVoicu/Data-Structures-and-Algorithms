#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


          // sens netrigo de la NV
// in ordine : NV,N,NE,E,SE,S,SV,V
int dx[] = { -1,-1,-1,0,1,1,1,0 };
int dy[] = { -1,0,1,1,1,0,-1,-1 };



int valid(int** a, int** b, int n, int m, int i, int j)
{
    // sunt depasite marginile matricei
    if (i < 0 || j < 0 || i >= n || j >= m)
    {
        return 0;
    }

    // obstacol
    if (a[i][j] == 1)
    {
        return 0;
    }

    // spatiul a fost vizitat anterior ( deci mai repede / deci printr-un drum mai scurt)
    if (b[i][j] != 0)
    {
        return 0;
    }

    return 1;
}

void back(int** a, int** trav, int n, int m, int i, int j, int sti, int stj)
{
    // i si j
   // if (valid(a, trav, n, m, i, j)
    {
        trav[i][j] = 
        if (i == sti && j == stj)
        {
            printf("dist : %d\n",trav[i][j]);

        }
        for (int k = 0; k < 8; k++)
        {
            int in = i + dx[k];
            int jn = j + dy[k];

            if (valid(a, trav, n, m, in, jn))
            {
                trav[]
            }
        }
    }
}

int main()
{
    FILE* f = fopen("data.in", "r");
    

    int n, m;
    int** a = (int**)malloc(sizeof(int*));

    fscanf(f, "%d %d", &n, &m);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            fscanf(f, "%d", &a[i][j]);
        }
    }
    int i, j;
    int k, p;
    fscanf(f, "%d %d", &i, &j);
    fscanf(f, "%d %d", &k, &p); 


}