#include<stdio.h>

int linearSearch(int arr[],int size,int element){
    for (int i=0;i<size;i++)
    {
        if (arr[i]==element){
            return i;
        }
    }return -1;
}

int binarySearch(int *A ,int n,int element)
{
    int low=0;int high;int mid;
    high=n-1;
    
    while(low<=high)
    {
        mid=(low+high)/2;
        if(A[mid]==element)
        {return mid;}
        if(A[mid]<element)
        {
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;

}

int main()
{
   // unsorted array for linear search
    //int arr[]={1,2,3,5,6,98,56,32,44,66,78};/*Not a sorted array*/
    //int size=sizeof(arr)/sizeof(int);

    //sorted array for Binary search
    int arr[]={1,2,3,5,6,98,156,232,244,266,278};
    int size=sizeof(arr)/sizeof(int);
    int element=278;
    //int searchIndex = linearSearch(arr,size,element);
    int searchIndex = binarySearch(arr,size,element);
    printf("The element %d was found at index %d",element,searchIndex);
    return 0; 
}