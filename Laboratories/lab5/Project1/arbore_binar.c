#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct binT
{
    int key;
    struct binT* parent;
    struct binT* left;
    struct binT* right;
}NodeT;

NodeT* createNode(int key)
{
    NodeT* node = (NodeT*)malloc(sizeof(NodeT));
    node->key = key;
    node->right = node->left = NULL;
    node->parent = NULL;
    return node;
}
NodeT* insertNode(NodeT* root, int key)
{
    NodeT* node = createNode(key);
    if (root == NULL)
    {
        root = node;
    }
    else
    {
        if (key < root->key)
        {
            root->left = insertNode(root->left, key);
        }
        else if (key > root->key)
        {
            root->right = insertNode(root->right, key);
        }
    }
    return root;
}

void inOrder(NodeT* p)
{
    if (p != NULL)
    {
        inOrder(p->left);
        printf("%d ", p->key);
        inOrder(p->right);
    }
}
void preOrder(NodeT* p)
{
    if (p != NULL)
    {
        printf("%d ", p->key);
        preOrder(p->left);
        preOrder(p->right);
    }
}

void postOrder(NodeT* p)
{
    if (p != NULL)
    {
        postOrder(p->left);
        postOrder(p->right);
        printf("%d ", p->key);
    }
}

void getParent(NodeT* root)
{
    if (root != NULL)
    {
        printf("//%d\n", root->key);
        if (root->left != NULL)
        {
            root->left->parent = root;
        }
        if (root->right != NULL)
        {
            root->right->parent = root;
        }
        getParent(root->left);
        getParent(root->right);
    }
}

NodeT* searchKey(NodeT* tree, int key)
{
    while (tree != NULL)
    {
        if (tree->key == key)
        {
            return tree;
        }
        if (tree->key > key)
        {
            tree = tree->left;
        }
        else if (tree->key < key)
        {
            tree = tree->right;
        }
    }
}
NodeT* findMin(NodeT* node)
{
    while (node->left != NULL)
    {
        node = node->left;
    }
    return node;
}
NodeT* findMax(NodeT* node)
{
    while (node->right != NULL)
    {
        node = node->right;
    }
    return node;
}

void printParents(NodeT* root)
{
    if (root != NULL)
    {
        if (root->parent != NULL)
        {
            printf("p %d %d\n", root->key, root->parent->key);
        }
        printParents(root->left);
        printParents(root->right);
    }
}
NodeT* succesor(NodeT* node)
{

    if (node != NULL)
    {
        if (node->right != NULL)
        {
            return findMin(node->right);
        }

        // altfel parcurgem toti parintii pana facem o mutare la dreapta <=> gasim o valoare mai mare decat nodul de la care pornim
        NodeT* parinte = node->parent;
        while (parinte != NULL && node == parinte->right)
        {
            node = parinte;
            parinte = parinte->parent;
        }
        return parinte;

    }
}
NodeT* predecessor(NodeT* node)
{

    if (node != NULL)
    {
        if (node->left != NULL)
        {
            return findMax(node->left);
        }

        // altfel parcurgem toti parintii pana facem o mutare la dreapta <=> gasim o valoare mai mare decat nodul de la care pornim
        NodeT* parinte = node->parent;
        while (parinte != NULL && node == parinte->left)
        {
            node = parinte;
            parinte = parinte->parent;
        }
        return parinte;

    }
}

NodeT* deleteNode(NodeT* root, int key)
{

    if (root == NULL)
    {
        return NULL;
    }
    if (key < root->key)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        //am gasit nodul
        NodeT* aux;
        if (root->left == NULL)
        {
            aux = root->right;
            free(root);
            return aux;
        }
        else if (root->right == NULL)
        {
            aux = root->left;
            free(root);
            return aux;
        }

        aux = findMin(root->right);
        root->key = aux->key;
        root = deleteNode(root, aux->key);
    }
    return root;
}

int main()
{
  NodeT* root = NULL;
    NodeT* root2 = NULL;
    NodeT* p;

    int n = 11;
    int keys[] = { 15, 6, 18, 17, 20, 3, 7, 2, 4, 13, 9 };

    root = insertNode(root, keys[0]);

    printf("%d ", keys[0]);
    for (int i = 1; i < n; i++) {
        insertNode(root, keys[i]);

    }

    printf("\nPreorder listing\n");
    preOrder(root);
    printf("\nRezultat inserare iterativa:\n");
    preOrder(root2);
    printf("\nInorder listing\n");
    inOrder(root);
    printf("\nPostorder listing\n");
    postOrder(root);

    int key = 15;
    p = searchKey(root, key);
    if (p != NULL) {
        printf("\nNod cu cheia = %d gasit\n", key);
        NodeT* m = findMin(p);
        printf("\nMinimul din subarborele care are ca radacina nodul %d este %d \n", p->key, m->key);
    }
    else
        printf("\nNodul NU a fost gasit \n");

    NodeT* s = succesor(p);
    if (s != NULL) {
        printf("Nod cu cheia = %d are sucesor pe %d\n", p->key, s->key);
    }
    else
        printf("Nodul NU are succesor !\n");
    NodeT* q = predecessor(p);
    if (q != NULL) {
        printf("Nod cu cheia = %d are predecesor pe %d\n", p->key, q->key);
    }
    else
        printf("Nodul NU are predecesor !\n");

    key = 15;
    printf("Nodul de sters este: %d\n", key);
    root = deleteNode(root, key);
    preOrder(root);


}
