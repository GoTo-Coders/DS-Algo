#include<stdio.h>
#include<stdlib.h>

int BinarySearch(int a[] , int n , int item)
{
    int low,mid,high;

    low = 0;
    high = n;

    while(low <= high)
    {
        mid = (low + high)/2;

        if(item == a[mid])
            return mid;

        else if(item < a[mid])
            high = (mid - 1);

        else
            low = (mid + 1);
    }

    return 0;
}

int main()
{
    int n,i,item,index;

    printf("Enter the size of array : ");
    scanf("%d" , &n);

    int a[n];

    printf("Enter elements of array(sorted order) : \n");
    for(i=0 ; i<n ; i++)
        scanf("%d" , &a[i]);

    printf("\nEnter the element you want to search : ");
    scanf("%d" , &item);

    index = BinarySearch(a , n-1 , item);

    if(index == 0)
        printf("\nElement is not found!\n");
    else
        printf("\nElement is found on index %d.\n",index);

    return 0;
}
