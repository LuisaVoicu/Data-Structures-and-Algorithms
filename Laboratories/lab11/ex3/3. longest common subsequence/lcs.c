#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int i, j;
    int dist;
}lcs;



void print_ij(lcs** c, char* x, int i , int j)
{
    if (i == 0 || j == 0)
    {
        return;
    }
    print_ij(c, x, i + c[i][j].i, j + c[i][j].j);
    if (c[i][j].i == -1 && c[i][j].j == -1)
    {
        printf("%c", x[i]);
    }
}

void print_eficient(int** d, char* x, int i, int j)
{

    if (d[i][j] == 0)
    {
        return;
    }
    if (d[i - 1][j] != d[i][j] && d[i][j - 1] != d[i][j] )
    {
        // merg pe diagonala 
        print_eficient(d, x, i - 1, j - 1);
        printf("%c", x[i]);
    }
    else
    {
        if (d[i - 1][j] >= d[i][j - 1])
        {
            print_eficient(d, x, i - 1, j);
        }
        else
        {
            print_eficient(d, x, i , j - 1);
        }
    }
}
int main()
{
    int xn = 9, yn = 8;
    char* x = (char*)malloc(xn * sizeof(char));
    char* y = (char*)malloc(yn * sizeof(char));
    lcs** c = (lcs**)malloc(xn * sizeof(lcs*));
    int** d = (int**)malloc(xn * sizeof(int*));  /// PT VARIANTA EFICIENTA IN CARE NU E NEVOIE SA STOCAM DIRECTIA
    for (int i = 0; i < xn; i++)
    {
        c[i] = (lcs*)malloc(yn * sizeof(lcs));
        d[i] = (int*)malloc(yn * sizeof(int));  
    }
    strcpy(x, "0ABCBDAB"); // am pus 0 si 1 pt a incepe de la indexul 1
    strcpy(y, "1BDCABA");

    //printf("%s\n", y);
    for (int i = 0; i < xn; i++)
    {
        for (int j = 0; j < yn; j++)
        {
            if (i == 0 || j == 0)
            {
                c[i][j].dist = 0;

                d[i][j] = 0;

            }
            else if (x[i] == y[j])
            {
                c[i][j].dist = c[i - 1][j - 1].dist + 1;
                c[i][j].i = -1;
                c[i][j].j = -1;

                d[i][j] = d[i - 1][j - 1] + 1;
            }
            else if (x[i] != y[j])
            {
                if (c[i - 1][j].dist >= c[i][j - 1].dist)
                {
                    c[i][j].dist = c[i - 1][j].dist;
                    c[i][j].i = -1;
                    c[i][j].j = 0;

                    d[i][j] = d[i - 1][j];
                }
                else
                {
                    c[i][j].dist = c[i][j - 1].dist;
                    c[i][j].i = 0;
                    c[i][j].j = -1;

                    d[i][j] = d[i][j - 1];
                }
            }
        }
    }

    printf("rez cu matricea de sageti si distanta:\n");
    print_ij(c, x, xn - 1, yn - 1);

    printf("\n\nrez fara matricea cu sageti (doar cu distanta) :\n");
    print_eficient(d, x, xn - 1, yn - 1);
    printf("\n");
}
