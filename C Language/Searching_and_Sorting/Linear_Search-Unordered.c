#include<stdio.h>
#include<stdlib.h>

void Ordered_List(int array[] , int n , int item)
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
        printf("\nElement is found on index %d.\n" , element_index);
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

    Ordered_List(array , n , item);

    return 0;
}
