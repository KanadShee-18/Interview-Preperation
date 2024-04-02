///// Second Largest and Second Smallest element in an Array:

// Link: https://www.codingninjas.com/studio/problems/ninja-and-the-second-order-elements_6581960

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach:

/*
1. Sort
2. Find the largest
3. Traverse from end and find which element is different from largest that will definitely be the second Largest and break
*/

// TC -> O(nlogn + n)  <- (sorting + traversing)

// CODE:

// vector<int> secondLargest_secondSmallest(vector<int> arr, int n){
//     sort (arr.begin(), arr.end());
//     int largest = arr[n-1];
//     int sLargest = -1;
//     for (int i = n-2; i >=0; i --){
//         if (arr[i] != largest){
//             sLargest = arr[i];
//             break;
//         }
//     }

//     int smallest = arr[0];
//     int sSmallest = INT_MAX;
//     for (int i = 1; i < n; i ++){
//         if (arr[i] != smallest){
//             sSmallest = arr[i];
//             break;
//         }
//     }
//     return {sLargest, sSmallest};
// }

// Better Approach:

/*
1. Find the largest
2. take secondLargest as -1 and traverse the array and find which element is greater than secondLargest and not equal to largest
*/

// For 2 Parse O(n+n) -> O(2n)

// CODE:

// int secSmallest (vector<int> &arr, int n){
//     int smallest = INT_MAX;
//     int ssmallest = INT_MAX;
//     for (auto it: arr){
//         if (it < smallest) {
//             smallest = it;
//         }
//     }
//     for (auto it: arr){
//         if (it < ssmallest && it != smallest){
//             ssmallest = it;
//         }
//     }
//     return ssmallest;
// }

// int secLargest (vector<int> &arr, int n){
//     int largest = INT_MIN;
//     int sLargest = -1;
//     for (auto it: arr){
//         if (it > largest) {
//             largest = it;
//         }
//     }
//     for (auto it: arr){
//         if (it > sLargest && it != largest){
//             sLargest = it;
//         }
//     }
//     return sLargest;
// }
// vector<int> secondLargestSmallest (vector<int> arr, int n){
//     int sLargest = secLargest(arr, n);
//     int sSmallest = secSmallest(arr, n);
//     return {sLargest, sSmallest};
// }

// Optimal Approach:

/*
1. Take arr[0] = largest and sLargest = -1;
2. Traverse the array and check. If element is greater than largest then the sLargest will be largest and largest will be that element.
3. One case we also have to check, if element is less than largest but greater than secondLargest
*/

// As it's just taking 1 pass so TC is O(n)

// CODE:

int secondSmallestElement(vector<int> &arr, int n)
{
    int smallest = arr[0];
    int secondSmallest = INT_MAX;

    for (auto &it : arr)
    {
        // if element is smaller than smallest then (sLargest = largest) and (largest = element)
        if (it < smallest)
        {
            secondSmallest = smallest;
            smallest = it;
        }
        // there can be some elements which will be greater than smallest but less than sSmallest
        else if (it > smallest && it < secondSmallest)
        {
            secondSmallest = it;
        }
    }
    return secondSmallest;
}

int secondLargestElement(vector<int> &arr, int n)
{
    int largest = arr[0];
    int secondLargest = -1;

    for (auto &it : arr)
    {
        // if element is greater than largest then (sLargest = largest) and (largest = element)
        if (it > largest)
        {
            secondLargest = largest;
            largest = it;
        }
        // there can be some elements which will be lesser than largest but greater than sLargest
        else if (it < largest && it > secondLargest)
        {
            secondLargest = it;
        }
    }
    return secondLargest;
}

vector<int> getSecondOrderElements(vector<int> arr, int n)
{
    int sLargest = secondLargestElement(arr, n);
    int sSmallest = secondSmallestElement(arr, n);
    return {sLargest, sSmallest};
}

int main()
{
    vector<int> arr = {2, 14, 5, 6, 47, 17, 20};
    // vector<int> ans = secondLargest_secondSmallest(arr, 7);
    // vector<int> ans = secondLargestSmallest(arr, 7);
    vector<int> ans = getSecondOrderElements(arr, 7);
    cout << "The second largest element of the array is: " << ans[0] << endl;
    cout << "The second smallest element of the array is: " << ans[1] << endl;
    return 0;
}