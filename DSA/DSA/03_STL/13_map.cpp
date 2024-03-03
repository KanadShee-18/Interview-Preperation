///////     Map     ///////
// -----> Stores unique key in sorted order.
// --> {key, value} key may be of any datatypes
// --> keys are unique but there may be multiple same value
// --> Time Complexity >>> log(N)
#include <bits/stdc++.h>
using namespace std;

int main (){
    map <int, int> mpp;
    map <int, pair<int, int>> mpp2;
    map <pair<int, int>, int> mpp3;

    mpp[1] = 2; //{1, 2} // key->1 and value->2
    mpp.emplace(3,5); // {1, 2} {3, 5}
    mpp.insert({2,4}); // {1, 2} {3, 5} {2, 4}

    mpp3 [{2,3}] = 10; // {{2,3}, 10}

    for (auto it: mpp){                                 // 1 2
        cout << it.first << " " << it.second << endl;   // 2 4
    }                                                   // 3 5
    // here see the keys are unique.
    cout << mpp[1]; // print 2 // as the key is 1 and value is 2.
    cout << mpp[34]; // print 0 // as there is no 34.
    
    auto it = mpp.find(3); // {5,6} {1,2} {3,4}
    //cout << *(it).second; // print 4

    auto it = mpp.find(5); // if 5 is there ok, else it will pointing to mpp.end()
    auto it = mpp.lower_bound(2);
    auto it = mpp.upper_bound(3);
    // erase(), swap(), size(), empty() are same as others.
    return 0;
}