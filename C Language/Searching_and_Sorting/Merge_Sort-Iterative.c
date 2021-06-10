#include<stdio.h>
#include<stdlib.h>


//merging of sub-sorted array
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

    for( ; i <=mid ; i++)
        b[k++]=a[i];

    for( ; j <= high ; j++)
        b[k++]=a[j];

    for(i=0 ; i <= high ; i++)
        a[i] = b[i];
}

void merge_sort(int a[] , int n)
{
    int p,l,h,m,i;

    //this for loop will take account of number of passes
    //in each pass number of elements is increasing by previous*2;
    for(p=2 ; p <= n ; p=p*2)
    {
        for(i=0 ; i+p-1 < n ; i=i+p)        //for choosing number of elements in each pass
        {
            l = i;
            h = i+p-1;
            m = (l+h)/2;
            merging(a , l , m , h);
        }
    }
    if(p/2 < n)                             //when number of elements is odd
        merging(a , 0 , p/2 , n-1);
}


int main()
{
    int i,n;

    printf("\nEnter total number of elements of array : ");
    scanf("%d",&n);

    int a[n];

    printf("\nEnter elements of array :\n");
    for(i=0 ; i < n ; i++)
        scanf("%d" , &a[i]);

    merge_sort(a , n);

    printf("\n\nMerged array is : \n");
    for(i=0 ; i < n ; i++)
        printf("%d " , a[i]);

    return 0;
}
