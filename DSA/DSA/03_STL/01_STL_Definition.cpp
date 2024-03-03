// What is STL?

// -> STL is basically the compilation of long long algorithms, functions, iterators for which we don't have to write long long code.

// >> STL contains 4 items: (1) Algorithms, (2) Containers, (3) Functions, (4) Iterators.

// First we will learn about Contianers.
// And to learn about containers, first we have to learn about pairs.
// Now, what is Pair we will see with some examples.

#include <bits/stdc++.h>
using namespace std;

// Pairs:
// void explainPair (){
    
// }

int main() {
    pair<int, int> p = {1, 3}; // We can also use string, double, characters in the place of int.
    cout << p.first << " " << p.second << endl;

    pair<int, pair<int, int>> q = {2, {6,7}};
    cout << q.first << " " << q.second.first << " " << q.second.second << endl;

    pair <int, int> arr[] = {{1,2}, {3,4}, {5,6}, {7,8}};
    cout << arr[1].second;
    return 0;
}

