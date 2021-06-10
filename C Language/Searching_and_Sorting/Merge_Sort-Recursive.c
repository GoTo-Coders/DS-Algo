#include<stdio.h>
#include<stdlib.h>

void merging(int a[] , int low , int mid , int high)
{
    int i,j,k;
    i = low;
    j = mid+1;
    k = low;
    int b[100];
    while(i <= mid && j <= high)
    {
        if(a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }

    for( ; i <= mid ; i++)
        b[k++]=a[i];

    for( ; j <= high ; j++)
        b[k++]=a[j];

    for(i=0 ; i <= high ; i++)
        a[i] = b[i];
}

void merge_sort(int a[] , int l , int h)
{
    int mid;
    if(l < h)           //will check if at least 2 elements are there
    {
        mid = (l+h)/2;
        merge_sort(a , l , mid);
        merge_sort(a , mid+1 , h);
        merging(a , l , mid , h);
    }
}


int main()
{
    int i,n,low,high;

    printf("\nEnter total number of elements of array : ");
    scanf("%d",&n);

    int a[n];

    low=0;
    high=n-1;

    printf("\nEnter elements of array :\n");
    for(i=0 ; i < n ; i++)
        scanf("%d" , &a[i]);

    merge_sort(a , low , high);

    printf("\n\nMerged array is : \n");
    for(i=0 ; i < n ; i++)
        printf("%d " , a[i]);

    return 0;
}

