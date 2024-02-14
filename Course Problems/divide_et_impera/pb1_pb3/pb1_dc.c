#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define NINF -10000
int max3(int a, int b, int c)
{
    int mx = b;
    if (a > mx)
        mx = a;
    if (c > mx)
        mx = c;
    return mx;
}

int divide_impera(int* a, int l, int r)
{
    
    if (l < r)
   {
        int mid = (l + r) / 2;

        int sum_left = divide_impera(a, l, mid);
        int sum_right = divide_impera(a, mid+1, r);

         //suma maxima pe care o obtinem in unul din subarbori / submultime
        int max1 = NINF;
        int suma = 0;

        for (int i = mid; i >= l; i--) // coboram in arbore a.i. sa gasim suma cea mai mare obt din elementele din fata lui a[mid]
        {  
            suma += a[i];
            if (suma > max1)
                max1 = suma;
        }

        suma = 0;
        int max2 = NINF;

        for (int i = mid + 1; i <= r; i++) // suma maxima obt din elementele aflate dupa a[mid]
        {
            suma += a[i];
            if (suma > max2)
                max2 = suma;
        }
        
        // 3 pos : 1. se formeaza suma maxima doar cu arborele stant / 2. doar cu cel drept / 3. cu amandoi
        int max_sub = max3(max1, max2, max1 + max2);

        return max3(max_sub, sum_left, sum_right);

    }
    return a[l];
}

int main()
{
    int n = 8;
    int a[] = { 0, -2, -3, 4, -1, -2, 1, 5, -3 };

    int sm = divide_impera(a, 1, n);
    printf("sum max: %d\n", sm);
    

}