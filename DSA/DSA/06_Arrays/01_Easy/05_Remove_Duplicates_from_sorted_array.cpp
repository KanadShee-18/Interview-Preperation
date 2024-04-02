/// Remove Duplciates from a sorted array:

#include <bits/stdc++.h>
using namespace std;

// Brute: (using Set) (Set insert unique elements in assending order)
/*
Create a set st to store unique elements.
Iterate through the input vector arr.
For each element arr[i], attempt to insert it into st.
If insertion is successful (unique element):
Copy the element from st to arr[j] (modified vector).
Increment j to point to the next position.
Return the value of j, which is the new effective size (unique elements count).
*/
// TC : O(nlogn + n) SC -> O(n)

int removeDuplicates(vector<int> arr)
{
    set<int> st;
    for (int i = 0; i < arr.size(); i++)
    {
        st.insert(arr[i]);
    }
    int index = 0;
    for (auto it : st)
    {
        arr[index] = it;
        index++;
    }
    return index;
}

// Optimal Approach:
// TC -> O(n) and SC -> O(1)

int removeDuplicatesFromSortedArray(vector<int> arr)
{
    int n = arr.size();
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (arr[j] != arr[i])
        {
            arr[i + 1] = arr[j];
            i++;
        }
    }
    return (i + 1);
}

int main()
{
    vector<int> arr = {1, 1, 2, 2, 2, 3, 3};
    // int idx = removeDuplicates (arr);
    int idx1 = removeDuplicatesFromSortedArray(arr);
    cout << "After removing duplciates the number of elements in the array is: " << idx1 << endl;
    return 0;
}