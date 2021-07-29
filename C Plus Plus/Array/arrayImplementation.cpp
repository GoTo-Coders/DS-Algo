/*
	Array is a linear data structure, which stores the elements in a contiguous memory locations.
	Arrays can be said as a list of similar types of elements i.e., an array can store the values
	with similar data type. 
	For example: if an array is of integer type, then it can store only integer varibles.
	Array can be of both predefined data types such as int, bool, etc. as well as user-defined
	data types such as structures, classes, etc.
	Operations performed on an array are:
		1. Insertion
		2. Traversal and Searching
		3. Updation
		4. Deletion
*/

// Implementation
#include<bits/stdc++.h>
using namespace std;

// array size var declaraion as global
int n;
// Function to insert element in array
void insert(int arr[], int n)
{
    for(int i=0;i<n;i++)
        cin>>arr[i];
}

// Function to update element in array
void update(int arr[], int pos, int val)
{
    arr[pos-1] = val;
}

// Function to delete element in array
void deletion(int arr[], int pos)
{
    for(int i=pos-1;i<n-1;i++)
        arr[i] = arr[i+1];
    n--;
}

// Function to print array
void print(int arr[])
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}

// Function to sort array
void sort(int arr[])
{
    sort(arr,arr+n);
}

// Funtion to find element in array
void search(int arr[], int val)
{
    sort(arr);
    if (binary_search(arr, arr+n, val))
        cout << "\nElement found in the array";
    else
        cout << "\nElement not found in the array";
}

int main()
{
    cout<<"Enter size of array\n";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of array\n";
    insert(arr,n);
    cout<<"\nUpadate array element\n";
    int pos, val;
    cout<<"Enter position to be updated\n";
    cin>>pos;
    cout<<"Enter value to be updated\n";
    cin>>val;
    update(arr,pos,val);
    cout<<"\nArray after updation";
    print(arr);
    cout<<"\n\nDelete array element\n";
    int pos1;
    cout<<"Enter position to be deleted\n";
    cin>>pos1;
    deletion(arr, pos1);
    cout<<"\nArray after deletion\n";
    print(arr);
    cout<<"\n\nSort array\n";
    sort(arr);
    cout<<"\nArray after sorting\n";
    print(arr);
    cout<<"\n\nSearch element in array\n";
    int val1;
    cout<<"Enter element to be searched\n";
    cin>>val1;
    search(arr,val1);
    return 0;
}

/*
    Time complexity: 
        1. Insertion : O(n)
        2. Updation : O(1)
        3. Deletion : O(n)
        4. Sorting : O(n logn)
        5. Searching : O(n logn)
        
    Space complexity of program is O(n)
*/
