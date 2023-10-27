#include<stdio.h>
#include<stdlib.h>

void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);

    }
    printf("\n");

}

int indDeletion(int arr[],int size,int index)
{
    if (index>99)
    {
       // printf("The index of the deletion element does not exist\n");
       return -1;
    }
    else{
    for (int i=index;i<size-1;i++)
    {
        arr[i]=arr[i+1];
    }}
}

int DeletionWithValue(int *A, int size,int value)
{
    int index;
    for(int i=0;i<size;i++)
    {
        if(value ==A[i])
        {
            index=i;
            for(int i=index;i<size-1;i++)
            {
             A[i]=A[i+1];
            }
          
        
        }
    }

}


int main()
{
    int arr[100]={4,7,2,56,22};
    int size=5,index/*jo delete krne hai*/=2;
    int value=3;     //value agar delete krni ho
    display(arr,size);
    indDeletion(arr,size,index);
    //DeletionWithValue(A,size,value)
    size -=1;
    printf("New array after deletion of element\n");
    display(arr,size);
    }


