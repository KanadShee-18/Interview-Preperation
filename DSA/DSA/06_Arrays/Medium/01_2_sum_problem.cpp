//// 2 Sum Problem:

// Link: https://leetcode.com/problems/two-sum/description/

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
*/

#include <bits/stdc++.h>
using namespace std;

// There are two variety in the question:
// 1. -> Return true or false that two numbers are present in the array or not
// 2. -> Return the index of two numbers.

// Brute Force:
// Approach: Pick one element from the array and sum up with others that is giving our target or not.
bool Two_Sum_Brute(vector<int> &arr, int target)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                return true;
            }
        }
    }
    return false;

    // TC ~ O(n^2)
}

// Better Approach: (using Hashmap)
// Approach: First we will go to each element of the array and will search for the reamining terms. If found then ok, else put that element in the map.
vector<int> twoSum(vector<int> &nums, int target)
{
    map<int, int> mpp;
    for (int i = 0; i < nums.size(); i++)
    {
        int a = nums[i];
        int moreRequired = target - a;
        if (mpp.find(moreRequired) != mpp.end())
        {
            return {mpp[moreRequired], i}; // return true;
        }
        mpp[a] = i;
    }
    return {-1, -1}; // return false;

    // TC ~ O(n * log n) and SC -> O(n)
}

// Optimal Approach: Remember this is the optimal approach for variety 1 not for 2.
// (using 2 Pointer approach):
/*
1. Sort the array
2. Take two pointer in the starting index and the last index.
3. Take the sum of arr[left] + arr[right]
4. If (sum == target) return true; if sum < target, then left ++; else right -- as the array is sorted.
*/

bool two_Sum(vector<int> &arr, int target)
{
    int left = 0, right = arr.size() - 1;
    sort(arr.begin(), arr.end());
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == target)
            return true;
        else if (sum < target)
            left++;
        else
            right--;
    }
    return false;
}

int main()
{
    vector<int> nums = {2, 7, 15, 11};
    int target = 9;
    bool ans = two_Sum(nums, target);
    if (ans)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}