// C++ implementation of the above approach

#include <iostream>
using namespace std;

// Function to perform the insertion sort
int part = 0;
void insertion_sort(int arr[], int low, int n)
{

    for (int i = low + 1;i < n + 1;i++)
    {
        int val = arr[i];
        int j = i;
        while (j > low && arr[j - 1] > val)
        {
            arr[j] = arr[j - 1];
            j -= 1;
        }
        arr[j] = val;
    }

}

//The following two functions are used
// to perform quicksort on the array.


// Partition function for quicksort

int partition(int arr[], int low, int high)
{
    part++;
    int pivot = arr[low];
    int i, j;
    i = low;
    j = low;

    for (int i = low; i < high; i++)
    {
        if (arr[i] < pivot)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j += 1;
        }
    }

    int temp = arr[j];
    arr[j] = arr[high];
    arr[high] = temp;

    return j;
}


// Function to call the partition function
// and perform quick sort on the array


void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quick_sort(arr, low, pivot - 1);
        quick_sort(arr, pivot + 1, high);


    }
}

// Hybrid function -> Quick + Insertion sort

void hybrid_quick_sort(int arr[], int low, int high)
{
    while (low < high)
    {

        // If the size of the array is less
        // than threshold apply insertion sort
        // and stop recursion

        if (high - low + 1 < 10)
        {
            insertion_sort(arr, low, high);
            break;
        }

        else

        {
            int pivot = partition(arr, low, high);

            // Optimised quicksort which works on
            // the smaller arrays first

            // If the left side of the pivot
            // is less than right, sort left part
            // and move to the right part of the array

            if (pivot - low < high - pivot)
            {
                hybrid_quick_sort(arr, low, pivot - 1);
                low = pivot + 1;
            }
            else
            {

                // If the right side of pivot is less
                // than left, sort right side and
                // move to the left side

                hybrid_quick_sort(arr, pivot + 1, high);
                high = pivot - 1;
            }

        }

    }
}
// Driver Code
int main()
{
    int arr[16] = { 9, 12, -6, 7, 44, 22, 10, 16, -2, 56, -18, 33, 75, 18, 22, 16 };

    hybrid_quick_sort(arr, 0, 15);
    cout << "PART " << part << endl;
    for (int i = 0; i < 16; i++)
        cout << arr[i] << ", ";
}

// This code is contributed by ishayadav2918
