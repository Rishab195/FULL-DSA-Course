#include<stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

void linkedListTraversal(struct Node * head)
{
    struct Node *ptr=head;
    
    do{
        printf(" Element: %d\n",ptr->data);
        ptr = ptr-> next;
    } while (ptr!=head);
}


struct Node* insertAtFirst(struct Node* head,int data)
{
    struct Node* ptr=(struct Node*)malloc (sizeof(struct Node));
    ptr->data=data;
    struct Node *p=head->next;
    while(p->next!=head)
    {
        p=p->next;

    }
    //At this point P points to the last node of this circular Linked List
    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;
}

struct Node* insertAtLast(struct Node* head,int data)
{
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node* p=head->next;
    while(p->next!=head)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
   //Allocate memory for nodes in the linked list in Heap
   head=(struct Node *) malloc(sizeof(struct Node));
   second=(struct Node *) malloc (sizeof(struct Node));
    third=(struct Node *) malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc (sizeof(struct Node)); 
    
    //linked first and second
    head -> data =7;
    head -> next = second;

    //Linked second and third
    second -> data = 11;
    second -> next = third;

    //Linked third and fourth
    third -> data = 66;
    third -> next = fourth;

    //Terminate the list at the fourth  node
    fourth -> data = 23;
    fourth -> next = head; 
    
    printf("Circular list after insertion\n");
    linkedListTraversal(head);
    head=insertAtFirst(head,80);
    //head=insertAtFirst(head,54);
    //head=insertAtLast(head,100);

    printf("Circular List after insertion\n");
     linkedListTraversal(head);

return 0;

}

