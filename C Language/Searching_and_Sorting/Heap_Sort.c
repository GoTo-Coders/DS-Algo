#include<stdio.h>
#include<stdlib.h>

//in place heap creation
void insert(int a[] , int n)
{
    int temp = a[n];
    int i = n;
    int parent = (i-1)/2;

    while(i>0 && temp > a[parent])
    {
        a[i] = a[parent];
        i = parent;
        parent = (i-1)/2;
    }
    a[i] = temp;
}

void createHeap(int a[] , int n)
{
    for(int i=1 ; i<n ; i++)
        insert(a , i);
}

void deleteHeap(int a[] , int n)
{
    int i=0 , j=0;
    int temp = a[n-1];
    int temp2 = a[0];
    a[i] = a[n-1];
    int lchild = 2*i+1;
    int rchild = 2*i+2;

    while((temp < a[lchild] || temp < a[rchild]))
    {
        if(a[lchild] > a[rchild])
            j = lchild;
        else
            j = rchild;

        if(j < n)
        {
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
        else
            break;

        temp = a[j];
        i = j;
        lchild = 2*i+1;
        rchild = 2*i+2;
    }
    a[n-1] = temp2;
}

int main()
{
    int n,i,m;

    printf("Enter number of elements of array : ");
    scanf("%d",&n);

    int a[n];

    printf("Enter elements of array :\n");
    for(i=0 ; i<n ; i++)
        scanf("%d",&a[i]);

    createHeap(a , n);                      //creating heap (Heapify)
    int size = n;

    for(i=size ; i>0 ; i--)                    //deleting the largest element
    {
        deleteHeap(a , i);
        n = n-1;                            //decrementing size of array
    }

    printf("\n\nSorted array is : \n");
    for(i=0 ; i<size ; i++)
        printf("%d ",a[i]);

    return 0;
}
