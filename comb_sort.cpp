// C++ implementation of Comb Sort
#include <iostream>
using namespace std;

int zamiana = 0;
int porownan = 0;
int przejscie = 1;
// To find gap between elements
int getNextGap(int gap)
{
    // Shrink gap by Shrink factor
    gap = (gap * 10) / 13;

    if (gap < 1)
        return 1;
    return gap;
}

// Function to sort a[0..n-1] using Comb Sort
void combSort(int a[], int n)
{
    // Initialize gap
    int gap = n;

    // Initialize swapped as true to make sure that
    // loop runs
    bool swapped = true;

    // Keep running while gap is more than 1 and last
    // iteration caused a swap
   
    while (gap != 1 || swapped == true)
    {
        
        // Find next gap
        gap = getNextGap(gap);

        // Initialize swapped as false so that we can
        // check if swap happened or not
        swapped = false;
        
        // Compare all elements with current gap
        
        for (int i = 0; i < n - gap; i++)
        {
            porownan++;
            if (a[i] > a[i + gap])
            {
                ++zamiana;
                swap(a[i], a[i + gap]);
                swapped = true;
                
            }
            
        }
        
        cout << "Przejscie: " << przejscie++ <<" zamian: "<<zamiana<< " porowniania: "<< porownan << endl;
    }
}

// Driver program
int main()
{
    int a[] = { 3, 77, -6, -59, 9, 11, 15, 0, -1, 20, -6 };
    int n = sizeof(a) / sizeof(a[0]);

    combSort(a, n);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    cout << "lacznie zamian: " << zamiana << endl;
    cout << "lacznie porownan: " << porownan << endl;
    return 0;
}
