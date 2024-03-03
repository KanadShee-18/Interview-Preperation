// Iterators:

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    v = {12, 48, 56, 47, 45};
    cout << v[2] << " ";
    v.push_back(100);
    cout << v[5] << " ";

    vector<int>::iterator it = v.begin(); // It is directing to 12 in the beginning 0th position and after it++, it will be pointing towards 45.
    it++;
    cout << *(it) << " ";
    it = it + 2;
    cout << *(it) << " ";

    There are some other syntaxes except v.begin()
    vector <int> :: iterator it = v.end(); // This will not pointing to 45, this will pointing right after 45. to get 45 we have to use it--.

    vector <int> :: iterator it = v.rend(); --> {45, 47, 56, 48, 12},, and this is pointing right after 12 and it-- => 12
    vector <int> :: iterator it = v.rbegin(); -> {45, 47, 56, 48, 12},,
    and this is pointing to 45 and it++ => 47.

    cout << v[0] << " " << v.at(0) << " ";
    cout << v.back() << " "; // this will pointing to the last element and here the last element is 100.

    // We can also run a for loop using these terms.
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << " "; // {}
    }
    In STL in the place of
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
    we can use for (auto it = v.begin(); it != v.end(); it++){

    As there is integer, so it will automatically asigned it as an int,
    if it was float, string or any other datatypes, then it will automatically detect that and will assign according to the datatyoes.

    for (auto it = v.begin(); it != v.end(); it++){
        cout << *(it) <<  " ";
    }

    vector <int> v3 = {15, 45, 78, 14, 36};
    for (auto it : v3){
        cout << it << " "; // First it will target 15 and then to the upcoming values.
    }

    //// We also can erase the values from a vector. ////////
    /////         ERASE Function          ///////
    vector <int> v4 = {12, 47, 58, 95, 41};
    v4.erase(v4.begin() + 2); // It will erase 58 form the vector. {12 47 95 41}

    / We also can erase multiple elements from a vector. To do that---->
    v4.erase (v4.begin()+2, v4.begin()+4); [start, end]
    for (auto it = v4.begin(); it != v4.end(); it++){
        cout << *(it) << " "; // {12 47 41}
    }

    ////// We also can insert some elements in a defined vector. ///////
    vector <int> v5(2,100); // {100, 100}
    // v5.insert(v5.begin(), 300); // {300, 100, 100}
    v5.insert(v5.begin()+1, 2, 10); // {100, 10, 10, 100} 
    v5.insert(v5.begin()+1, 5, 10); // {100, 10, 10, 10, 10, 10, 100} 
    // here it will insert two 10 in the 1st position.

    ///// ERASE and INSERT are very important.

    vector <int> copy(4,30);
    v5.insert(v5.begin(), copy.begin(), copy.end()); // {30 30 30 30 100 10 10 10 10 10 10 10 100 }
    cout << endl;
    cout << v5.size() << endl; // This will give the size of the vector.
    v5.pop_back(); // {30 30 30 30 100 10 10 10 10 10 10 10} This will delete the last element.
    // for (auto it = v5.begin(); it != v5.end(); it++){
    //     cout << *(it) << " ";
    // }
    vector <int> v20 = {15, 48};
    vector <int> v30 = {45, 98};
    v20.swap(v30);
    cout << v20[0] << " " << v20[1] << endl; // v20 = {45, 98}
    cout << v30[0] << " " << v30[1]; // v30 = {15, 48}

    v5.clear(); // Clear the entire vector.
    cout << v5.empty();
    return 0;
}