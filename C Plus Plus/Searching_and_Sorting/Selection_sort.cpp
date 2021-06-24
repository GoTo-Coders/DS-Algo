/*
    Selection sort is a sorting algorithm that selects the smallest element from an unsorted list in each iteration 
    and places that element at the beginning of the unsorted list.
*/

#include <bits/stdc++.h>
using namespace std;

class selectionsort
{
private:
    int i, j, n, loc, temp, min, a[20];

public:
    int readdata();
    int sort();
    int display();
} x;
//Taking input
int selectionsort ::readdata()
{
    cout << "Enter the number of elements\n";
    cin >> n;
    cout << "Enter the elements\n";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
//Logic
int selectionsort ::sort()
{
    for (i = 0; i < n - 1; i++)
    {
        min = a[i];
        loc = i;
        for (j = i + 1; j < n; j++)
        {
            if (min > a[j])
            {
                min = a[j];
                loc = j;
            }
        }
        temp = a[i];
        a[i] = a[loc];
        a[loc] = temp;
    }
}
//Printing result
int selectionsort ::display()
{
    for (i = 0; i < n; i++)
    {
        cout << "\n"
             << a[i];
    }
}
int main()
{
    x.readdata();
    x.sort();
    x.display();
}

/*
    Input: 5
        2 5 9 8 10
    Output: 2 5 8 9 10
    
    Time complexity: O(n2)
    Space complixity: O(1)
*/
