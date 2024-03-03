///////****** Quick Sort ******////////

#include <bits/stdc++.h>
using namespace std;

//// Quick Sort:  (Divide & Conquer Algorithm)

// -> Step 1: First Pick up any Pivot element from the array and place it in its correct place. The pivot element can be the first element or the last element or the median element or any random element from the array.
// -> Step 2: Smaller on the left and larger on the right.
// -> Step 3: Continue the upper steps till each array left with one element.

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }
        while (arr[j] > pivot && j >= low)
        {
            j--;
        }
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void qs(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int partitionIdx = partition(arr, low, high);
        qs(arr, low, partitionIdx - 1);
        qs(arr, partitionIdx + 1, high);
    }
}

vector<int> quickSort(vector<int> arr)
{
    qs(arr, 0, arr.size() - 1);
    return arr;
}

int main()
{
    vector<int> arr = {4, 5, 1, 2, 6, 7, 9};
    cout << "Before quick sort the array is looking like: ";
    for (auto it : arr)
    {
        cout << it << " ";
    }

    arr = quickSort(arr);

    cout << "\n\nAfter quick sort the array is looking like: ";
    for (auto it1 : arr)
    {
        cout << it1 << " ";
    }
    return 0;
}