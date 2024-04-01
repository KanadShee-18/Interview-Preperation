//// Largest Element in Array: 

#include <bits/stdc++.h>
using namespace std;

// Brute: sort the array and return the last element. For this case the TC will be O(nlogn)

// Better / Optimal: TC -> O(n)
int largestElement (int arr[], int n){
    int maxElement = INT_MIN;
    for (int i = 0; i < n; i ++){
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }
    return maxElement;
}


int main () {
    int arr[] = {10, 20, -21, 45, 65, 47, 89};
    int n = 7;

    int maxElement = largestElement(arr, n);
    cout << "The maximum element in the array is: " << maxElement << endl;
    return 0;
}