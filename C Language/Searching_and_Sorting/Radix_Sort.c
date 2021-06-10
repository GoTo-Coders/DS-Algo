#include<stdio.h>
#include<stdlib.h>

// Function to get the largest element from an array
int getMax(int a[] , int n)
{
    int max = a[0] , i;
    for (i = 1 ; i < n ; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

void count_sort(int a[], int n, int place)
{
    int output[n];                  // output array
    int count[10];
    int i;

    //Initializing the array with 0
    for(i=0 ; i < 10 ; i++)
        count[i] = 0;

    //storing the count of occurrences in count array
    for (i = 0; i < n; i++)
        count[(a[i] / place) % 10]++;

    // change count[i] so that count[i] now contains actual
    // position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n-1 ; i >= 0 ; i--)
    {
        output[count[(a[i] / place) % 10] - 1] = a[i];          //important step
        count[(a[i] / place) % 10]--;
    }

    // Copy the output array to a[], so that a[] now
    // contains sorted numbers according to current digit
    for (i = 0 ; i < n ; i++)
        a[i] = output[i];
}


// Main function to implement radix sort
void radix_sort(int a[], int n)
{
    int place = 1;
    // Get maximum element
    int max = getMax(a , n);

    // Apply counting sort to sort elements based on place value.
            //for (place = 1; max / place > 0; place *= 10)
                //count_Sort(a , n , place);
    while(place <= max)
    {
        count_sort(a , n , place);
        place = place*10;           //incrementing place value (onces -->tens--> hundred)
    }

}

int main()
{
    int n,i,l,h;

    printf("Enter number of elements of array : ");
    scanf("%d" , &n);

    int a[n];

    printf("Enter elements of array :\n");
    for(i=0 ; i<n ; i++)
        scanf("%d" , &a[i]);

    radix_sort(a , n);

    printf("\n\nSorted array is : \n");
    for(i=0 ; i<n ; i++)
        printf("%d " , a[i]);

    return 0;
}
