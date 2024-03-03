//////              DEQUE            ///////

#include <bits/stdc++.h>
using namespace std;

int main () {
    deque <int> dq;
    dq.push_back(32); // {32}
    dq.emplace_back(51); // {32, 51}

    dq.push_front(40); // {40, 32, 51}
    dq.emplace_front(70); // {70, 40, 32, 51}

    dq.back();
    dq.front();
    
    // rest functions are same as vector.
    // begin, end, rbegin, rend, clear, insert, size, swap
    return 0;
}