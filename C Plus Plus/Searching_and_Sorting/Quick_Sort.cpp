/*
    Quick Sort is an inplace sorting algorithm based on divide and conquer approach.
    Quick sort believes on a fact that an element can be called as sorted if all the elemnts before it are smaller and after it are larger irrespective of their sequence.

    We achieve this by selecting pivot in array which can be the
    1. first element of the array
    2. last element of the array
    3. Choose any random element as pivot
    4. Median element

    Here, we have implemented quick sort by using last element of the array as pivot.

    We follow same approach and use partition() method in which the pivot is always set to its correct position (x)i.e., elements before x are smaller and elements after x are larger.

    Then recursively calls quicksort dividing the array into two parts
    1. from low(intially 0) to partition-1;
    2. from partition+1 to high.

*/


#include <bits/stdc++.h>
using namespace std;

void quick_sort(int[], int, int);
int partition(int[], int, int);
void printarr(int[], int);
void swap(int&, int&);

int main()
{
    int arr[] = {50, 65, 23, 10, 98, 35};
    int size = sizeof(arr) / sizeof(arr[0]);
    quick_sort(arr, 0, size - 1);
    printarr(arr, size);
}


void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int j = partition(arr, low, high);

        quick_sort(arr, low, j - 1);
        quick_sort(arr, j + 1, high);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low-1;
    for(int j=low; j<high-1; j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);

    return i+1;
}

void swap(int &i, int &j){
    int temp = i;
    i = j;
    j = temp;
}

void printarr(int arr[], int size){\
    cout<<"Array is : ";
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}

/*
    Time Complexity:
    1. Best Case: O(n log n)
    2. Average Case: O(n log n)
    3. Worst Case: O(n^2) ,when array is already sorted.
*/