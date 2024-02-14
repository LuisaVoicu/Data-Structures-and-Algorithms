#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void quickSort(int* v, int l, int r)
{
	if (l < r)
	{

		int m = (l + r) / 2;
		int aux = v[l];
		v[l] = v[m];
		v[m] = aux;

		int i = l, j = r, d = 0;

		while (i < j)
		{
			if (v[i] > v[j])
			{
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
				d = 1 - d;
			}
			i += d;
			j -= 1 - d;
		}
		quickSort(v, l, i - 1);
		quickSort(v, i + 1, r);
	}

}


long long solve(int* a, int n) {
	//returneaza costul pentru descompunerea optima	

	if (n == 1)
	{
		return a[0];
	}

	long long cost = 0;
	int nb_el = 0;
	while (nb_el < n - 1)
	{
		quickSort(a, nb_el, n - 1);
		cost += a[nb_el] + a[nb_el + 1];
		a[nb_el + 1] = a[nb_el] + a[nb_el + 1];;
		nb_el++;
	}
	return cost;
}

int main() {
	int tests;
	long long sol;
	int n;
	int* a;
	FILE* f = fopen("prb4_numere.txt", "r");
	if (f == NULL) {
		printf("Fisier inexistent\n");
		return -1;
	}
	fscanf(f, "%d", &tests);
	for (int testi = 0; testi < tests; testi++) {
		fscanf(f, "%d%I64d", &n, &sol);
		a = (int*)malloc(n * sizeof(int));
		for (int i = 0; i < n; i++)
			fscanf(f, "%d", a + i);
		long long cost = solve(a, n);
		printf("test %d: result %10I64d, expected %10I64d\n", testi, cost, sol);
		free(a);
	}
	fclose(f);
	return 0;
}
