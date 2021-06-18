/*
    Bubble Sort is a simple algorithm which is used to sort a given set of n elements 
    provided in form of an array with n number of elements. 
    Bubble Sort compares all the element one by one and sort them based on their values.
*/

#include <bits/stdc++.h>
using namespace std;

class bubblesort
{
    private:
    int i,j,n,a[10],temp;
    public:
    void input();
    void sort();
    void output();
}x;

//Taking Input
void bubblesort :: input()
{
    cout<<"Enter the number of elements  ";
    cin>>n;
    cout<<"\nEnter the elements\n";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
}

//Logic
void bubblesort :: sort()
{
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

//Printing the result
void bubblesort :: output()
{
    for(i=0;i<n;i++)
    {
        cout<<"\n"<<a[i];
    }
}

int main()
{
    x.input();
    x.sort();
    x.output();       
}

/*
    Input: 6
           2 5 7 9 4 10
    Output: 2 4 5 7 9 10
    
    Time complexity: O(n2)
    Space complixity: O(1)
*/
