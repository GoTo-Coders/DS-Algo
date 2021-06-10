#include<stdio.h>
#include<stdlib.h>

int BinarySearch(int a[] , int low , int high , int item)
{
    int mid;

    if(low == high)
        if(a[low] == item)              //can also write (a[high] == item)
            return low;
    else
    {
        mid = (low + high)/2;

        if(item  < a[mid])
            return BinarySearch(a , low , mid-1 , item);

        else
            return BinarySearch(a , mid+1 , high , item);
    }
    //if the element is not found return -1
    return -1;
}

int main()
{
    int n,i,item,index,low,high;

    printf("Enter size of array : ");
    scanf("%d" , &n);

    int a[n];

    printf("\nEnter elements of array(sorted order) :\n");
    for(i=0 ; i<n ; i++)
        scanf("%d" , &a[i]);

    printf("\nEnter the element you want to search : ");
    scanf("%d",&item);

    low = 0;
    high = (n-1);

    index = BinarySearch(a , low , high , item);
    if(index == -1)
        printf("\nElement not found!\n");
    else
        printf("\nElement is found on index %d.\n",index);

    return 0;
}
