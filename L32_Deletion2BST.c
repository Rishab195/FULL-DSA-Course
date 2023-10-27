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

void InOrder(struct Node*root)
{
    if(root!=NULL)
    {
        InOrder(root->left);
        printf("%d ",root->data);
        InOrder(root->right);
    }
}

struct Node*inorderPredecessor(struct Node*root)
{
    root=root->left;
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root;
}

struct Node*deleteNode(struct Node*root,int value)
{
   if(root==NULL){
    printf("This value doenot exixt\n");
   return NULL;
   }
   if(root->data==value)
   {
    if(root->left==NULL && root->right==NULL)
    {
        free(root);
        return NULL;
    }
    if(root->left!=NULL && root->right==NULL)
    {
        struct Node*temp=root->left;
        free(root);
        return temp;
    }
     if(root->left==NULL && root->right!=NULL)
    {
        struct Node*temp=root->right;
        free(root);
        return temp;
    }
    if(root->left!=NULL && root->right!=NULL)
    {
        int ipre=inorderPredecessor(root->left)->data;
        root->data=ipre;
        root->left=deleteNode(root->left,ipre);
        return root;
    }
   }
   else if(root->data>value)
   {
    root->left=deleteNode(root->left,value);
    return root;
   }
   else{
    root->right=deleteNode(root->right,value);
    return(root);
    
   }
   return root;

}

int main()
{
    struct Node *p = createNode(5);
    struct Node *p1 = createNode(3);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(1);
    struct Node *p4 = createNode(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    InOrder(p);
    printf("\n");
    deleteNode(p, 6);
    InOrder(p);
    return 0;
}