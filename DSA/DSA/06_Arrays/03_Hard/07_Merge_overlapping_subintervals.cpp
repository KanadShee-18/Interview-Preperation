/// Merge Overlapping Subintervals:
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Link: https://leetcode.com/problems/merge-intervals/description/

/*
Naive Approach (Brute-force):
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

First, we will group the closer intervals by sorting the given array of intervals(if it is not already sorted).
After that, we will select one interval at a time using a loop(say i) and insert it into our answer list(if the answer list is empty or the current interval cannot be merged with the last interval of the answer list). While traversing and inserting we will skip the intervals that lie in the last inserted interval of our answer list.
Now, for each interval arr[i], using another loop (say j) we are going to check the rest of the intervals(i.e. From index i+1 to n-1) if they can be merged with the selected interval.
Inside loop j, we will continue to merge all the intervals that lie in the selected interval.
How to check if the current interval can be merged with the selected interval:
We will compare the current interval’s start with the end of the selected interval. If the start is smaller or equal to the end, we can conclude the current interval can be a part of the selected interval. So, we will update the selected interval’s end with the maximum(current interval’s end, selected interval’s end) in the answer list(not in the original array).
We will break out of loop j, from the first element that cannot be a part of the selected interval.
How to check if the current interval is not a part of the selected interval:
We will compare the current interval’s start with the end of the selected interval. If the start is greater than the end, we can conclude the current interval cannot be a part of the selected interval.
Finally, we will return the answer list.
*/

/*
Optimal Approach:
~~~~~~~~~~~~~~~~~

First, we will group the closer intervals by sorting the given array of intervals(if it is not already sorted).
After that, we will start traversing the array using a loop(say i) and insert the first element into our answer list(as the answer list is empty).
Now, while traversing we will face two different cases:
Case 1: If the current interval can be merged with the last inserted interval of the answer list:
In this case, we will update the end of the last inserted interval with the maximum(current interval’s end, last inserted interval’s end) and continue moving afterward.
Case 2: If the current interval cannot be merged with the last inserted interval of the answer list:
In this case, we will insert the current interval in the answer array as it is. And after this insertion, the last inserted interval of the answer list will obviously be updated to the current interval.
Thus the answer list will be updated with the merged intervals and finally, we will return the answer list.
Intuition: Since we have sorted the intervals, the intervals which will be merging are bound to be adjacent. We kept on merging simultaneously as we were traversing through the array and when the element was non-overlapping we simply inserted the element in our answer list.
*/

#include <bits/stdc++.h>
using namespace std;

/* Brute:
~~~~~~~~~~
Time Complexity: O(N*logN) + O(2*N), where N = the size of the given array.
Reason: Sorting the given array takes  O(N*logN) time complexity. Now, after that, we are using 2 loops i and j. But while using loop i, we skip all the intervals that are merged with loop j. So, we can conclude that every interval is roughly visited twice(roughly, once for checking or skipping and once for merging). So, the time complexity will be 2*N instead of N2.
Space Complexity: O(N), as we are using an answer list to store the merged intervals. Except for the answer array, we are not using any extra space.
*/
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        int start = intervals[i][0];
        int end = intervals[i][1];

        if (!ans.empty() && end <= ans.back()[1])
            continue;

        for (int j = i + 1; j < n; j++)
        {
            if (intervals[j][0] <= end)
            {
                end = max(end, intervals[j][1]);
            }
            else
            {
                break;
            }
        }

        ans.push_back({start, end});
    }

    return ans;
}

/* Optimal:
~~~~~~~~~~~~
Time Complexity: O(N*logN) + O(N), where N = the size of the given array.
Reason: Sorting the given array takes  O(N*logN) time complexity. Now, after that, we are just using a single loop that runs for N times. So, the time complexity will be O(N).
Space Complexity: O(N), as we are using an answer list to store the merged intervals. Except for the answer array, we are not using any extra space.
*/
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        if (ans.empty() || intervals[i][0] > ans.back()[1])
        {
            ans.push_back(intervals[i]);
        }
        else
        {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = mergeOverlappingIntervals(arr);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans)
    {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}