//// Some Important Algorithms  ////

#include <bits/stdc++.h>
using namespace std;

bool comp (pair <int, int>p1, pair <int, int>p2){
    if (p1.second < p2.second) return true;
    if (p1.second > p2.second) return false;
    // they will same
    if (p1.first > p2.first) return true;
    else false;
}

int main(){
    // let say, we have given an array and we have to sort it. In C++, we can use an function without any sorting operation.
    // {1, 6, 8, 3}
    sort(a, a+n); // a -> the starting position the first iterator and a+n the last iterator which is after the last element.
    // now, {1, 3, 6, 8}
    // We can also use----->
    sort(v.begin(), v.end());

    // Another Example: 
    // {1, 4, 7, 5, 2} and we just want to sort 5 and 2
    sort(a+3, a+5);
    // Now, I want to sort them in descending order. 
    //ex:  {1, 3, 5, 2}
    sort(a, a+n, greater<int>); // {5, 3, 2, 1} // start end greater<datatype>
    // Here we have done asscending and descending order
    // Now, there can be any order 

    pair <int, int> a[] = {{1,2}, {2,1}, {4,1}};
    // Sort it according to the second element.// {2,1} {4,1} {1,2}
    // if second element is same, then sort.
    // according to the first element but in descending. // {4,1} {2,1} {1,2}
    // here, we have to do sort(start, end, comp) -> comp >> self written comperator and comp is a boolian function.
    sort(a, a+n, comp); // comp function is written above

    int num = 7; // 7 -> 111
    int cnt = __builtin_popcount(); // it asks how many set bits are there, according to here there are 3 set bits.

    long long num2 = 1256548759547;
    int cnt = __builtin_popcountll();

    string s = "123"; // Let say I want all the permutation of string s.
    sort (s.begin(), s.end());
    do {
        cout << s << endl;
    } while(next_permutation(s.begin(), s.end()));
    
    // Let say we want the maximum or minimum element from the array. 
    // {1, 10, 45, 4, 87}
    int maxi = *max_element(a, a+n);
    int mini = *min_element(a, a+n);
    return 0;
}