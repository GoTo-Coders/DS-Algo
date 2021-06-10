#include<stdio.h>
#include<stdlib.h>

void swap(int *x , int *y)
{
    int temp=*x;
    *x = *y;
    *y = temp;
}

int partition(int a[] , int start , int end)
{
    int pivot = a[start];
    int i = start;
    int j = end;

    while(i < j)
    {
        while(a[i] <= pivot)
            i++;

        while(a[j] > pivot)
            j--;

        if(i < j)
            swap(&a[i] , &a[j]);
    }
    swap(&a[start] , &a[j]);

    return j;
}

/*
OTHER WAY OF PARTITIONING:
int partition(int a[] , int start , int end)
{
    int pivot = a[end];         //selecting the pivot element
    int pIndex = start;         //initially partition-index will be at starting

    for(int i=start ; i<end ; i++)
    {
        //if an element is lesser than pivot, swap it.
        if(a[i] <= pivot)
        {
            swap(&a[i] , &a[pIndex]);
            pIndex++;               //incrementing pIndex for further swapping.
        }
    }
    swap(&a[pIndex] , &a[end]);     //lastly swapping or the correct position of pivot
    return pIndex;
}
*/

void quick_sort(int a[] , int start , int end)
{
    int pivot;
    //we will not call quick_sort if there is only one element
    if(start < end)
    {
        pivot = partition(a , start , end);
        quick_sort(a , start , pivot-1);
        quick_sort(a , pivot+1 , end);
    }
}

int main()
{
    int n,i,start,end;

    printf("Enter number of elements of array : ");
    scanf("%d" , &n);

    int a[n];

    printf("Enter elements of array :\n");
    for(i=0 ; i<n ; i++)
        scanf("%d" , &a[i]);

    start = 0;
    end = n-1;
    quick_sort(a , start , end);

    printf("\n\nSorted array is : \n");
    for(i=0 ; i<n ; i++)
        printf("%d " , a[i]);

    return 0;
}


