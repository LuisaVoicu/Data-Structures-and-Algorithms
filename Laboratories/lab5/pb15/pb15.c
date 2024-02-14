#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX(A,B) ((A) > (B) ? (A):(B))
typedef struct node
{
    int key;
    int height;
    struct node* left;
    struct node* right;
}NodeT;


NodeT* create_node(int key)
{
    NodeT* node = (NodeT*)malloc(sizeof(NodeT*));
    node->key = key;
    node->height = 0;
    node->left = node->right = NULL;
    return node;
}

void Preorder(NodeT* abc)
{

    if (NULL != abc)
    {
        printf("%d %d \n", abc->key,abc->height);
        Preorder(abc->left);
        Preorder(abc->right);
    }
}


NodeT* single_right_rotate(NodeT* y)
{
    NodeT* x = y->left;
    NodeT* subXR = x->right;
    x->right = y;
    y->left = subXR;
    y->height = height(y);
    x->height = height(x);
    return x;
}

NodeT* single_left_rotate(NodeT* y)
{
    NodeT* x = y->right;
    NodeT* subxL = x->left;
    int h = x->height;
    x->left = y;
    y->right = subxL;
    y->height = height(y);
    x->height = height(x);
    return x;
}

NodeT* double_rightleft_rotate(NodeT* root)
{
    root->right = single_right_rotate(root->right);
    root = single_left_rotate(root);
    return root;
}

NodeT* double_leftright_rotate(NodeT* root)
{
    root->left = single_left_rotate(root->left);
    root = single_right_rotate(root);
    return root;
}

int height(NodeT* root)
{
    if (root == NULL)
    {
        return -1;
    }
    return MAX(height(root->left), height(root->right)) + 1;
}

int balance(NodeT* abc)
{

    if (abc == NULL)
    {
        return 0;
    }
    int hl = -1, hr = -1;
    if (abc->left != 0)
    {
        hl = abc->left->height;
    }
    if (abc->right != 0)
    {
        hr = abc->right->height;
    }
    return hl - hr;
    //return height(abc->left) - height(abc->right);
}


NodeT* insert_AVL(NodeT* root, int key)
{
    if (root == NULL)
    {
        return create_node(key);
    }
    if (key < root->key)
    {
        root->left = insert_AVL(root->left, key);
    }
    else if(key > root->key)
    {
        root->right = insert_AVL(root->right, key);
    }
    else
    {   
        return root;
    }
    
    root->height = height(root);
    int H = balance(root);
    if (H < -1 || H > 1)
    {
        // e nevoie de rebalansarea arborelui
        int Haux;
        if (H < 1)
        {
            // debalansare(?) pe partea dreapta
            Haux = balance(root->right);
            if (Haux <= 0) 
            {  
                return single_left_rotate(root);
            }
            else
            {
                return double_rightleft_rotate(root);
            }

        }
        else
        {
            Haux = balance(root->left);
            if(Haux >= 0)
            {
                return single_right_rotate(root);
            }
            else
            {
                return double_leftright_rotate(root);
            }
        }
    }
    root->height = height(root);
    return root;

}

int main()
{
    NodeT* root = NULL;
    
    root = insert_AVL(root, 1);
    root = insert_AVL(root, 2);
    root = insert_AVL(root, 3);
    root = insert_AVL(root, 4);
    root = insert_AVL(root, 5);
    root = insert_AVL(root, 6);
    root = insert_AVL(root, 7);
    root = insert_AVL(root, 8);
    root = insert_AVL(root, 9);
    root = insert_AVL(root, 10);
    root = insert_AVL(root, 11);
    Preorder(root);

 
}