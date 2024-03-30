//// Longest Subarray with sum K (positives + zeroes)

// Link: https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_6682399?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

/*
Problem statement
You are given an array 'a' of size 'n' and an integer 'k'.

Find the length of the longest subarray of 'a' whose sum is equal to 'k'.

Example :
Input: ‘n’ = 7 ‘k’ = 3
‘a’ = [1, 2, 3, 1, 1, 1, 1]

Output: 3

Explanation: Subarrays whose sum = ‘3’ are:

[1, 2], [3], [1, 1, 1] and [1, 1, 1]

Here, the length of the longest subarray is 3, which is our final answer.
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force:
// Approach 1(using 2 loops):- -> generate all subarrays and find out the longest

int longestSubarrayWithSumK(vector<int> &arr, long long k)
{
    int length = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        long long sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == k)
            {
                length = max(length, j - i + 1);
            }
        }
    }
    return length;
    // here, the TC ~ O(n^2) and SC -> O(1)
}

// Better Approach: (using Hashmap)
// Note: This is the better approach for positives and zeroes but if array contains negatives then it is the optimal approach

int longestSubarrayWithSumK_Better(vector<int> &arr, long long k)
{
    map<long long, int> presumMap;
    long long sum = 0;
    int maxLen = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];

        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }

        long long rem = sum - k;
        if (presumMap.find(rem) != presumMap.end())
        { // if the remainder is present in the map
            int len = i - presumMap[rem];
            maxLen = max(maxLen, len);
        }

        // presumMap[sum] = i; // this will not work for 0s and negatives.
        if (presumMap.find(sum) == presumMap.end())
        { // only push the first index of any element.
            presumMap[sum] = i;
        }
    }

    return maxLen;

    // TC ~ O(n * logn) for map & TC ~ O(n * 1) for unordered_map
    // SC ~ O(n)
}

// Optimal Approach: (using 2 Pointer)
// Approach: Take two pointer in the starting index of the array and start traversing with one pointer and calculate the sum. If the sum == k, then calculate the length. And if the sum > k then, start reducing from the front index and move the front pointer.

int longestSubarrayWithSumK_Optimal(vector<int> &arr, int k)
{
    int left = 0;
    int right = 0;
    long long sum = arr[0];
    int maxLen = 0;
    int n = arr.size();

    while (right < n)
    {
        while (sum > k && left <= right)
        {
            sum -= arr[left];
            left++;
        }
        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if (right < n)
        {
            sum += arr[right];
        }
    }
    return maxLen;
}

int main()
{
    vector<int> arr = {1, 2, 3, 1, 1, 1, 1, 3, 3};
    long long k = 6;
    int ans = longestSubarrayWithSumK_Optimal(arr, k);
    cout << "The longest subarray with sum " << k << " is: " << ans;
    return 0;
}