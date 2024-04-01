/// Missing number in an array:

// Link: https://leetcode.com/problems/missing-number/description/

/**
 * Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Example 1:

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
*/

#include <bits/stdc++.h>
using namespace std;

// Brute:
// Approach: We can use loops from 0 to the size of the arr and can search which index is missing and that will be our answer.
int missingNumberBrute(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i <= n; i++)
    {
        int flag = 0;
        for (int j = 0; j < n; j++)
        { // we know one number is missing so j < n-1
            if (nums[j] == i)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        { // if still flag is 0 then that number will be the missing number.
            return i;
        }
    }
    return -1;
    // So, TC in worst case, TC -> O(n * n) and SC -> O(1)
}

// Better approach: Using the hashmap
// Approach: we first make hasharr of size of the original array and will fill with 0. After that we will traverse through the arr and mark that element as 1 in the hashArr. Now, we will traverse in the hashArr and will see which index is not 1 and that will be our answer.

int missingNumberBetter(vector<int> &nums)
{
    int n = nums.size();
    int hashArr[n + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        hashArr[nums[i]]++;
    }

    for (int i = 0; i <= n; i++)
    {
        if (hashArr[i] == 0)
        {
            return i;
        }
    }
    return -1;
}

// Optimal Approach: There are two optimal approach:
// Approach 1: Using some mathematics

int missing_number_optimal1(vector<int> &nums)
{
    int n = nums.size();
    int sum = (n * (n + 1)) / 2;
    int sum2 = 0;
    for (auto it : nums)
    {
        sum2 += it;
    }
    return sum - sum2;
    // Here, TC -> O(1) and SC -> O(1)
}

int missing_number_optimal2(vector<int> &nums)
{
    int n = nums.size();
    int XOR1 = 0;
    int XOR2 = 0;
    for (int i = 0; i < n; i++)
    {
        XOR1 = XOR1 ^ i;
        XOR2 = XOR2 ^ nums[i];
    }

    XOR1 = XOR1 ^ n;
    return XOR1 ^ XOR2;
    // Here also, TC -> O(n) and SC -> O(1)
}

int main()
{
    vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    // int n = 10;
    cout << "The array is: ";
    for (auto it : nums)
    {
        cout << it << " ";
    }
    int ans = missing_number_optimal2(nums);
    cout << endl
         << "The missing number in the array is: " << ans << endl;
    return 0;
}