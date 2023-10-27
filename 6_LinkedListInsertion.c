                                //Linked List Insertion
#include<stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node*next;  
};

void linkedListTraversal(struct Node* ptr)
{
    while(ptr!=NULL)
    {
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next;
    }
}

//CASE1


//CASE2
struct Node * insertAtIndex(struct Node*head,int data,int index)
{
    struct Node* ptr=(struct Node*) malloc (sizeof(struct Node));
    struct Node *p=head;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}

//CASE3 
struct Node*insertAtEnd(struct Node*head,int data)
{
    struct Node* ptr=(struct Node* )malloc(sizeof(struct Node*));
    ptr->data=data;
    struct Node* p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}

//CASE4
struct Node* insertAfterNode(struct Node*head ,struct Node *PrevNode,int data)
{
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=PrevNode->next;
    PrevNode->next=ptr;
    return head;
}


int main()
{
    struct Node *head;
    struct Node*second;
    struct Node * Third;
    struct Node * fourth;
    struct Node * fifth;

    //Allocate the memory in the heap
    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    Third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc (sizeof(struct Node));
    fifth =(struct Node*)malloc(sizeof(struct Node));

    //Linked Lists
    head ->data=7;
    head->next =second;

    second ->data=12;
    second->next= Third;
    
    Third->data=323;
    Third ->next=fourth;

    fourth ->data =35;
    fourth ->next=fifth;

    fifth ->data=77;
    fifth ->next=NULL;


    linkedListTraversal(head);
    head=insertAtFirst(head,56);
    //head=insertAtIndex(head,56,1);
   // head=insertAtEnd(head,56);
   //head=insertAfterNode(head,second,56);
    printf("List after insertion\n");
    linkedListTraversal(head);

    return 0;
}