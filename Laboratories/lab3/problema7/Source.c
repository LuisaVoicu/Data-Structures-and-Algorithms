#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct DoublyNode
{
    char key[100];
    int frequency;
    struct DoublyNode* next;
    struct DoublyNode* prev;
}NodeDL;

struct list_header
{
    NodeDL* first;
    NodeDL* last;
};

NodeDL* create_node(char* givenKey)
{
    NodeDL* node = (NodeDL*)malloc(sizeof(NodeDL));
    
    node->frequency = 0;
    strcpy(node->key, givenKey);
    node->next = node->prev = NULL;
    return node;
}

void print_list(struct list_header list)
{
    while (NULL != list.first)
    {
        printf("%s ", list.first->key);
        list.first = list.first->next;
    }
    printf("\n");
}

NodeDL* search_key(struct list_header list, char* s)
{

    while (NULL != list.first)
    {
        if (strcmp(s, list.first->key) <= 0)
        {
            return list.first;
        }
        list.first = list.first->next;
    }
    return NULL;
}



void insert_after_key(struct list_header* list, char* givenKey)
{
   
    NodeDL* node = create_node(givenKey);

    if (NULL == list->first)
    {
        list->first = list->last = node;
    }
    else
    {
    NodeDL* p = search_key(*list,givenKey);
    if (NULL == p)
    {
        // inseram pe ultima pozitie
        node->prev = list->last;
        list->last->next = node;
        list->last = node;
    }
    else
    {
        printf("... %s %s\n",givenKey, p->key);
        // inseram inainte de p
      
        node->prev = p->prev;
        p->prev = node;
        node->next = p;
        printf("dupa inserare: %s\n", p->prev->prev->key);
    }

    }
    printf("\n\n %s %s\n", list->first->key, list->first->next->key);
   
}
int main()
{
    FILE* pf = fopen("file.txt", "r");
    
    if (NULL == pf)
    {
        printf("fisierul nu poate fi deschis!");
        exit(1);
    }

    int n;
    fscanf(pf, "%d", &n);

    char* cuv = (char*)malloc(100 * sizeof(char));

    if (NULL == cuv)
    {
        printf("nu poate fi alocata memorie!");
        exit(2);
    }

    struct list_header list = { NULL, NULL };


    for (int i = 0; i < n; i++)
    {
        fscanf(pf, "%s", cuv);
        insert_after_key(&list, cuv);
    }
    printf("\n\n %s %s %s\n", list.first->key, list.first->next->key, list.first->next->next->key);
    print_list(list);
}