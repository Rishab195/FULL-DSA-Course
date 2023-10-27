#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *CreateNode(int value)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct Node *insert(struct Node *root, int value)
{
    if (root == NULL)
        return CreateNode(value);
    else if (root->data > value)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }
    return root;
}

void Inorder(struct Node *root)
{

    if (root != NULL)
    {
        Inorder(root->left);
        printf("%d ", root->data);
        Inorder(root->right);
    }
}

struct Node *predec(struct Node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
struct Node *DeleteNode(struct Node *root, int value)
{
    struct Node *ipre;
    if (root == NULL)
    {
        return NULL;
    }
    // if (root->right == NULL && root->left == NULL)
    // {
    //     free(root);
    //     return root;
    // }
    if (root->data > value)
    {
        root->left = DeleteNode(root->left, value);
    }
    else if (root->data < value)
    {
        root->right = DeleteNode(root->right, value);
    }
    else
    {
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        ipre = predec(root);
        root->data = ipre->data;
        root->left = DeleteNode(root->left, ipre->data);
    }
    return root;
}

int main()
{
    struct Node *root = NULL;
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 8);
    root = insert(root, 1);
    root = insert(root, 10);
    Inorder(root);
    printf("\n");
    DeleteNode(root, 1);
    DeleteNode(root, 10);
    Inorder(root);
}
