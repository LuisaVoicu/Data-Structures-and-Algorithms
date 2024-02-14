typedef struct pereche
{
    int a, b;
}per;

typedef struct node
{
    per key;
    struct node* next;
}NodeT;
NodeT* first;
NodeT* last;

NodeT* create(per key);
void enqueue(per key);
per dequeue();
int empty();