////////            Multiset               /////////
// --> Stores everything in a sorted order.

#include <bits/stdc++.h>
using namespace std;

int main() {
    multiset <int> ms;
    ms.insert(1); // {1}
    ms.insert(1); // {1, 1}
    ms.insert(1); // {1, 1, 1}

    ms.erase(1); // all 1 are erased

    int count = ms.count(1);
    // To erase only a single element we have to point to the iterator
    ms.erase(ms.find(1)); // {1, 1} Erase the first 1 as the iterator pointing to it. 
    // ms.erase(ms.find(1), ms.find(1)+2); // {1} it will erase first two 1. erase(start, end)
    // Rest all functions are same as set.
    return 0;
}