///////         QUEUE          ///////
/// FIFO --> First In First Out


#include <bits/stdc++.h>
using namespace std;

int main (){
    queue <int> q;
    q.push(4); // {4}
    q.push(6); // {4, 6}
    q.emplace(8); // {4, 6, 9}

    q.back() += 5; // {4, 6, 13}
    cout << q.back() << endl; // it will print 13.
    cout << q.front() << endl; // it will print 4.
    
    q.pop(); // {6, 13}
    cout << q.front() << endl; // it will print 6.
    // Size, swap, empty are same as stack.
    return 0;
}

