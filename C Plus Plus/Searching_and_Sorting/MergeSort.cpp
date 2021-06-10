/*
	Merge Sort as the name suggests is a sorting algorithm based on Divide and Conquer approach.
	It divides the array into two parts and recursively calls itself and the merge() function
	which merges the sorted subarrays.
*/ 


#include<iostream>
#include<stdlib.h>
using namespace std;
 
 
//Definition of merge() method.
void merge(int arr[], int first, int last)
{
	int size = last-first+1;  //calculating size of the array to temporarily store values.
	int temp[size];
	
	int mid = (first+last)/2;
	
	int i = 0, j = first, k = mid+1,m=0;
	//Here j and k describes the range of array for which 
	//the array has to be sorted and merged.
	while(j<=mid && k<=last)
	{
		if(arr[j]<arr[k])
		{
			temp[i]=arr[j];
			j++;
		}
		else
		{
			temp[i] = arr[k];
			k++; 
		}
		i++;
	}
	
	//Copying the remaining elements of
	//the array, if any
	if(j<=mid)
	{
		while(j<=mid)
		{
			temp[i]=arr[j];
			j++;
			i++;
		}
	}
	else
	{
		while(k<=last)
		{
			temp[i] = arr[k];
			k++;
			i++;
		}
	}
	
	//Copying the data of temp to arr.
	while(m<i)
	{
		arr[first+m] = temp[m];
		m++;
	}
}

//Definition of merge_sort() method.
void merge_sort(int arr[],int first, int last)
{
	int mid;
	if(first<last)
	{
		//Base condition whether the lower bound
		//is less than upper bound to execute further.
		mid = (first+last)/2 ;
		
		merge_sort(arr,first,mid); //calling merge sort for the first part of array from first element upto mid.
		merge_sort(arr,mid+1,last);  //calling merge sort for the second part of array from mid+1 element upto high.
		merge(arr,first,last);  //calling merge to merge the above sorted arrays.
	}
}

int main()
{
	int arr[10] = {98,86,54,25,97,35,15,85,56,24};
	merge_sort(arr , 0 , 10);
	for(int i=0;i<10;i++)
	{
		cout<<arr[i]<<" ";	
	}
}


/* 
	Time Complexity - O(n*Log n)
	Space Compleity - O(n)
