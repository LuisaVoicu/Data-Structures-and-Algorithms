#define _crt_secure_no_warnings
#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
    int key;
    int status;
} Cell;

enum { FREE, OCCUPIED };

void afisare(Cell* T, int m)
{
    printf("\n\nTabela de dispersie este \n");
    for (int i = 0; i < m; i++)
    {
        if (T[i].status == OCCUPIED)
            printf("T[%d]=%d\n", i, T[i]);
        else
            printf("T[%d]= --\n", i);
    }
}

void insert_key(int k, Cell* T, int m, int (*hash_func)(int k, int m, int i))
{
    int kneg = 0;
    if (k < 0)
    {
        kneg = k;
        k *= (-1);
        int div = k / m;
        div++;

        k = m * div - k;

    }
    int i = 0;
    int slot = hash_func(k, m, i);

    if (T[slot].status == FREE)
    {
        if (kneg == 0)
        {
            T[slot].key = k;
        }
        else
        {
            T[slot].key = kneg;
        }
        T[slot].status = OCCUPIED;

    }
    else
    {
        int collision = slot;
        i++;
        slot = hash_func(k, m, i);

        while (T[slot].status != FREE && slot != collision)
        {
            //printf("status %d\n", T[hash_func(k, m, i)].status);
            i++;
            slot = hash_func(k, m, i);
        }

        if (slot == collision)
        {
            printf("\nTabelul de dispersie este plin!\n");
        }
        else
        {
            // printf("-->entru cheia %d locul %d este liber\n", k, i);

            if (kneg == 0)
            {
                T[slot].key = k;
            }
            else
            {
                T[slot].key = kneg;
            }
            T[slot].status = OCCUPIED;
        }
    }
    //insereaza pe prima pozitie libera potrivit hash_func-ului sau afiseaza ca tabela e plina
}

int search_key(int k, Cell* T, int m, int (*hash_func)(int k, int m, int i)) {
    int i = 0;

    int kneg = 0;
    if (k < 0)
    {
        kneg = k;
        k *= (-1);
        int div = k / m;
        div++;

        k = m * div - k;

    }

    int slot = hash_func(k, m, i);

    if (T[slot].status == FREE)
    {
        return -1; // celula nu e ocupata!
    }

        if ((kneg == 0 && T[slot].key == k) ||
              (kneg != 0 && T[slot].key == kneg))
        {
                return slot;
        }
    // altfel poate se afla pe alta pozitie
        int collision = slot;
        i++;
        slot = hash_func(k, m, i);

        while (slot !=  collision)
        {
            if ((kneg == 0 && T[slot].key == k) ||
                (kneg != 0 && T[slot].key == kneg))
            {
                return slot;
            }
            i++;
            slot = hash_func(k, m, i);
        }
    
        return -1; //-1 in cazul in care nu se gaseste, altfel pozitia
}

int h_prime(int k, int m)
{
    int h0 = k % m;
    return h0; //schimbati in formula
}

int h_prime2(int k, int m) {
    int h1 = 5 - (k % 5);
    return h1;
}

int linear_probing(int k, int m, int i)
{
    int h = (h_prime(k, m) + i) % m;
    return h;
}

int quadratic_probing(int k, int m, int i)
{
    // c1=c2=1;
    int h = (h_prime(k, m) + i + i * i) % m;

    return h;
}

int double_hashing(int k, int m, int i)
{
    int h = (h_prime(k, m) + i * h_prime2(k, m)) % m;
    return h;
}

void set_table_free(Cell* T, int m)
{
    //initializam tabela
    int i;
    for (i = 0; i < m; i++)
    {
        T[i].status = FREE;
    }
}

int main()
{
    int m = 7;
    Cell* T = (Cell*)malloc(m * sizeof(Cell)); //tabela de dispersie - se aloca

    //test linear probing
    set_table_free(T, m);
    int vals[] = { 19, 36, 5, 21, 4, 26, 14, 17 };
    for (int i = 0; i < sizeof(vals) / sizeof(int); i++)
        insert_key(vals[i], T, m, linear_probing);
    afisare(T, m);
    //21, 36, 26, 14, 4, 19, 5

    //test quadratic probing
    set_table_free(T, m);
    for (int i = 0; i < sizeof(vals) / sizeof(int); i++)
        insert_key(vals[i], T, m, quadratic_probing);
    afisare(T, m);
    //k + i + i*i mod m: 5, 36, 21, 26, 4, 19, 14

    //test double hashing

    set_table_free(T, m);
    for (int i = 0; i < sizeof(vals) / sizeof(int); i++)
        insert_key(vals[i], T, m, double_hashing);
    afisare(T, m);
    //k + i*(5 - k%5) mod m: 21, 36, 26, 5, 4, 19, 14

    //test hash function
    set_table_free(T, m);
    insert_key(-3, T, m, linear_probing);
    afisare(T, m);
    // T[4]=-3

    //test cautare
    set_table_free(T, m);
    for (int i = 0; i < sizeof(vals) / sizeof(int); i++)
        insert_key(vals[i], T, m, linear_probing);
    afisare(T, m);
    for (int i = 0; i < sizeof(vals) / sizeof(int); i++) {
        int pos = search_key(vals[i], T, m, linear_probing);
        if (pos != -1) {
            printf("cheia %d este pe pozitia %d\n", vals[i], pos);
        }
        else
            printf("cheia %d nu se gaseste in tabela\n", vals[i]);
    }
    int key = -100;
    int pos = search_key(key, T, m, linear_probing);
    if (pos != -1) {
        printf("cheia %d este pe pozitia %d\n", key, pos);
    }
    else
        printf("cheia %d nu se gaseste in tabela\n", key);

    //free(T);
    return 0;
}
