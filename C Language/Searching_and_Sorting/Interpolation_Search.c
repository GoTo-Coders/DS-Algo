#include<stdio.h>
#include<stdlib.h>

int Interpolation_Search(int a[] , int n , int item)
{
    int low = 0;
    int high = n-1;
    int pos=0;

    while(low <= high)
    {
        pos = low + (((high - low) / (a[high] - a[low])) * (item - a[low]));

        if(a[pos] == item)
            return pos;

        else if(a[pos] > item)
            high = pos-1;

        else
            low = pos+1;
    }
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

    index = Interpolation_Search(a , n , item);
    if(index == -1)
        printf("\nElement not found!\n");
    else
        printf("\nElement is found on index %d.\n",index);

    return 0;
}

