/*
    Insertion sort is a simple sorting algorithm 
    that builds the final sorted array one item at a time
*/

#include <bits/stdc++.h>
using namespace std;

class insertionsort
{
    private:
    int i,j,n,a[10],temp;
    public:
    int input();
    int sort();
    int output();
}x;

//Taking input
int insertionsort::input()
{
    cout<<"Enter the number of elements\n";
    cin>>n;
    cout<<"Enter the elements\n";
    for(i=0;i<n;i++)
        cin>>a[i];
}

//Logic
int insertionsort::sort()
{
    for(i=1;i<n;i++)
    {
        temp=a[i];
        j=i-1;
        while (j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}

//Printing the result
int insertionsort::output()
{
    for(i=0;i<n;i++)
        cout<<"\n"<<a[i];
}

int main()
{
    x.input();
    x.sort();
    x.output();
}

/*
    Input: 7
           2 5 7 9 8 4 10
    Output: 2 4 5 7 8 9 10
    
    Time complexity: O(n)
    Space complixity: O(1)
*/
