#include<stdio.h>
#include<stdlib.h>
 struct Node{
    int data;
    struct Node*prev;
    struct Node*next;
};

void linkedListTraversal(struct Node* ptr)
{
    while(ptr!=NULL)
    {
        printf("Element:%d\n ",ptr->data);
        ptr=ptr->next;
        
    }
}

void Backwardtraversal(struct Node *tail)
{
    while(tail!=NULL)
    {
        printf("Element:%d",tail->data);
        tail=tail->prev;
    }
}

int main()
{
    struct Node* head;
    struct Node*second;
    struct Node*third;
    struct Node*fourth;

    //Allocate the memory in the dynamic memory
    head= (struct Node*)malloc(sizeof(struct Node));
    second=(struct Node* )malloc (sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));

    //Linked nodes to each other
    head->data=11;
    head->prev=NULL;
    head->next=second;
    
    second->data=22;
    second->prev=head;
    second->next=third;
    
    third->data=33;
    third->prev=second;
    third->next=fourth;
    
    fourth->data=44;
    fourth->prev=third;
    fourth->next=NULL;
    
    //Traversal of list
    linkedListTraversal(head);
    printf("Backward Traversal\n");
    Backwardtraversal(head);
    return 0;
       }