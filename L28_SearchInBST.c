#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*left;
    struct Node*right;
};

struct Node*createNode(int data)
{
    struct Node*n;
    n=(struct Node*)malloc(sizeof(struct Node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

void Inorder(struct Node* root)
{
    if(root!=NULL)
    {
        Inorder(root->left);
        printf("%d ",root->data);
        Inorder(root->right);
    }
}
struct Node*search(struct Node*root,int value)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==value)
    {
        return root;
    }
    else if(root->data>value)
    {
        return search(root->left,value);
    }
    else{
        return search(root->right,value);
    }
}

int main()
{
    struct Node*p=createNode(9);
    struct Node*p1=createNode(4);
    struct Node*p2=createNode(11);
    struct Node*p3=createNode(2);
    struct Node*p4=createNode(7);
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    Inorder(p);
    printf("\n");
    struct Node*n=search(p,7);
    if(n!=NULL)
    {
        printf("Found: %d ",n->data);

    }
    else
    printf("NOT FOUND\n");
}
