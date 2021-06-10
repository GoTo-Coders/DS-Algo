#include<stdio.h>
#include<stdlib.h>

void bin_sort(int a[], int n)
{
    int i, j;
    int count[n];
    for(i = 0 ; i < n ; i++)
        count[i] = 0;

    for(i = 0; i < n ; i++)
        count[a[i]]++;

    for(i = 0 , j = 0 ; i < n ; i++)
        for( ; count[i] > 0 ; count[i]--)
            a[j++] = i;
}

int main()
{
    int n,i;

    printf("Enter number of elements of array : ");
    scanf("%d" , &n);

    int a[n];

    printf("Enter elements of array :\n");
    for(i=0 ; i<n ; i++)
        scanf("%d" , &a[i]);

    bin_sort(a , n);

    printf("\n\nSorted array is : \n");
    for(i=0 ; i<n ; i++)
        printf("%d " , a[i]);

    return 0;
}
