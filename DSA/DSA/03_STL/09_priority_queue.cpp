///////        PRIORITY QUEUE       ////////
// -> The guy with the largest value stays at the top.

#include <bits/stdc++.h>
using namespace std;

int main (){
    priority_queue <int> pq;

    pq.push(6); // {6}
    pq.push(8); // {8, 6}
    pq.push(10); // {10, 8, 6}
    pq.emplace(43); // {43, 10, 8, 6}

    cout << pq.top(); // print 43
    // Now, if we insert 7 in pq, then it will be inserted between 6 and 8.
    pq.pop(); // {10, 8, 6}
    cout << pq.top(); // print 10
    // size, swap, empty function are same as others.

    // What will be the functions if I want to store minimum element in the top of the priority_queue
    priority_queue <int, vector<int>, greater<int>> pq;
    pq.push(5); // {5}
    pq.push(3); // {3, 5}
    pq.push(2); // {2, 3, 5}
    pq.emplace(10); // {2, 3, 5, 10}

    cout << pq.top(); // print 2
    return 0;
}


////   Time Complexity of some of the functions.
// (1) push => log(n)
// (2) top  => O(1)
// (1) pop  => log(n)