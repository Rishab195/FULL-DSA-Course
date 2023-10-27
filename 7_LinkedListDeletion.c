#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf(" Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// CASE 1
struct Node *DeletingFirstNode(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// CASE2
struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

// CASE 3
struct Node *deleteAtEnd(struct Node *head)

{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

// CASE4 Deleting the element with a given value
struct Node *deletewithvalue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // linked first and second
    head->data = 7;
    head->next = second;

    // Linked second and third
    second->data = 11;
    second->next = third;

    // Linked third and fourth
    third->data = 66;
    third->next = fourth;

    // Terminate the list at the fourth  node
    fourth->data = 23;
    fourth->next = NULL;

    linkedListTraversal(head);
    // head=DeletingFirstNode(head);
    // head=deleteAtIndex(head,1);
    // head=deleteAtEnd(head);
    head = deletewithvalue(head, 11);
    printf("List after Deletion\n");
    linkedListTraversal(head);
    return 0;
}