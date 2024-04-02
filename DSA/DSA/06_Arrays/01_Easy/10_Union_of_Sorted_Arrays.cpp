/// Union of two sorted arrays:

/*
Input: ‘n’ = 5 ‘m’ = 3
‘a’ = [1, 2, 3, 4, 6]
‘b’ = [2, 3, 5]

Output: [1, 2, 3, 4, 5, 6]
*/

#include <bits/stdc++.h>
using namespace std;

// Brute: We will use set here as it accepts only unique elements.
vector<int> unionOfSortedArrays(vector<int> &a, vector<int> &b)
{
    int n1 = a.size();
    int n2 = b.size();
    set<int> unionSet;

    // Insert all elements from vector a to set and then from b to set
    for (auto it1 : a)
    {
        unionSet.insert(it1); // TC -> O(n1 logn)   here n-> size of set which will vary in every set
    }
    for (auto it2 : b)
    {
        unionSet.insert(it2); // TC -> O(n2 logn)    here n-> size of set which will vary in every set
    }

    // Now, copy all the items from the set to a temp array
    vector<int> temp;
    for (auto it : unionSet)
    {
        temp.push_back(it); // TC -> O(n1 + n2)
    }

    return temp;

    // So, overall TC-> O(nl logn + n2 logn) + O(n1 + n2)
    // and SC => O(n1 + n2) + O(n1 + n2) <- first one is for set to store all the unique elements and second one is to return the ans from the union array.
}

// Optimal Approach:
// Approach: using 2 Pointer
// -> first we will one pointer i in the first array and j in the second array and then we have to compare them and whichever is smaller we will put that in the array. And before pushing in the array we also have to check the last element of the array as it can be the same element. Let's see the code and this will make it clear.

vector<int> union_of_sorted_array(vector<int> &a, vector<int> &b)
{
    int n1 = a.size();
    int n2 = b.size();
    int i = 0, j = 0;
    vector<int> unionArr;

    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            if (unionArr.size() == 0 || unionArr.back() != a[i])
            { // means if the size of the array is zero or the last element of the array is not similar to the current element then push it
                unionArr.push_back(a[i]);
            }
            i++;
        }
        else
        {
            if (unionArr.size() == 0 || unionArr.back() != b[j])
            {
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }
    // till now, the comparison has been done now we have to push the remaining elements.
    while (j < n2)
    {
        if (unionArr.size() == 0 || unionArr.back() != b[j])
        {
            unionArr.push_back(b[j]);
        }
        j++;
    }
    while (i < n1)
    {
        if (unionArr.size() == 0 || unionArr.back() != a[i])
        {
            unionArr.push_back(a[i]);
        }
        i++;
    }

    return unionArr;

    // here for the TC, we can see that we are traversing each element once in the array. So, the overall TC -> O(n1 + n2) and the extra space required at the worst case is SC -> O(n1 + n2)
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 6};
    vector<int> b = {2, 3, 5};
    cout << "First array: ";
    for (auto it : a)
    {
        cout << it << " ";
    }
    cout << endl
         << "Second array: ";
    for (auto it : b)
    {
        cout << it << " ";
    }
    vector<int> ans = union_of_sorted_array(a, b);
    cout << endl
         << "Now, the union of these two sorted array is: ";
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}