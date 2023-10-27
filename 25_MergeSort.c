#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int *A,int mid,int low,int high)
{
    int i,j,k,B[100];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high)
    {
        if(A[i]<A[j])
        {
            B[k]=A[i];
            i++;
            k++;
        }
        else{
            B[k]=A[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        B[k]=A[i];
        k++;
        i++;
    }
    while(j<=high)
    {
        B[k]=A[j];
        k++;
        j++;
    }
    for(int i=low;i<=high;i++)
    {
        A[i]=B[i];
    }
}

void MergeSort(int *A,int low ,int high)
{
    int mid;
    if(low<high){
    mid=(low+high)/2;
    MergeSort(A,low,mid);
    MergeSort(A,mid+1,high);
    merge(A,mid,low,high);
    }

}

int main()
{
    int A[] = {1,3,2,7,4,4};
    int n =6;
    printArray(A, n);
    MergeSort(A, 0,5);
    printArray(A, n);
    return 0;
}