//169. Majority Element
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int count(int* num,int val, int a, int b)
{
    int cnt = 0;
    for (int i = a; i <= b; i++)
        if (num[i] == val)
            ++cnt;
    return cnt;
}


int divide_impera(int* num, int left, int right)
{
    if (left == right)
        return num[left];

    int mid = (left + right) / 2;
    
    int lft_val = divide_impera(num, left, mid);
    int rgh_val = divide_impera(num, mid + 1, right);


    int cntL = count(num, lft_val, left, mid);
    int cntR = count(num, rgh_val, mid + 1, right);

    if (cntL > cntR)
        return lft_val;
    return rgh_val;

}


int main()
{
    int num[] = { 3,2,3 };
    int n = sizeof(num) / sizeof(int);
    int fr = divide_impera(num, 0, n - 1);
    printf("%d\n", fr);
}