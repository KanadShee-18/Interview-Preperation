/////           SET             /////
// --> Stores everything in a sorted order and sotres unique.
// find(), count(), insert() are most important here.

#include <bits/stdc++.h>
using namespace std;

int main (){
    set <int> st;
    st.insert(1); // {1}
    st.insert(2); // {1, 2}
    st.insert(2); // {1, 2} it will not store 2 again.
    st.insert(4); // {1, 2, 4}
    st.insert(3); // {1, 2, 3, 4}
    // Functionality of insert an vector can be used also, that only increases efficiency.
    // begin(), end(), rbegin(), rend(), size(), empty() and swap() are same as others.

    // {1, 2, 3, 4, 5}
    auto it = st.find(3); // -> it will return an iterator which points to 3. (basically points to the address)
    auto it = st.find(7); // if the element is not in the set, then the iterator will point to the st.end()
    
    // {1, 2, 3, 4, 5}
    st.erase (5); // erase 5 // takes logarithmic time
    st.erase(it); // we can also give the address of the element which is to be erased.
    // st.erase(it1, it2); // after erase {1, 4, 5} [first, last]

    int cnt = st.count(1); // if present then shows 1 else 0.

    // lower_bound() and upper_bound() function works in the same way as in the vector does. This is the syntax.
    auto it = st.lower_bound(2);
    auto it = st.upper_bound(4);

    // In a set, everything happens in (logN) time complexity.
    // size(), empty(), begin() everything is same as others.
    return 0;
}