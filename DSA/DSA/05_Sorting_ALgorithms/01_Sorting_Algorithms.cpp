///////  Sorting Algorithms  ///////////

#include <bits/stdc++.h>
using namespace std;

/// Selection Sort:
void selection_sort(int arr[], int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        int mini = i;

        for (int j = i; j <= n - 1; j++)
        {
            if (arr[j] < arr[mini])
            {
                mini = j; // getting the minimum
            }
        }
        // sort the min with the ith index.
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;

        // swap(arr[mini], arr[i]);
    }

    //// for TC: here the pattern is like: n + (n-1) + (n-2)+ (n-3) + ......
    //// which is like: n*(n+1)/2
    /// so, we can say that the TC for this is: O(n^2) for best, avg & worst
}

// Bubble Sort:
// -> push the max element to the end using adjacent swapping.
void bubble_sort(int arr[], int n)
{
    for (int i = n - 1; i >= 1; i--)
    {
        int didSwap = 0;
        for (int j = 0; j <= (i - 1); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                didSwap = 1;
            }
        }
        if (didSwap == 0)
            break; // means the arrr is already sorted, there is no need to run the loop again.
        // cout << "runs\n";
    }
    // here also the TC is quite similar like Selection Sort.
    // So, the complexity is O(n^2) but for the worst/avg complexity.
    // for best case, O(n)
}

///// Insertion Sort:
// Take an element & place it in its correct order.
void insertion_sort(int arr[], int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
            // cout << "runs\n";
        }
    }
    /// for worst case the TC is : O(n^2) for worst and avg case.
    /// for best case TC is O(n).
}

// Merge Sort:
// -> divide and merge.
void merge(int arr[], int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
    // TC -> O(NlogN)
    // SC -> O(N)
}
void Merge_Sort(int arr[], int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    Merge_Sort(arr, low, mid);
    Merge_Sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

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
    // int n;
    // cout << "How many numbers do you want to store in the array: ";
    // cin >> n;
    // int arr[n];
    // for (int i = 0; i < n; i++) {
    //     cin >> arr[i];
    // }
    // cout << "Your array is looks like: ";
    // for (int i = 0; i < n; i++) {
    //     cout << arr[i] << " ";
    // }

    // selection_sort(arr, n);
    // bubble_sort(arr, n);
    // insertion_sort(arr, n);
    // Merge_Sort(arr, 0, n-1);

    // cout << endl << "Now, after Sorting: " << endl;
    // cout << "Your array is looks like: ";
    // for (int i = 0; i < n; i++) {
    //     cout << arr[i] << " ";
    // }

    /// For quick Sort:
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
