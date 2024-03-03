////******** Merge Sort: ***********/////

#include <bits/stdc++.h>
using namespace std;

// Merge Sort: 
// -> divide and merge.
void merge (int arr[], int low, int mid, int high) {
    vector <int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left ++;
        }
        else {
            temp.push_back(arr[right]);
            right ++;
        }
    }
    while (left <= mid) {
        temp.push_back(arr[left]);
        left ++;
    }
    while (right <= high) {
        temp.push_back(arr[right]);
        right ++;
    }
    for (int i = low; i <=high; i ++) {
        arr[i] = temp[i - low];
    }
    // TC -> O(NlogN)
    // SC -> O(N)

}
void Merge_Sort (int arr[], int low, int high) {
    if (low >= high) return;
    int mid = (low + high)/2;
    Merge_Sort(arr, low, mid); 
    Merge_Sort(arr, mid+1, high);
    merge(arr, low, mid, high); 
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

    Merge_Sort(arr, 0, n-1);

    cout << endl << "Now, after Sorting: " << endl;
    cout << "Your array is looks like: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}