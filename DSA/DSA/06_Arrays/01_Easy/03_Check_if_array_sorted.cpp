// Check if array is sorted:

#include <bits/stdc++.h>
using namespace std;

bool isArraySorted(vector<int> arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        if (arr[i] >= arr[i - 1])
        {
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<int> arr = {1, 2, 3, 7, 5, 6};
    bool ans = isArraySorted(arr);
    if (ans)
    {
        cout << "The array is sorted.";
    }
    else
    {
        cout << "The array is not sorted.";
    }
    return 0;
}