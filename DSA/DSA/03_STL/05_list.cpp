///////          LIST           ////

#include <bits/stdc++.h>
using namespace std;

int main (){
    list <int> ls;

    ls.push_back(56); // {56}
    ls.emplace_back(67); // {56, 67}

    ls.push_front(34); // {34, 56, 67}
    ls.emplace_front(); // {56, 67}

    // rest functions are same as vector.
    // begin, end, rbegin, rend, clear, insert, size, swap
    return 0;
}