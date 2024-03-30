//// Subarrays with K different integers:
//  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Link: https://leetcode.com/problems/subarrays-with-k-different-integers/description/
/*
Given an integer array nums and an integer k, return the number of good subarrays of nums.
A good array is an array where the number of different integers in that array is exactly k.
For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

Example 1:
Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]

Example 2:
Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].

Constraints:
1 <= nums.length <= 2 * 10^4
1 <= nums[i], k <= nums.length
*/

#include <bits/stdc++.h>
using namespace std;

// Approach 1: TC -> O(n) and SC -> O(n)
// -> The provided Java code implements an approach to find the total count of subarrays having at most k distinct elements within an array of integers. This is achieved using a sliding window technique combined with a HashMap data structure for efficient tracking of distinct elements within the window. The `slidingWindow` method iterates through the array using two pointers, `i` and `j`, to define the current window. It maintains a HashMap (`mp`) to store the frequency of elements within the window. The window expands by incrementing `j` and updates the HashMap accordingly. When the number of distinct elements exceeds `k`, the window shrinks by incrementing `i`, updating the HashMap, and thus ensuring that the window contains at most `k` distinct elements. The `subarraysWithKDistinct` method utilizes the `slidingWindow` method twice. First, it calculates the count of subarrays with at most `k` distinct elements. Then, it calculates the count of subarrays with exactly `k` distinct elements by subtracting the count of subarrays with at most `k-1` distinct elements from the count of subarrays with at most `k` distinct elements.

int slidingWindow(vector<int> &nums, int k)
{
    int n = nums.size();
    int i = 0;
    int j = 0;
    int count = 0;

    unordered_map<int, int> mp;

    while (j < n)
    {
        mp[nums[j]]++;
        while (mp.size() > k)
        {
            mp[nums[i]]--;
            if (mp[nums[i]] == 0)
            {
                mp.erase(nums[i]);
            }
            i++;
        }
        count += (j - i + 1);
        j++;
    }
    return count;
}

int subarraysWithKDistinct(vector<int> &nums, int k)
{
    return slidingWindow(nums, k) - slidingWindow(nums, k - 1);
}

int main()
{
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;
    int ans = subarraysWithKDistinct(nums, k);
    cout << "No of Subarrays with K different integers is: " << ans << endl;
    return 0;
}