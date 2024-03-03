///////       STACK      ///////
/// --> (LIFO) Last In Front Out
// just push, pop, top are the main here.
// In stack, the time complexity is O(1). Everything happens in constants. 
#include <bits/stdc++.h>
using namespace std;

int main (){
    stack <int> st;
    st.push(1); // {1}
    st.push(2); // {2, 1}
    st.push(3); // {3, 2, 1}
    st.push(3); // {3, 3, 2, 1}
    st.push(5); // {5, 3, 3, 2, 1}

    cout << st.top(); // This will print 5. st[0], sy[1].... st[5] <-- these are invalid.

    st.pop(); // {3, 3, 2, 1}
    cout << st.top(); // 3
    cout << st.size(); // 4
    cout << st.empty();

    stack <int> st1, st2;
    st1.swap(st2);
    return 0;
}