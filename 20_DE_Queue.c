#include<stdio.h>
#include<stdlib.h>

struct DEQueue{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct DEQueue *q)
{
    if(q->r==q->size-1)
    return 1;
    else
    return 0;
}

int isEmpty(struct DEQueue *q)
{
    if(q->r==q->f)
    return 1;
    else
    return 0;
}

void enqueueRear(struct DEQueue *q,int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r]=val;
        printf("Enqued element: %d\n",val);
    }
}

void enqueueFront(struct DEQueue *q,int val){
    if((isFull(q))|| (q->f!=-1)){
        printf("This Queue is full\n");
    }
    else{
       
        q->f--;
        q->arr[q->f]=val;
        printf("Enqued element: %d\n",val);

    }
}

int dequeuefront(struct DEQueue *q)
{
    int a=-1;
    if(isEmpty(q))
    {
        printf("This queue is empty\n");
    }
    else{
        q->f++;
        a=q->arr[q->f];
    }
    return a;
}

int dequeueRear(struct DEQueue *q)
{
    int a=-1;
    if(isEmpty(q))
    {
        printf("This queue is empty\n");
    }
    else{
        q->r--;
        a=q->arr[q->r];
    }
    return a;
}

int main()
{
    struct DEQueue q;
    q.size=10;
    q.f=q.r=-1;
    q.arr=(int *)malloc(q.size*sizeof(int));

    //Enqueue few elements
    enqueueRear(&q,12);
    enqueueRear(&q,23);
    enqueueRear(&q,55);
    enqueueRear(&q,87);
    enqueueRear(&q,32);
    printf("Dequeuing elements %d\n",dequeueRear(&q));
    //printf("Dequeuing elements %d\n",dequeue(&q));
    //printf("Dequeuing elements %d\n",dequeue(&q));
    enqueueFront(&q,99);


    if(isEmpty(&q)){
        printf("Queue is empty\n");
    }
    if(isFull(&q)){
        printf("Queue is full\n");
    }
    return 0;


}