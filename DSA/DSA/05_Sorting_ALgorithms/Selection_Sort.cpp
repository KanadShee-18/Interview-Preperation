///////****** Selection Sort ******////////

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

    selection_sort(arr, n);

    cout << endl
         << "Now, after Sorting: " << endl;
    cout << "Your array is looks like: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}