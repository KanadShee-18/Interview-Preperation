///// Reverse Pairs: (hard interview problem)
//// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Link: https://leetcode.com/problems/reverse-pairs/description/
/*
Given an integer array nums, return the number of reverse pairs in the array.
A reverse pair is a pair (i, j) where:
0 <= i < j < nums.length and
nums[i] > 2 * nums[j].

Example 1:
Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1

Example 2:
Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1
*/

#include <bits/stdc++.h>
using namespace std;

/* Brute Force Approach: (using simple loops)
Time Complexity: O(N2), where N = size of the given array.
Reason: We are using nested loops here and those two loops roughly run for N times.
Space Complexity: O(1) as we are not using any extra space to solve this problem.
*/
int countPairs_brute(vector<int> &a, int n)
{

    // Count the number of pairs:
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > 2 * a[j])
                cnt++;
        }
    }
    return cnt;
}
int reversePairs_brute(vector<int> &nums, int n)
{
    return countPairs_brute(nums, n);
}

/* Optimal Approach: (using divide and conquer)
Time Complexity: O(2N*logN), where N = size of the given array.
Reason: Inside the mergeSort() we call merge() and countPairs() except mergeSort() itself. Now, inside the function countPairs(), though we are running a nested loop, we are actually iterating the left half once and the right half once in total. That is why, the time complexity is O(N). And the merge() function also takes O(N). The mergeSort() takes O(logN) time complexity. Therefore, the overall time complexity will be O(logN * (N+N)) = O(2N*logN).
Space Complexity: O(N), as in the merge sort We use a temporary array to store elements in sorted order.
*/
void merge(vector<int> &nums, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (nums[left] <= nums[right])
        {
            temp.push_back(nums[left]);
            left++;
        }
        else
        {
            temp.push_back(nums[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(nums[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(nums[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        nums[i] = temp[i - low];
    }
}

int countPairs(vector<int> &nums, int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;
    int count = 0;
    for (int i = left; i <= mid; i++)
    {
        while (right <= high && nums[i] > 2 * nums[right])
        {
            right++;
        }
        count += (right - (mid + 1));
    }
    return count;
}

int mergeSort(vector<int> &nums, int low, int high)
{
    int count = 0;
    if (low >= high)
    {
        return count;
    }
    int mid = low + (high - low) / 2;
    count += mergeSort(nums, low, mid);
    count += mergeSort(nums, mid + 1, high);
    count += countPairs(nums, low, mid, high);
    merge(nums, low, mid, high);
    return count;
}

int reversePairs_optimal(vector<int> &nums, int n)
{
    return mergeSort(nums, 0, n - 1);
}

int main()
{
    vector<int> nums = {4, 1, 2, 3, 1};
    int n = nums.size();
    cout << "The array is: ";
    for (auto it : nums)
    {
        cout << it << ", ";
    }
    cout << endl;
    int ans = reversePairs_brute(nums, n);
    cout << "The no of reverse pairs possible from the array is: " << ans << endl;
    return 0;
}