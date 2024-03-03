/////////        Unordered Set         /////////
// --> it does not have any order, we can store randomly but it is unique.
#include <bits/stdc++.h>
using namespace std;

int main (){
    unordered_set <int> us;
    // {6, 8, 1, 2, 5, 4}
    // lower_bound() and upper_bound() functions doesn't work here.
    // rest all functions are same.
    // it does not store in any particular order.
    // it has a better complexity than set in most cases, except some when collision happens.
    return 0;
}