//// Check if array is sorted and rotated:

// Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
/**
arr = [1, 2, 3, 4, 5, 6]
after rotating;
arr = [4, 5, 6, 1, 2, 3]
here we can see there is only one time arr[i] > arr[i+1] otherwise in every condition arr[i] < arr[i+1] but to check the first and the last element we have to use the remainder(%) operator.
 
*/
bool checkIsSorted(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n; i ++){
        if (nums[i] > nums[(i + 1) % n]){
            count ++;
        }
        if (count > 1) return false;
    }
    return  true;
}

int main()
{
    vector<int> arr1 = {3, 4, 5, 1, 2};
    vector<int> arr2 = {2, 1, 3, 4};
    
    bool ans1 = checkIsSorted(arr1);
    bool ans2 = checkIsSorted(arr2);

    if (ans1) {
        cout << "The first array is sorted and rotated" << endl;
    } else {
        cout << "The first array is not sorted and rotated" << endl;
    }

    if (ans2) {
        cout << "The second array is sorted and rotated" << endl;
    } else {
        cout << "The second array is not sorted and rotated" << endl;
    }
    return 0;
}