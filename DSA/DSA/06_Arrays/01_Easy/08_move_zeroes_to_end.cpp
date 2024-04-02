//// Move zeroes in the end of the array:

// Link: https://leetcode.com/problems/move-zeroes/description/

#include <bits/stdc++.h>
using namespace std;

// Brute Force:
// Approach: First we will take all the non-zero elements from the array and will store them in an temp array and then we can get the number of zeroes by eliminating the temp array size from the main array.

vector<int> moveZeroesToEnd(vector<int> &arr)
{
    int n = arr.size();
    // Step 1: Add all non zero items in temp array
    vector<int> temp;
    for (auto it : arr)
    {
        if (it != 0)
        {
            temp.push_back(it);
        }
    } // TC -> O(n)

    // Step 2: Now push all the non zero items from the temp array from the original array
    for (int i = 0; i < temp.size(); i++)
    {
        arr[i] = temp[i];
    } // TC -> O(x)  where x = non zero elements

    // Step 3: Now, fill with zero
    int nonZero_elements = temp.size();
    for (int i = nonZero_elements; i < n; i++)
    {
        arr[i] = 0;
    } // TC -> O(n-x)

    return arr;
    // So, overall TC -> O(2n) and the extra space required is SC -> O(x)  where, x -> no of non zero elements.
}

// Optimal Approach: 2 pointer: It is similar as the remove duplicates from a array
// Approach: First traverse the array and find the first 0 and make a pointer j to it, Then take one more pointer i and point it to the next element of j and start traversing the array and replace non-zero and zero th terms.

void move_zeroes_to_end(vector<int> &arr)
{
    int n = arr.size();
    // Step 1: Find the first 0.
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            j = i; // here taking the first 0's position and //TC -> O(x) where x is the first index till which we hava to go to find the first 0.
            break;
        }
    }
    // if still j = -1, means there is no 0 then return the original array
    if (j == -1)
        return;
    // Step 2: take one more pointer i and replace non-zero terms and zero.
    for (int i = j + 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[j], arr[i]);
            j++;
        } // TC -> O(n-x)
    }
    // Overall TC -> O(n) and SC -> O(1) as we are not using any extra space.
}

int main()
{
    vector<int> arr = {1, 2, 0, 3, 5, 0, 4, 6, 0, 4, 7, 0, 5, 0, 0, 4, 0, 7};
    cout << "The original array is looking like: ";
    for (auto &it : arr)
    {
        cout << it << " ";
    }
    move_zeroes_to_end(arr);
    cout << endl
         << "Now, the array is looking like: ";
    for (auto &it : arr)
    {
        cout << it << " ";
    }
    return 0;
}