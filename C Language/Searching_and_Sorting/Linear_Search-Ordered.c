#include<stdio.h>
#include<stdlib.h>

void Bubble_Sort(int a[] , int n)
{
    int flag;
    for(int i=0 ; i < (n-1) ; i++)
    {
        flag = 0;
        for(int j=0 ; j < (n-1-i) ; j++)
        {
            if(a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = 1;
            }
        }
        if(flag == 0)
            break;
    }
}

void UnOrdered_List(int array[] , int n , int item)
{
    int element_index=0;
    int flag=0;

    for(int i=0 ; i < n ; i++)
        if(item == array[i])
        {
            flag = 1;
            element_index = i;
            break;
        }

    if(flag == 1)
        printf("\nArray is sorted.\nElement is found on index %d." , element_index);
    else
        printf("\nElement not found!\n");
}

int main()
{
    int i,n,item;

    printf("\nEnter size of array : ");
    scanf("%d" , &n);

    int array[n];

    printf("\nEnter elements of the array\n");
    for(i=0 ; i < n ; i++)
        scanf("%d" , &array[i]);

    printf("\nEnter the element to be searched : ");
    scanf("%d" , &item);

    Bubble_Sort(array , n);

    UnOrdered_List(array , n , item);

    return 0;
}

