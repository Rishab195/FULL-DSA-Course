#include <stdio.h>
#include <stdlib.h>

void display(int arr[], int n)
{
    //transition
    for(int i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }
}
int indInsertion(int arr[],int size, int element, int capacity, int index){
    //code for insertion
    if (size>=capacity){
        return -1;
    }
    //ab index se array ke element ko end takk age khiskahana pdega
    for (int i=size-1;i>=index;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index]=element;
    return 1;

}
int main()
{
    int arr[100]={1,3,4,78};
    
    int size=4, /*Element to be inserted*/element=45, index=3;
    display(arr,size);
    printf("Array after insertion\n");
    indInsertion(arr,size,element,100,index);
    size +=1;
    display(arr,size);
    
}
