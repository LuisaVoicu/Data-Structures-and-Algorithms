#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

    struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };
 
    struct TreeNode* create(int key)
    {
        struct TreeNode* nod = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        nod->val = key;
        nod->left = nod->right = NULL;
        return nod;
    }
    struct TreeNode* buidBST(int* A, int st, int dr)
    {
        if (st > dr)
            return NULL;
        int mid = (st + dr) / 2;
        struct TreeNode* tree = create(A[mid]);
        tree->left = buidBST(A, st, mid - 1);
        tree->right = buidBST(A, mid + 1, dr);
        return tree;
    }



struct TreeNode* sortedArrayToBST(int* nums, int numsSize) 
{
    if (numsSize == 0)
        return NULL;
    return buidBST(nums, 0, numsSize - 1);
}


void preorder(struct TreeNode* root)
{
    if (root != NULL)
    {
        printf("%d ", root->val);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    int v[] = { -10,-3,0,5,9 };
    int n = sizeof(v) / sizeof(int);
    struct TreeNode* root = sortedArrayToBST(v, n);

    preorder(root);
}