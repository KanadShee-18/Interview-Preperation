/// Linear Search:

// There will be given an array and a number and we have to return the index of that number from the array. If not present then return -1

#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int> &arr, int num)
{
    // Write your code here.
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {15, 47, 21, 36, 0, 1, 41, 21};
    int num = 41;
    int ans = linearSearch(arr, num);
    cout << "The index of " << num << " is: " << ans;
    return 0;
}