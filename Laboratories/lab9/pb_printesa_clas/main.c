#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int x,y;

}coord;



void print_map(int**harta, int n, int m)
{
    for(int i =0 ; i< n; i++)
    {
        for(int j = 0; j<m;j++)
        {

            printf("%d ",harta[i][j]);
        }
        printf("\n");
    }
}

void populateSol(coord*sol)
{
    sol[0].x = 0; sol[0].y = -1;
    sol[1].x = 1; sol[0].y = -1;
    sol[2].x = 1; sol[0].y = 0;
    sol[3].x = 1; sol[0].y = 1;
    sol[4].x = 0; sol[0].y = 1;
    sol[5].x = -1; sol[0].y = 1;
    sol[6].x = -1; sol[0].y = 0;
    sol[7].x = -1; sol[0].y = -1;


}


int bun(int k, coord* v, int** mat,int n, int m)
{

    if(v[k].y < 0 || v[k].y >= n || v[k].x < 0 || v[k].y >=m)
    {
        return 0;
    }

    if(mat[v[k].y][v[k].x] == 1)
    {
        return 0;
    }

    for(int i = 0 ; i < k; i++)
    {
        if(v[i].x == v[k].x &&v[i].y == v[k].y)
        {
            return 0; // ne intoarcem
        }
    }
    return 1;
}
void backtracking(int k, coord*v, coord* sol,int ** mat,int n, int m, coord printesa)
{
    // iteram prin toata multimea de solutii
        // vedem daca e finala
    for(int i = 0; i < 8; i++)
    {
        v[k].x = v[k-1].x+sol[i].x;
        v[k].y = v[k-1].y+sol[i].y;
        if(bun(k,v,mat,n,m))
        {
            // cond fin
            // printf
            //memoreaza
        }
    }
}

int main()
{
    FILE* f = fopen("printesa.in","r");
    int n,m;
    coord dani;
    coord prodanca;
    fscanf(f,"%d %d",&n,&m);
    fscanf(f,"%d %d",&dani.x,&dani.y);
    fscanf(f,"%d %d",&prodanca.x,&prodanca.y);

    int** harta = (int**)malloc(n*sizeof(int*));
    for(int i = 0; i<n;i++)
    {

        harta[i] = (int*)malloc(m*sizeof(int));
        for(int j = 0 ; j < m ; j++)
        {
            fscanf(f,"%d",&harta[i][j]);
        }
    }

    coord* v = (coord*)malloc(n*m*sizeof(coord));
    coord sol[8];
    populateSol
    v[0].x = dani.x;
    v[0].y = dani.y;
    backtracking(1,v,sol,harta,n,m,prodanca);
    return 0;
}
