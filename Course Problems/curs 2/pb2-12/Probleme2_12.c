#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NodeType {
    int key;
    int duplicate;
    struct NodeType* next;
}NodeT;

typedef struct FrequencyNode
{
    int key;
    int freq;
    struct FrequencyNode* next;
}NodeF;


///////////////////////////////////////////////////////////// Functii auxiliare //////////////////////////////////////////////////////////////////////////////

NodeT* create_list(int givenkey)
{

    NodeT* q = (NodeT*)malloc(sizeof(NodeT));

    if (NULL == q)
    {
        // nu se poate realiza alocarea dinamica
        exit(1);
    }

    q->key = givenkey;
    q->duplicate = 0;
    q->next = NULL;

    return q;
}

NodeF* create_frequency_list(int givenKey)
{
    NodeF* q = (NodeF*)malloc(sizeof(NodeF));

    if(NULL == q)
    {
        // nu se poate realiza alocarea dinamica
        exit(2);
    }

    q->key = givenKey;
    q->freq = 1;
    q->next = NULL;
    return q;
}

void insert_last(NodeT** first, NodeT** last, int givenKey)
{
    NodeT* p_first = *first;
    NodeT* p_last = *last;
    NodeT* elem = create_list(givenKey);

    if (NULL == p_first)
    {
        p_first = elem;
        p_last = elem;
    }

    else if (NULL != p_last)
    {
        p_last->next = elem;
        p_last = elem;
    }
     *first = p_first;
     *last = p_last;
}

void print_list(NodeT* first)
{
    NodeT* p;
    p = first;

    if(NULL == p)
    {
        printf("Lista vida!");
    }

    while(NULL != p)
    {
        printf("%d ",p->key);
        p = p->next;
    }

    printf("\n\n");
}

void print_frequency_list(NodeF* fr)
{
    if(fr == NULL)
    {
        printf("Lista este vida!");
    }
    else
    {
        while(fr->next!=NULL)
        {
        printf("%d:%d -> ",fr->key,fr->freq);
        fr = fr->next;
        }
        printf("%d:%d",fr->key,fr->freq);
    }

    printf("\n\n");
}




/////////////////////////////////////////////////////////////// Probleme 2 - 12 /////////////////////////////////////////////////////////////////////////////

int Problema2(NodeT* first)
{
    /*
    Problema 2 Se da o lista simplu inlantuita, cu referinta la inceputul listei.
    Descrieti, in pseudocod, un algoritm care numara elementele duplicat din lista.
    (Un element este duplicat daca apare de cel putin 2 ori in lista). Analizati
    complexitatea algoritmului propus.
    */

    NodeT* p = first;
    int nrD = 0;
    while(NULL != first->next)
    {
        int k = 0;
        p = first->next;

        if(first->duplicate != 1)
        {

          while(NULL != p)
        {
            if(p->key == first->key && p->duplicate == 0)
            {
                k = 1;
                p->duplicate = 1;
            }
            p = p->next;
        }

        if(k == 1)
        {
            // a fost gasit un duplicat
            nrD++;
        }

        }
        first = first->next;
    }
    return nrD;

    /// COMPLEXITATE O(N^2) ~ P = N*(N-1)/2
}

void Problema3(NodeT** first, int value)
{
    /*
    Problema 3 Se da o lista simplu inlantuita, cu referinta la inceputul listei.
    Descrieti, in pseudocod, un algoritm care inlocuieste toate valorile unicat din
    lista, cu o valoare data (repl). Analizati complexitatea algoritmului propus.
    */

    NodeT* p = *first;
    NodeT* q = *first;
    while(NULL != q->next)
    {
        int k = 0;
        p = q->next;

        if(q->duplicate != 2)
        {
            while(NULL != p)
            {

            if(p->key == q->key)
            {
                k = 1;
                p->duplicate = 2;
            }

            p = p->next;

            }

        if(k == 0)
        {
            q->key = value;
        }
        }
        q = q->next;
    }

    if(q->duplicate != 2)
    {
        q->key = value;
    }


    /// COMPLEXITATE O(N^2) ~ P = N(N-1)/2
}

void Problema4(NodeT** first)
{
    /*
    Problema 4 Se da o lista simplu inlantuita, cu referinta la inceputul listei.
    Descrieti, in pseudocod, un algoritm care inverseaza lista.
    Analizati complexitatea algoritmului propus.
    */
    NodeT* current = *first;
    NodeT* prev = NULL;
    NodeT* next = NULL;

    while(NULL != current)
    {
        // retinem urmatorul element
        next = current->next;

        // "intoarcem" elementul anterior ~ schimbam directia spre care pointeaza acesta
        current->next = prev;

        // procedam analog pentru toate elementele, pana la finalul listei
        prev = current;
        current = next;

    }

    *first = prev;

    /// COMPLEXITATE O(N) ~ P = N
}

void Problema5(NodeT** first, int element)
{
    /*
    Problema 5 Se da o lista simplu inlantuita, cu referinta la inceputul listei.
    Descrieti, in pseudocod, un algoritm care sterge ultima aparitie a unui element.
    Analizati complexitatea algoritmului propus.
    */

    NodeT* pos = NULL;
    NodeT* p = *first;
    NodeT* p1 = NULL;
    NodeT* pos1 = NULL;

    while(NULL != p)
    {
        if(p->key == element)
        {
             // retinem elementul anterior elementului gasit
            pos1 = p1;
            pos = p;
        }
        p1 = p;
        p = p->next;
    }


    if(NULL != pos)
    {
        // elementul exista in lista
        if(pos == *first)
        {
            // primul element este sters
            (*first) = (*first)->next;
        }

        else
        {
            pos1->next = pos->next;
        }
    }

    free(p);

    /// COMPLEXITATE O(N) ~ P = N
}

void Problema6(NodeT** first, int element)
{
    /*
    Problema 6 Se da o lista simplu inlantuita ORDONATA, cu referinta la inceputul listei.
    Descrieti, in pseudocod, un algoritm care insereaza un element
    dat in lista (lista rezultat trebuie sa fie si ea ordonata). Analizati complexitatea
    algoritmului propus.
    */

    NodeT* p = *first;
    NodeT* elem = create_list(element);


    // inserare pe prima pozitie
    if(p == NULL)
    {
        *first = elem;
    }
    else
    {
        if(p->next == NULL)
        {
                // inserez pe orice pozitie, nu va afecta monotonia sirului
                elem->next = NULL;
                p->next = elem;
        }
        else
        {
            // inserarea pe prima pozitie
            if((element <= p->key && p->key <= p->next->key) ||
               (element >= p->key && p->key >= p->next->key) )
            {

                elem->next = *first;
                *first = elem;
            }
            else
            {
            // inserare in interiorul listei
                while(NULL != p->next)
                {
                    if((p->key <= element && element <= p->next->key) ||
                        (p->key >= element && element >= p->next->key) )
                    {
                        break;
                    }

                    p = p->next;
                }

                if(NULL != p->next)
                {

                    elem->next = p->next;
                    p->next = elem;

                }
                else
                {
                //inserare dupa ultimul element
                elem->next = NULL;
                p->next = elem;
                }
            }
        }
    }

    /// COMPLEXITATE O(N)
}

NodeF* Problema7(NodeT* first)
{
    /*
    Problema 7 Se da o lista simplu inlantuita, cu referinta la inceputul listei.
    Lista contine elemente numere intregi. Descrieti, in pseudocod, un algoritm care
    creaza o noua lista care are ca si campuri elementele si frecventa lor de aparitie.
    Analizati complexitatea algoritmului propus.
    */
    NodeT* p = first;
    NodeF* fp = NULL;

    while(NULL != p)
    {

        if(NULL == fp)
        {
            fp = create_frequency_list(p->key);
        }
        else
        {
            int found = 0;
            NodeF* fq = fp;
            fq = fp;

            while(NULL != fq->next)
            {
                if(fq->key == p->key)
                {
                    fq->freq++;
                    found = 1;
                    break;
                }
                fq = fq->next;
            }
            if(NULL == fq->next && fq->key == p->key)
            {
                fq->freq++;
                found = 1;
            }

            if(found == 0)
            {
                // adaugam elementul in lista
                NodeF* aux = create_frequency_list(p->key);
                fq->next = aux;
            }
        }
        p = p->next;
    }

    return fp;

    /// COMPLEXITATE O(N^2) <-- in cazul in care toate elementele sunt distincte
}


void Problema8(NodeT** first, int k)
{
    /*
    Problema 8 Se da o lista simplu inlantuita, cu referinta la inceputul listei.
    Descrieti, in pseudocod, un algoritm care roteste lista (circular) cu K pozitii
    spre stanga. Analizati complexitatea algoritmului propus.
    */

    NodeT* p = *first;

    if(NULL != *first)
    {
        while(k > 0)
        {
             while(NULL != p->next)
            {
                p = p->next;
            }

            // adaugam primul element la sfarsitul listei;

            NodeT* head = create_list((*first)->key);
            p->next = head;

            // stergem primul element
            *first = (*first)->next;

            k--;
        }

    }
    /// COMPLEXITATE O(K*N) <-- k = numarul de "rotatii" ale listei
}

int Problema9(NodeT** first)
{
    /*
    Problema 9 Se da o lista simplu inlantuita, cu referinta la inceputul listei.
    Lista contine elemente numere naturale ≤ 9. Descrieti, in pseudocod,
    un algoritm care determina daca lista este palindromica.
    Analizati complexitatea algoritmului propus.
    */


    NodeT* unrev = NULL;
    NodeT* rev = NULL;
    NodeT* revLast = NULL;
    NodeT* current = *first;
    NodeT* next = NULL;

    while(NULL!= current)
    {
        insert_last(&unrev,&revLast,current->key);

        next = current->next;
        current->next = rev;
        rev = current;
        current = next;
    }

   *first = unrev;

   while(NULL != rev)
   {
       if(rev->key != unrev->key)
       {
           return 0;
       }
       rev = rev->next;
       unrev = unrev->next;
   }

   return 1;

   /// COMPLEXITATE O(N) ~ P = 2*N

}

int Problema10(NodeT* first)
{

    /*
    Problema 10 Se da o lista simplu inlantuita, cu referinta la inceputul listei.
    Lista contine elemente intregi. Descrieti, in pseudocod, un algoritm care printr-o
    singura parcurgere a listei determina elementul din mijlocul listei.
    Analizati complexitatea algoritmului propus.
    */

    NodeT* trav1 = first;
    NodeT* trav2 = first;

    // vom folosi 2 pointeri care parcurg (simultan) lista din 1 in 1 respectiv din 2 in 2
    // atunci cand pointerul ce parcurge lista din 2 in 2 ajunge la final, cel de-al doilea pointer se afla in mijlocul listei

    while(NULL != trav2)
    {

        if(trav2->next == NULL)
        {
            // am ajuns la capatul listei
            break;
        }trav1 = trav1->next;
        trav2 = trav2->next->next;
    }
    return trav1->key;

    /// COMPLEXITATE O(N)

}

NodeT* Problema11(NodeT* list1, NodeT* list2)
{
    /*
    Problema 11 Se dau doua liste simplu inlantuite ordonate crescator, fiecare
    avand referinta la inceputul listei. Listele contin elemente intregi. Descrieti, in
    pseudocod, un algoritm care interclaseaza cele doua liste. Analizati complexitatea algoritmului propus.
    */

    NodeT* result = NULL;
    NodeT* result_last = NULL;

    while(NULL != list1 && NULL != list2)
    {
        if(list1->key < list2->key)
        {
            insert_last(&result, &result_last, list1->key);
            list1 = list1->next;
        }
        else if(list1->key > list2->key)
        {
             insert_last(&result, &result_last, list2->key);
             list2 = list2->next;
        }
        else if(list1->key == list2->key)
        {
             insert_last(&result, &result_last, list1->key);
             insert_last(&result, &result_last, list2->key);
             list1 = list1->next;
             list2 = list2->next;
        }
    }


    while(NULL != list1)
    {
        insert_last(&result, &result_last, list1->key);
        list1 = list1->next;
    }

    while(NULL != list2)
    {
        insert_last(&result, &result_last, list2->key);
        list2 = list2->next;
    }

    return result;

    /// COMPLEXITATE O(max(N,M)) <-- N = numarul de elemente din lista 1 ; M = numarul de elemente din lista 2 ;
}

NodeT* Problema12(NodeT* list1, NodeT* list2)
{
    NodeT* result = NULL;
    NodeT* result_last = NULL;

    //list1 si list2 sunt ordonate crescator

    while(NULL != list1 && NULL != list2)
    {
        if(list1->key < list2->key)
        {
            list1 = list1->next;
        }
        else if(list1->key > list2->key)
        {
             list2 = list2->next;
        }
        else if(list1->key == list2->key)
        {
             insert_last(&result, &result_last, list1->key);
             list1 = list1->next;
             list2 = list2->next;
        }
    }

    return result;

    /// COMPLEXITATE O(min(N,M)) <-- N = numarul de elemente din lista 1 ; M = numarul de elemente din lista 2 ;
}


int main()
{
    NodeT* first = NULL;
    NodeT* last = NULL;
    NodeT* first1 = NULL;
    NodeT* last1 = NULL;

insert_last(&first,&last,2);
insert_last(&first,&last,3);
insert_last(&first,&last,9);
insert_last(&first,&last,9);
insert_last(&first,&last,16);
insert_last(&first,&last,16);


insert_last(&first1,&last1,2);
insert_last(&first1,&last1,2);
insert_last(&first1,&last1,6);
insert_last(&first1,&last1,7);
insert_last(&first1,&last1,26);
insert_last(&first1,&last1,226);

printf("Lista 1 : ");
print_list(first);
printf("Lista 2 : ");
print_list(first1);



char s[3];
int k;
do
{   printf("Doriti sa rezolvati o problema? Tastati : DA / NU\n");
    scanf("%s",s);

    if(stricmp(s,"DA") == 0)
    {
        int nr;

        printf("Introduceti numarul problemei ( 2 - 12) !\n");
        scanf("%d",&k);

        if(2 == k)
        {
            nr = Problema2(first);
            printf("\nRezultatul Problemei 2 / Numarul de duplicate este: %d\n\n",nr);
        }

        if(3 == k)
        {
            printf("Introduceti valoarea: ");
            scanf("%d", &nr);
            Problema3(&first,nr);
            printf("\nRezultatul Problemei 3: ");
            print_list(first);
        }

        if(4 == k)
        {
            Problema4(&first);
            printf("\nRezultatul Problemei 4: ");
            print_list(first);
        }

        if(5 == k)
        {
            printf("Introduceti valoarea: ");
            scanf("%d",&nr);
            printf("\nRezultatul Problemei 5: ");
            Problema5(&first,nr);
            print_list(first);
        }

        if(6 == k)
        {
            printf("Introduceti valoarea: ");
            scanf("%d",&nr);
            printf("\nRezultatul Problemei 6: ");
            Problema6(&first,nr);
            print_list(first);


        }

        if(7 == k)
        {
            NodeF* frequency = Problema7(first);
            printf("\nRezultatul Problemei 7: ");
            print_frequency_list(frequency);
        }

        if(8 == k)
        {
            printf("Introduceti valoarea: ");
            scanf("%d",&nr);
            printf("\nRezultatul Problemei 8: ");
            Problema8(&first,nr);
            print_list(first);
        }
        if(9 == k)
        {
            nr = Problema9(&first);
            if(nr == 1)
            {
                printf("Sirul este palindrom!\n");
            }
            else
            {
                printf("Sirul NU este palindrom!\n");
            }
            print_list(first);

        }
        if(10 == k)
        {
            nr = Problema10(first);
            Problema10(first);
            printf("Rezultatul Problemei 10: %d\n\n", nr);
        }

        if(11 == k)
        {

            NodeT* result = Problema11(first,first1);
            printf("Rezultatul problemei 11: ");
            print_list(result);
        }

        if(12 == k)
        {
            NodeT* result = Problema12(first,first1);
            printf("Rezultatul problemei 12: ");
            print_list(result);

        }
    }
}while(stricmp(s,"DA") == 0);


    return 0;
}
