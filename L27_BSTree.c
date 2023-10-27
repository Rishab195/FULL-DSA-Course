#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*left;
    struct Node*right;
};

struct Node* createNode(int data)
{
    struct Node*n;
    n=(struct Node*)malloc(sizeof(struct Node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

void Inorder(struct Node*root)
{
    if(root!=NULL)
    {
        Inorder(root->left);
        printf("%d ",root->data);
        Inorder(root->right);
    }
}

int isBST(struct Node*root)
{
    static struct Node*prev=NULL;
    if(root!=NULL)
    {
        if(!isBST(root->left))
        {
            return 0;
        }
        if(prev!=NULL && root->data<=prev->data)
        {
            return 0;
        }
        prev=root;
        return isBST(root->right);
    }
    else{
        return 1;
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
    if(isBST(p)){
        printf("This is a bst" );
    }
    else{
        printf("This is not a bst");
    }
    return 0;

}