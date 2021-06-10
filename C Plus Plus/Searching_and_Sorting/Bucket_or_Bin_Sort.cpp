#include <bits/stdc++.h>
#include <vector>
using namespace std;

void bin_sort(float a[], int n)
{
    int i,j;
    //creating buckets
    vector <float> b[n];

    //putting array elements into their respective buckets.
    for(i=0 ; i<n ; i++)
    {
        int bi = n * a[i];            //index in bucket (important step)
        b[bi].push_back(a[i]);
    }

    //sorting the individual buckets
    for (i=0 ; i<n ; i++)
        sort(b[i].begin() , b[i].end());

    //concatenating all the buckets into the array
    int index = 0;
    for(i=0 ; i<n ; i++)            //traversing buckets
        for(j=0 ; j<b[i].size() ; j++)      //traversing individual bucket
            a[index++] = b[i][j];
}


int main()
{
    int n,i;

    cout<<"Enter number of elements of array : ";
    cin>>n;

    float a[n];

    cout<<"Enter elements of array : "<<endl;
    for(i=0 ; i<n ; i++)
        cin>>a[i];

    bin_sort(a , n);

    cout<<"\n\nSorted array is : "<<endl;
    for(i=0 ; i<n ; i++)
        cout<<a[i]<<"  ";

        /*
    return 0;
    float arr[]
        = { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 };
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);

    cout << "Sorted array is \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";*/
    return 0;
}
