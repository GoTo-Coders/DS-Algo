#include<stdio.h>
#include<stdlib.h>


void selection_sort(int a[] , int n)
{
    int i,j,k;

    for(i=0 ; i < n-1 ; i++)                //for checking position of every element
    {
        for(j=k=i ; j < n ; j++)            //for checking correct position of minimum element
        {
            if(a[j] < a[k])                 //if lesser value is found, make it pointed by "k"
                k = j;
        }
        //swap
        int temp = a[i];
        a[i] = a[k];
        a[k] = temp;
    }
}

int main()
{
    int n,i;

    printf("Enter number of elements of array : ");
    scanf("%d",&n);

    int a[n];

    printf("Enter elements of array :\n");
    for(i=0 ; i<n ; i++)
        scanf("%d",&a[i]);

    selection_sort(a,n);

    printf("\n\nSorted array is : \n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    return 0;
}

/*
can use swap function as well :

calling   swap(&a[i] , &a[k])

void swap(int *x,int *y)
{
 int temp=*x;
 *x=*y;
 *y=temp;
}

*/
