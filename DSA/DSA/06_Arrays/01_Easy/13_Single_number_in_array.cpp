// Single Number in an array:

// Link: https://leetcode.com/problems/single-number/description/

/**
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:
Input: nums = [2,2,1]
Output: 1


Example 2:
Input: nums = [4,1,2,1,2]
Output: 4
*/

#include <bits/stdc++.h>
using namespace std;

// Optimal:
// Approach: The approach is pretty much simple. We can do XOR of all the elements as each element present twice in the array except one. So, the elements which are in pair, they will gte cancelled and the one element will remain.
int singleNumber(vector<int> &nums)
{
    int n = nums.size();
    int XORR = 0;
    for (int i = 0; i < n; i++)
    {
        XORR = XORR ^ nums[i];
    }
    return XORR;
}

int main()
{
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << "The array is: ";
    for (auto it : nums)
    {
        cout << it << " ";
    }
    int ans = singleNumber(nums);
    cout << endl
         << "The single number present in the array is: " << ans;
    return 0;
}