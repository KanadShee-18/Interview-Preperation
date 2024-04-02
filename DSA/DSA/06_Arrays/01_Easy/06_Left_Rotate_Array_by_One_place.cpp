/// Left rotate array by one place:

// Link: https://www.codingninjas.com/studio/problems/left-rotate-an-array-by-one_5026278?

#include <bits/stdc++.h>
using namespace std;

// Approach:
/*
1. Take the first element in a temp variable
2. Move the other elements to te left by one place (arr[i-1] = arr[i])
3. Again place the temp element as the last element of array
*/
vector<int> leftRotateArrayByOnePlace(vector<int> &arr)
{
    int n = arr.size();
    int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
    return arr;
}

int main()
{
    vector<int> arr = {1, 20, 41, 87, 41, 31};
    cout << "Before left rotating array by one place the array is: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    leftRotateArrayByOnePlace(arr);
    cout << endl
         << "After left rotating array by one place the array is looking like: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}