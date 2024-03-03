///////****** Bubble Sort ******////////

#include <bits/stdc++.h>
using namespace std;

// Bubble Sort:
// -> push the max element to the end using adjacent swapping.
void bubble_sort(int arr[], int n) {
    for (int i = n-1; i >= 1; i--) {
        int didSwap = 0;
        for (int j = 0; j <= (i-1); j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                didSwap = 1;
            }
        }
        if (didSwap == 0) break; // means the arrr is already sorted, there is no need to run the loop again.
        // cout << "runs\n";

    }
    // here also the TC is quite similar like Selection Sort.
    // So, the complexity is O(n^2) but for the worst/avg complexity.
    // for best case, O(n)
}

int main() {
    int n;
    cout << "How many numbers do you want to store in the array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Your array is looks like: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    bubble_sort(arr, n);

    cout << endl << "Now, after Sorting: " << endl;
    cout << "Your array is looks like: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}