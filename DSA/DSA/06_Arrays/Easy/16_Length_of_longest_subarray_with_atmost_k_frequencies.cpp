//// Length of longest subarray with at most k frequencies:
//// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/*
Link: https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description

You are given an integer array nums and an integer k.
The frequency of an element x is the number of times it occurs in an array.
An array is called good if the frequency of each element in this array is less than or equal to k.
Return the length of the longest good subarray of nums.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,2,3,1,2,3,1,2], k = 2
Output: 6
Explanation: The longest possible good subarray is [1,2,3,1,2,3] since the values 1, 2, and 3 occur at most twice in this subarray. Note that the subarrays [2,3,1,2,3,1] and [3,1,2,3,1,2] are also good.
It can be shown that there are no good subarrays with length more than 6.

Example 2:
Input: nums = [1,2,1,2,1,2,1,2], k = 1
Output: 2
Explanation: The longest possible good subarray is [1,2] since the values 1 and 2 occur at most once in this subarray. Note that the subarray [2,1] is also good.
It can be shown that there are no good subarrays with length more than 2.
*/

#include <bits/stdc++.h>
using namespace std;

// 2 Approach: both are using sliding window but in the 1st approach we are going to use nested while loop and another one using a single while loop

// Approach 1:
// This approach utilizes the classic sliding window technique to find the maximum length of a subarray where the number of distinct integers is at most `k`. The algorithm maintains a sliding window represented by two pointers `i` and `j`, where `i` marks the start of the window and `j` marks the end. It uses a hashmap (`unordered_map` in C++) to store the frequency of each integer within the window. The algorithm iterates through the array, expanding the window (`j`) and contracting it (`i`) as necessary to ensure that the number of distinct integers remains at most `k`. The time complexity of this approach is O(n) since it iterates through the array once, and the space complexity is O(n) due to the hashmap storing the frequency of integers.

// TC ~ O(n) & SC ~ O(1)
int maxSubarrayLength(vector<int> &nums, int k)
{
    int n = nums.size();
    int i = 0;
    int j = 0;
    int result = 0;

    unordered_map<int, int> mpp;

    while (j < n)
    {
        mpp[nums[j]]++;
        while (mpp[nums[j]] > k && i <= j)
        {
            mpp[nums[i]]--;
            i++;
        }
        result = max(result, j - i + 1);

        j++;
    }
    return result;
}

// Approach 2:
// This approach also finds the maximum length of a subarray where the number of occurrences of a particular integer is at most `k`. However, it achieves this without using nested loops. Instead, it maintains a sliding window represented by two pointers `i` and `j`, similar to Approach-1. Additionally, it uses a hashmap (`unordered_map` in C++) to store the frequency of each integer within the window. However, it introduces an additional variable `culprit` to keep track of the number of integers that have exceeded the limit `k` within the window. The algorithm iterates through the array, expanding the window (`j`) and contracting it (`i`) as necessary. If an integer within the window exceeds the limit `k`, it increments `culprit` and adjusts the window accordingly. This approach also has a time complexity of O(n) and a space complexity of O(n).

// TC ~ O(n) & SC ~ O(n)
int maxSubarrayLength_without_nested_loop(vector<int> &nums, int k)
{
    // without nested loop

    int n = nums.size();
    int i = 0;
    int j = 0;
    int result = 0;
    int culprit = 0;

    unordered_map<int, int> mp;

    while (j < n)
    {
        mp[nums[j]]++;
        if (mp[nums[j]] == k + 1)
        {
            culprit++;
        }

        if (culprit > 0)
        {
            mp[nums[i]]--;
            if (mp[nums[i]] == k)
            {
                culprit--;
            }
            i++;
        }

        if (culprit == 0)
        {
            result = max(result, j - i + 1);
        }
        j++;
    }
    return result;
}

int main()
{
    vector<int> nums = {1, 2, 3, 1, 2, 3, 1, 2};
    int k = 2;
    int ans = maxSubarrayLength_without_nested_loop(nums, k);
    cout << "Length of longest subarray with at most " << k << " frequencies is: " << ans;
    return 0;
}