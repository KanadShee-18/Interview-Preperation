//// Check if array is sorted and rotated:

// Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
bool checkIsSorted(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] > nums[i])
        {
            count++;
        }
    }
    if (nums[0] < nums[n - 1])
    {
        count++;
    }
    return (count <= 1);
}

int main()
{
    vector<int> arr1 = {3, 4, 5, 1, 2};
    vector<int> arr2 = {2, 1, 3, 4};
    
    bool ans1 = checkIsSorted(arr1);
    bool ans2 = checkIsSorted(arr2);

    if (ans1) {
        cout << "The first array is sorted and rotated" << endl;
    } else {
        cout << "The first array is not sorted and rotated" << endl;
    }

    if (ans2) {
        cout << "The second array is sorted and rotated" << endl;
    } else {
        cout << "The second array is not sorted and rotated" << endl;
    }
    return 0;
}