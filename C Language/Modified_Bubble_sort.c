#include<stdio.h>
void MbubbleSort(int a[],int n)
{
    int t,flag;
    for(int i=1;i<=n-1;i++)
    {
        flag=0;
        for(int j=0;j<=n-1-i;j++)
        {
           if(a[j]>a[j+1])
           {
               flag=1;
               t=a[j];
               a[j]=a[j+1];
               a[j+1]=t;
           }
        }
        if(flag==0)
        {
            printf("i=%d\n",i);
         return;
        }

    }

}
int main()
{
    int a[]={4,5,10,15,30};
    MbubbleSort(a,5);
    for(int i=0;i<5;i++)
    {

        printf(" %d",a[i]);
    }
    return 1;
}

