/// Maximum Consecutie 1's:

// Link: https://leetcode.com/problems/max-consecutive-ones/

/*
Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
*/

// Here, the solution is pretty much straight forward. SO, we will jump directly to optimal approach.

#include <bits/stdc++.h>
using namespace std;

int max_consecutive_ones(vector<int> &nums)
{
    int n = nums.size();
    int maxi = 0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
        {
            count++;
            maxi = max(maxi, count);
        }
        // if ina ny time, it does not found 1, then the count will again set to 0
        else
        {
            count = 0;
        }
    }
    return maxi;

    // here, we are traversing the array by once, so the TC of the array will be TC -> O(n)
}

int main()
{
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    cout << "The array is: ";
    for (auto it : nums)
    {
        cout << it << " ";
    }

    int ans = max_consecutive_ones(nums);
    cout << endl
         << "The maximum consecutive ones in the array is: " << ans;

    return 0;
}
