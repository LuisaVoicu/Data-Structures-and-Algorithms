#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    int depth;
    int height;
    struct node* left;
    struct node* right;
    struct node* parent;
}NodeT;

NodeT* create_node(int key)
{
    NodeT* node = (NodeT*)malloc(sizeof(NodeT));
    node->key = key;
    node->right = node->left = node->parent =  NULL;
    node->depth = node->height = 0;
    return node;
}
NodeT* insert_bst(NodeT* root, int key)
{
    if (root == NULL)
    {
        return create_node(key);
    }
    if (root != NULL)
    {
        if (key < root->key)
        {
            root->left = insert_bst(root->left, key);
        }
        else if (key > root->key)
        {
            root->right = insert_bst(root->right, key);
        }
    }
    return root;
}

NodeT* search_bst(NodeT* root, int key)
{
    while (root != NULL)
    {
        if (key < root->key)
        {
            root = root->left;
        }
        else if (key > root->key)
        {
            root = root->right;
        }
        else
        {
            return root;
        }
    }
    return NULL;
}

NodeT* get_min(NodeT* root)
{
    while (root!=NULL && root->left != NULL)
    {
        root = root->left;
    }//printf("%d aici\n ", root->key);
    return root;
}

NodeT* get_max(NodeT* root)
{

    while (root!=NULL && root->right != NULL)
    {
        root = root->right;
    }
    return root;
}


NodeT* succesor(NodeT* root, int key)
{
    NodeT* succes = NULL;

    while (root != NULL)
    {
        if (root->key == key)
        {
            break;
        }
        else if (key > root->key)
        {
            root = root->right;
        }
        else if(key < root->key)
        {
            succes = root;//poate chiar asta e succesorul
            root = root->left;
        }
    }
    if (root != NULL && root->right != NULL)
    {
        succes = get_min(root->right);
    }
    return succes;
}

NodeT* predecesor(NodeT* root, int key)
{
    NodeT* pred = NULL;
    while (root != NULL)
    {
        if (root->key == key)
        {
            break;
        }
        else if (key < root->key)
        {
            root = root->left;
        }
        else if (key > root->key)
        {
            pred = root;
            root = root->right;
        }
    }

    if (root != NULL && root->left != NULL)
    {
        pred = get_max(root->left);
    }
    return pred;
}

void get_parents(NodeT* root)
{
    if (root != NULL)
    {

        if (root->right != NULL)
        {
            root->right->parent = root;
        }

        if (root->left != NULL)
        {
            root->left->parent = root;
        }

        get_parents(root->left);
        get_parents(root->right);

    }
}

NodeT* succesorV2(NodeT* node)
{
    NodeT* succes = NULL;

   // printf("%d aici\n ", node->key);
    succes = get_min(node->right);


    if (succes == NULL)
    {
        // mergem in sus pana cand dam de un nr mai mare decat cel dat
        succes = node->parent;
        while (succes != NULL)
        {
            if (succes->key > node->key)
            {
                break;
            }
            succes = succes->parent;
        }
    }
    return succes;
}

NodeT* precedesorV2(NodeT* node)
{
    NodeT* pred = NULL;
    pred = get_max(node->left);

    if (pred == NULL)
    {
        pred = node->parent;
        while (pred != NULL)
        {
            if (pred->key < node->key)
            {
                break;
            }
            pred = pred->parent;
        }
    }
    return pred;
}



NodeT* delete_key(NodeT* root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }

        if (key < root->key)
        {
            root->left =  delete_key(root->left,key);
        }
        else if (key > root->key)
        {
            root->right=  delete_key(root->right, key);
        }

        else
        {
            if (root->left == NULL)
            {
                NodeT* node;
                node = root->right;
                free(root);
                return node;
            }
            else if (root->right == NULL)
            {
                NodeT* node;
                node = root->left;
                free(root);
                return node;
            }
            else
            {
                NodeT* node = get_min(root->right);
                root->key = node->key;
                root->right = delete_key(root->right, node->key);
            }
        }

    return root;
}
void preorder(NodeT* root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}


void get_depth(NodeT* root)
{
    if (root != NULL)
    {
        if (root->left != NULL)
        {
            root->left->depth = root->depth + 1;
        }
         if (root->right != NULL)
        {
            root->right->depth = root->right + 1;
        }
         get_depth(root->right);
         get_depth(root->right);

    }
}


int maxim(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}


int get_height(NodeT* root,int* mx)
{
    if (root != NULL)
    {
        root->depth = 1 + maxim(get_height(root->right,mx) , get_height(root->left,mx));

        if (root->depth > *mx)
        {
            *mx = root->depth;
        }
        return root->depth;


    }
    else
    {
        return -1;
    }

}



int main()
{
    NodeT* root = NULL;
    root = insert_bst(root, 40);
    insert_bst(root, 50);
    insert_bst(root, 30);
    insert_bst(root, 60);
    insert_bst(root, 45);
    insert_bst(root, 25);
    insert_bst(root, 35);
    insert_bst(root, 38);
    insert_bst(root, 36);

    preorder(root);
    printf("\n");
    NodeT* s = succesor(root, 36);
    NodeT* p = predecesor(root, 35);
    printf("%d %d", s->key, p->key);

    printf("\n");
    s = succesor(root, 25);
    p = predecesor(root,40);
    printf("%d %d", s->key, p->key);

    get_parents(root);


    printf("\n...\n");
    NodeT* a = NULL;
    NodeT* b = NULL;
    a = search_bst(root, 25);
    b = search_bst(root, 40);
    printf("a %d b %d\n", a->key, b->key);
    s = succesorV2(a);
    p = precedesorV2(b);
    printf("n %d %d", s->key, p->key);


    printf("\n..................................\n");
    root = delete_key(root, 40);
    root = delete_key(root, 25);
    preorder(root);

    int maxim = 0;
    get_height(root, &maxim);
    printf("\n%d ", maxim);
}
