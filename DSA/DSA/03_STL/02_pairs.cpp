////////    Pairs   /////////

#include <bits/stdc++.h>
using namespace std;

int main() {
    pair<int, int> p = {1, 3}; // We can also use string, double, characters in the place of int.
    cout << p.first << " " << p.second << endl;

    pair<int, pair<int, int>> q = {2, {6,7}};
    cout << q.first << " " << q.second.first << " " << q.second.second << endl;

    pair <int, int> arr[] = {{1,2}, {3,4}, {5,6}, {7,8}};
    cout << arr[1].second;
    return 0;
}