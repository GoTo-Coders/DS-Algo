#include<stdio.h>
#include<stdlib.h>

int findMax(int A[] , int n)            //to return the maximum element of the array
{
    int max = A[0];
    int i;
    for(i=0 ; i < n ; i++)
    {
        if(A[i] > max)
            max = A[i];
    }
    return max;
}


void count_sort(int A[] , int n)
{
    int i,j,max;

    max = findMax(A , n);

    //count array will contain count or frequency of elements
    int count[max+1];

    //Initializing the array with 0
    for(i=0 ; i < max+1 ; i++)
        count[i]=0;

    //Increasing the corresponding index in the count array
    for(i=0 ; i < n ; i++)
        count[A[i]]++;

    i=0;                  //counter for frequency(count) array
    j=0;                  //counter for input array

    //will run the loop till the end of count array
    while(i < max+1)
    {
        //if element (count[j]) is present, then its frequency must be greater than 0
        if(count[i] > 0)
        {
            A[j++] = i;         //copying the element at index j and incrementing j by 1
            count[i]--;         //decreasing the frequency by 1
        }
        //else will execute if the frequency is 0. So, we have to go to the next index.
        else
            i++;
    }
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

    count_sort(a , n);

    printf("\n\nSorted array is : \n");
    for(i=0 ; i<n ; i++)
        printf("%d " , a[i]);

    return 0;
}


