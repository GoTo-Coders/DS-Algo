#include<stdio.h>
#include<stdlib.h>

void insertion_sort(int a[] , int n)
{
    int i,j,current;

    for(i=1 ; i<n ; i++)
    {
        j = i-1;
        current = a[i];

        //will swap only when larger element is found and the index(j) must be greater than -1
        while(j>=0 && a[j]>current)
        {
            a[j+1] = a[j];                      //shifting the element at next position
            j--;                                //decrementing the position of j
        }
        a[j+1] = current;                          //found the correct position so insert the number here.
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

    insertion_sort(a,n);

    printf("\n\nSorted array is : \n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    return 0;
}
