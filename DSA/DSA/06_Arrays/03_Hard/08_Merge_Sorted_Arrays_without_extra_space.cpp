/// Merge two sorted arrays without extra space:
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Link: https://leetcode.com/problems/merge-sorted-array/description/
// Link2: https://www.naukri.com/code360/problems/merge-two-sorted-arrays-without-extra-space_6898839

#include <bits/stdc++.h>
using namespace std;

// Brute Force:
// TC -> O(n+m) + O(n+m) and SC -> O(n+m)
void merge_two_sorted_arrays_brute(vector<int> &arr1, vector<int> &arr2, int m, int n)
{
    vector<int> arr3(m + n);
    int left = 0;
    int right = 0;
    int index = 0;

    while (left < m && right < n)
    {
        if (arr1[left] < arr2[right])
        {
            arr3[index] = arr1[left];
            left++;
        }
        else
        {
            arr3[index] = arr2[right];
            right++;
        }
        index++;
    }
    // There can be some cases where some elements will be left in any of the array
    while (left < m)
    {
        arr3[index] = arr1[left];
        left++;
        index++;
    }
    while (right < n)
    {
        arr3[index] = arr2[right];
        right++;
        index++;
    }

    for (int i = 0; i < m + n; i++)
    {
        if (i < m)
            arr1[i] = arr3[i];
        else
            arr2[i - m] = arr3[i];
    }
}

// Optimal 1: (using 2 pointer and sorting)
// Approach: We will set one pointer in the last element of arr1 and another pointer in the beginning of arr2. Now, if the element of arr1 in left pointer is greater than the element of arr2 in right pointer, then we will swap them and if once we get the case that, the element in the left pointer is smaller than the element in the right pointer then we will break out. As, the arrays were previously sorted so, the elements in the left of the element in the left pointer will always be smaller than the element present in the right of the right pointer.
// TC -> O(min(n, m)) + O(nlogn) + O(mlogm) and SC -> O(1)
void merge_two_sorted_arrays_optimal1(vector<int> &arr1, vector<int> &arr2, int m, int n)
{
    int left = m - 1;
    int right = 0;

    while (left >= 0 && right < n)
    {
        if (arr1[left] > arr2[right])
        {
            swap(arr1[left], arr2[right]);
            left--;
            right++;
        }
        else
        {
            break;
        }
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}

/* Optimal 2:
Time Complexity: O((n+m)*log(n+m)), where n and m are the sizes of the given arrays.
Reason: The gap is ranging from n+m to 1 and every time the gap gets divided by 2. So, the time complexity of the outer loop will be O(log(n+m)). Now, for each value of the gap, the inner loop can at most run for (n+m) times. So, the time complexity of the inner loop will be O(n+m). So, the overall time complexity will be O((n+m)*log(n+m)).
Space Complexity: O(1) as we are not using any extra space.
*/
void swapIfGreater(vector<int> &arr1, vector<int> &arr2, int ind1, int ind2)
{
    if (arr1[ind1] > arr2[ind2])
    {
        swap(arr1[ind1], arr2[ind2]);
    }
}

void merge_two_sorted_arrays_optimal2(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    // len of the imaginary single array:
    int len = n + m;

    // Initial gap:
    int gap = (len / 2) + (len % 2);

    while (gap > 0)
    {
        // Place 2 pointers:
        int left = 0;
        int right = left + gap;
        while (right < len)
        {
            // case 1: left in arr1[]
            // and right in arr2[]:
            if (left < n && right >= n)
            {
                swapIfGreater(arr1, arr2, left, right - n);
            }
            // case 2: both pointers in arr2[]:
            else if (left >= n)
            {
                swapIfGreater(arr2, arr2, left - n, right - n);
            }
            // case 3: both pointers in arr1[]:
            else
            {
                swapIfGreater(arr1, arr1, left, right);
            }
            left++, right++;
        }
        // break if iteration gap=1 is completed:
        if (gap == 1)
            break;

        // Otherwise, calculate new gap:
        gap = (gap / 2) + (gap % 2);
    }
}

int main()
{
    vector<int> arr1 = {1, 4, 8, 10};
    vector<int> arr2 = {2, 3, 9};
    int m = 4, n = 3;
    merge_two_sorted_arrays_optimal2(arr1, arr2, m, n);
    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < m; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < n; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}
