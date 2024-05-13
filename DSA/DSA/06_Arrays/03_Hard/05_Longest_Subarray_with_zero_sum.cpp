//// Longest Subarray with 0 Sum:
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Link: https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

#include <bits/stdc++.h>
using namespace std;

// Brute Force: (generate all subarrays)
// TC -> O(N^2) and SC -> O(1)
int solve(vector<int> &a)
{
    int maxLen = 0;
    unordered_map<int, int> sumIndexMap;
    int sum = 0;

    for (int i = 0; i < a.size(); i++)
    {
        sum += a[i];

        if (sum == 0)
        {
            maxLen = i + 1;
        }
        else if (sumIndexMap.find(sum) != sumIndexMap.end())
        {
            maxLen = max(maxLen, i - sumIndexMap[sum]);
        }
        else
        {
            sumIndexMap[sum] = i;
        }
    }

    return maxLen;
}

// Optimal Approach: (using Hashmap)
// TC -> O(NlogN) and SC-> O(N)

int maxSubarrayLengthWithZeroSum(vector<int> &nums)
{
    int n = nums.size();
    int maxi = 0;
    int sum = 0;
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        if (sum == 0)
        {
            maxi = i + 1;
        }
        else
        {
            if (mpp.find(sum) != mpp.end())
            {
                maxi = max(maxi, i - mpp[sum]);
            }
            else
            {
                mpp[sum] = i;
            }
        }
    }
    return maxi;
}

int main()
{
    vector<int> arr = {1, -1, 3, 2, -2, -8, 1, 7, 10, 23};
    int ans = maxSubarrayLengthWithZeroSum(arr);
    cout << "The length of maximum subarray with sum 0 is: " << ans << endl;
    return 0;
}