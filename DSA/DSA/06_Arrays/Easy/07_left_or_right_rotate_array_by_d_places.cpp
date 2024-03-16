//// Left or right rotate array by d or k places:

// Link: https://leetcode.com/problems/rotate-array/description/

/*
Example: right rotate
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2: left rotate
'arr '= [1,2,3,4,5]
'k' = 1  rotated array = [2,3,4,5,1]
'k' = 2  rotated array = [3,4,5,1,2]
'k' = 3  rotated array = [4,5,1,2,3] and so on.
*/

// Here two solution we have. Brute and optimal. The brute is quite similar as the previous problem
// Here we will do left rotate array by d the places and the right rotate will be very similar.

// Brute:
// Approach: First we will take d/k elements in a temp array. Then we will move the rest of the elements of the array. And then we will place again the elements of temp array into the original array.

#include <bits/stdc++.h>
using namespace std;

vector<int> leftRotate (vector<int> &arr, int d) {
    int n = arr.size();

    // first take a temp array of d size to store d items in it.
    vector<int> temp(d);
    for (int i = 0; i < d; i ++){
        temp[i] = arr[i];  // TC -> O(d)
    }

    // Now, shift the remaining elements in front of the array.
    for (int i = d; i < n; i ++){
        arr[i-d] = arr[i];   // TC -> O(n-d)
    }

    // Now, push back the elements of the temp array into the original array.
    for (int i = n-d; i < n; i ++){
        arr[i] = temp[i - (n-d)];  // TC -> O(d)
    }

    return arr;

    // Overall TC -> O(n+d) and extra space needed SC => O(d)
} 


//// Now, here is a optimal approach which has come out just by observation and replacing items of the array inside it.

// Optimal:
vector<int> rotateArr (vector<int> &arr, int k) {
    int n = arr.size();
    k = k % n;
    reverse (arr.begin(), arr.begin() + k);   // TC -> O(d)
    reverse (arr.begin() + k, arr.end());    // TC -> O(n-d)
    reverse (arr.begin(), arr.end());     // TC -> O(n)

    return arr;

    // So, overall TC -> O(2n) and here no extra space is needed so, SC -> O(1), but the TC has slightly increased.
}


int main() {
    vector <int> arr = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    cout << "The original array looks like: ";
    for (auto it: arr) {
        cout << it << " ";
    }
    // vector<int> newArr = leftRotate (arr, k);
    vector<int> newArr2 = rotateArr (arr, k);
    cout << endl << "After left rotating array by " << k << "th places the array looks like: ";
    for (auto it: newArr2){
        cout << it << " ";
    }
    return 0;
}