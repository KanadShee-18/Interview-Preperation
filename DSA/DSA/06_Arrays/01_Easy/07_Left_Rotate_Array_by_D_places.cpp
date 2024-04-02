/// Left rotate array by kth or dth places:
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Link: https://leetcode.com/problems/rotate-array/description/

/**
Example: Left Rotate
'arr '= [1,2,3,4,5]
'k' = 1  rotated array = [2,3,4,5,1]
'k' = 2  rotated array = [3,4,5,1,2]
'k' = 3  rotated array = [4,5,1,2,3] and so on.

Example: Right rotate
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
*/

#include <bits/stdc++.h>
using namespace std;

/// Brute Force Approach:
// Steps:
/*
1. Take d elements in the temp   TC -> O(d)
2. Shift the rest of the elements   TC -> O(n-d)
3. Now push back element from temp to array.    TC -> O(d)
~~~~~~~~~ TC -> O(n+d) and the extra space required SC -> O(d)
*/

vector<int> leftRotateByDPlaces(vector<int> &arr, int d)
{
    int n = arr.size();

    // first take a temp arr and store the d elements
    vector<int> temp(d);
    for (int i = 0; i < d; i++)
    {
        temp[i] = arr[i];
    }

    // now shift rest of the elements to the beginning of the array
    // 3 -> 0;   4 -> 1;     5 -> 2;      6 -> 3    means
    // d -> 0;   d+1 -> 1;   d+2 -> 2;    d+3 -> 3
    for (int i = d; i < n; i++)
    {
        arr[i - d] = arr[i];
    }

    // Now push back d elements back to array from temp
    // 4th index <- 0th value     5th index <- 1th value     6th index <- 2nd value
    // (n-d) <- 0th                (n-d+1) <- 1th             (n-d+2) <- 2nd
    for (int i = n - d; i < n; i++)
    {
        arr[i] = temp[i - (n - d)];
    }

    return arr;
}

//// Optimal Approach:
// Steps:
/*
1. Reverse first d elements    TC -> O(d)
2. Reverse the rest elements   TC -> O(n-d)
3. Now reverse the whole array TC -> O(n)
~~~~~~~~~ TC -> O(2n) and There is no extra space required so SC -> O(1)
*/
void left_rotate_by_D_places(vector<int> &arr, int d)
{
    int n = arr.size();
    reverse(arr.begin(), arr.begin() + d);
    reverse(arr.begin() + d, arr.end());
    reverse(arr.begin(), arr.end());
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int d = 3;
    cout << "Before rotating the array is looking like: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    // vector <int> ans = leftRotateByDPlaces(arr, d);
    left_rotate_by_D_places(arr, d);

    cout << endl
         << "After rotating the array is looking like: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}