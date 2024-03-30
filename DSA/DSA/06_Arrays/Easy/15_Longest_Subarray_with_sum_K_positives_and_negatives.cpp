// Longest Subarray with sum K (positives + negatives):

// Link: https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_5713505?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

/*
Problem statement
Ninja and his friend are playing a game of subarrays. They have an array ‘NUMS’ of length ‘N’. Ninja’s friend gives him an arbitrary integer ‘K’ and asks him to find the length of the longest subarray in which the sum of elements is equal to ‘K’.

Ninjas asks for your help to win this game. Find the length of the longest subarray in which the sum of elements is equal to ‘K’.

If there is no subarray whose sum is ‘K’ then you should return 0.

Example:
Input: ‘N’ = 5,  ‘K’ = 4, ‘NUMS’ = [ 1, 2, 1, 0, 1 ]

Output: 4

There are two subarrays with sum = 4, [1, 2, 1] and [2, 1, 0, 1]. Hence the length of the longest subarray with sum = 4 is 4.
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

// Better and Optimal Approach: (using Hashmap)
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
    // SC -> O(n)
}

int main()
{
    vector<int> arr = {1, 2, 3, 1, 1, 1, 1, 3, 3};
    long long k = 6;
    int ans = longestSubarrayWithSumK_Better(arr, k);
    cout << "The longest subarray with sum " << k << " is: " << ans;
    return 0;
}
