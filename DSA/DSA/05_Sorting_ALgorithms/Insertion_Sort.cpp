///////****** Insertion Sort ******////////

#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    int n;
    cout << "How many numbers do you want to store in the array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Your array is looks like: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    insertion_sort(arr, n);

    cout << "\nNow, after Sorting: " << endl;
    cout << "Your array is looks like: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}