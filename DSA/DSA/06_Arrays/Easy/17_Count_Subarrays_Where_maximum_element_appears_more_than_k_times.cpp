//// Count subarrays where maximum element appears more than k times:
/*
Link: https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/

You are given an integer array nums and a positive integer k.
Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.
A subarray is a contiguous sequence of elements within an array.

Example 1:
Input: nums = [1,3,2,3,3], k = 2
Output: 6
Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].

Example 2:
Input: nums = [1,4,2,1], k = 3
Output: 0
Explanation: No subarray contains the element 4 at least 3 times.

Constraints:
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^6
1 <= k <= 10^5
*/

#include <bits/stdc++.h>
using namespace std;

// Approach 1: (using 2 pointer)
// This approach utilizes the sliding window technique to solve the problem efficiently. It begins by identifying the maximum element in the array. Then, it iterates through the array using two pointers, `i` and `j`, to define the sliding window. The `j` pointer moves forward, while the `i` pointer adjusts when necessary to maintain the condition of having at most `k` occurrences of the maximum element within the window. The number of subarrays satisfying the condition is accumulated in the `result` variable. The time complexity of this approach is O(n), where n is the size of the input array, and the space complexity is O(1) since only a fixed number of variables are used irrespective of the input size.

long long countSubarrays(vector<int> &nums, int k)
{
    int maxElement = *max_element(begin(nums), end(nums));

    int i = 0;
    int j = 0;
    int n = nums.size();

    long long result = 0;
    int countMax = 0;

    while (j < n)
    {
        if (nums[j] == maxElement)
        {
            countMax++;
        }

        while (countMax >= k)
        {
            result += (n - j);
            if (nums[i] == maxElement)
            {
                countMax--;
            }
            i++;
        }
        j++;
    }
    return result;

    // TC -> O(n) and SC -> O(1)
}

// Approach 2: (without using sliding window)
// In this approach, the sliding window technique is not employed. Instead, it relies on a vector (`maxIndices`) to keep track of the indices where the maximum element occurs. It iterates through the array once, storing the indices of occurrences of the maximum element. Then, it checks for the condition of having at least `k` occurrences of the maximum element. For each occurrence after the `k`th, it calculates the number of subarrays that satisfy the condition and accumulates the result. The time complexity remains O(n) since it iterates through the array once, but the space complexity increases to O(n) due to the vector used to store indices.

long long countSubarrays_without_2_pointer(vector<int> &nums, int k)
{
    int maxElement = *max_element(begin(nums), end(nums));

    int i = 0;
    int n = nums.size();
    long long result = 0;

    vector<int> maxEl_idx;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == maxElement)
        {
            maxEl_idx.push_back(i);
        }

        int size = maxEl_idx.size();

        if (size >= k)
        {
            int lastIndexOfMaxElement = maxEl_idx[size - k];
            result += lastIndexOfMaxElement + 1;
        }
    }
    return result;
    // TC -> O(n) as we are treaversing once throughout the whole array and SC -> O(n) as we are storing the indexes in the maxEl_idx vector.
}

int main()
{
    vector<int> nums = {1, 3, 2, 3, 3};
    int k = 2;
    long long ans = countSubarrays_without_2_pointer(nums, k);
    cout << "The number of subarrays where maximum element appears more than " << k << " times is: " << ans;
    return 0;
}