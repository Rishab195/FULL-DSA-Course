#include<stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isFull(struct stack* ptr){
    if(ptr->top== ptr->size-1)
    {
        return 1;

    }
    else{
        return 0;
    }
    
}
int isEmpty(struct stack*ptr){
    if(ptr->top==-1)
    {
        return 1;

    }
    else{
        return 0;
    }
}

void push(struct stack * ptr, int val)
{
    if(isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %d to the stack\n",val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}

int  pop(struct stack * ptr)
{
    if(isEmpty(ptr))
    {
        printf("Stack unerflow! Cannot pop to the stack\n");
        return -1;
        }
    else{
     int val=ptr->arr[ptr->top];
     ptr->top--;
     return val;

    }
}

int peek(struct stack* sp,int i)
{
    int arrayIndex=sp->top-i+1;
    if(arrayIndex<0)
    {
        printf("Not a valid position\n");
        return -1;
    }
    else{
        return sp->arr[arrayIndex];
    }
}

int stackTop(struct stack*sp){
    return sp->arr[sp->top];
}

int stackBottom(struct stack *sp)
{
    return sp->arr[0];
}

int main()
{
    struct stack *sp=(struct stack *)malloc (sizeof(struct stack));
    sp->size=10;
    sp->top=-1;
    sp->arr=(int *)malloc(sizeof(int));
    printf("stack has been created successfully\n");

    printf("Before pushing, Full:%d\n",isFull(sp));
    printf("Before pushing, Full:%d\n",isEmpty(sp)); 
    push(sp,1);
    push(sp,56);
    push(sp,53);
    push(sp,577);
    push(sp,89);
    push(sp,11);
    push(sp,22);
    push(sp,56);
    push(sp,43);
    push(sp,90);        //Pushed 10 values
    push(sp,99);        //Stack overflows Since the size of stack is 10
    printf("After pushing, Full:%d\n",isFull(sp));
    printf("After pushing, Empty:%d\n",isEmpty(sp));

    printf("Popped %d from the stack\n",pop(sp));   //Last in First out
    printf("Popped %d from the stack\n",pop(sp));
    printf("Popped %d from the stack\n",pop(sp));

    for(int j=1;j<= sp->top+1;j++){
    printf("The value at position %d is %d\n",j,peek(sp,j));}

    printf("The top most element of the stack is %d\n",stackTop(sp));
    printf("The bottom most element of the stack is %d\n",stackBottom(sp));
return 0;
}