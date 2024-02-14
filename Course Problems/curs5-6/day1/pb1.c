/*
1. De la tastatură se citesc cuvinte. Să se creeze o listă dublu înlănŃuită ordonată alfabetic, care conŃine în
noduri cuvintele distincte şi frecvenŃa lor de apariŃie. Se va afişa conŃinutul listei în ordine alfabetică.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20

typedef struct doubly
{
    char cuv[N]; 
    int frecv;
    struct doubly* next;
    struct doubly* prev;
}NodeT;





NodeT* create_node(char* cuv)
{
    NodeT* node = (NodeT*)malloc(sizeof(NodeT));
    strcpy(node->cuv, cuv);
    node->next = node->prev = NULL;
    node->frecv = 1;
    return node;
}

void insert_lex(NodeT** first, NodeT** last, char* cuv)
{
    int rez;
    int rez2;

    if (*first == NULL)
    {
        *first = *last = create_node(cuv);
    }
    else
    {
        NodeT* q = *first;
        NodeT* node = create_node(cuv);
        rez = strcmp(q->cuv, node->cuv);
        if (rez > 0)
        {
            // inseram pe prima pozitie

            node->next = q;
            q->prev = node;
            (*first) = node;
        }
        else 
        {
            if (q->next == NULL)
            {
                rez = strcmp(q->cuv, node->cuv);
                // avem doar un element in lista
                if (rez > 0)
                {
                    // inseram pe prima pozitie
                    node->next = *first;
                    (*first)->prev = node;
                    (*first) = node;
                }
                else if (rez < 0)
                {
                    // inseram pe ultima pozitie
                    (*last)->next = node;
                    node->prev = (*last);
                    (*last) = node;
                }
                else
                {
                    (*first)->frecv++;
                    // (*last)->frecv++;

                }

            }
            else
            {
                //printf("------%s %s\n", node->cuv, q->cuv);
                q = q->next;

                while (q != NULL)
                {
                   // printf("prev: %s %s %s\n", q->prev->cuv, q->cuv, node->cuv);
                    rez = strcmp(q->prev->cuv, node->cuv);
                    rez2 = strcmp(node->cuv, q->cuv);
                    //printf("%d %d\n", rez, rez2);
                    if (rez == 0)
                    {
                        q->prev->frecv++;
                        break;
                    }
                    else if (rez2 == 0)
                    {
                        q->frecv++;
                        break;
                    }
                    else if (rez < 0 && rez2 < 0)
                    {
                       // printf("aici!");
                        node->prev = q->prev;
                        node->next = q;
                        q->prev->next = node;
                        q->prev = node;
                        break;
                    }
                    q = q->next;
                }
                if (q == NULL)
                {
                    node->prev = (*last);
                    (*last)->next = node;
                    (*last) = node;
                }
            }
        }
    }
}
void print_forward(NodeT* first)
{
    NodeT* p = first;
    while (p != NULL)
    {
        printf("%s %d\n", p->cuv, p->frecv);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    FILE *pf = fopen("fisier.txt", "r");
    char s[10];
    int n;
    NodeT* last = NULL;
    NodeT* first = NULL;
    fscanf(pf, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        fscanf(pf,"%s", s);
        //printf("%s\n", s);
        insert_lex(&first, &last, s);
    }
    print_forward(first);
}