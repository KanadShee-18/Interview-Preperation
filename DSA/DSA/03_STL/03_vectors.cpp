// Vectors:

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector <int> v;

    v.push_back(1); // {1}
    v.emplace_back(2); // {1} -> {1,2}

    vector<pair<int, int>>vec;
    vec.push_back({4,5});
    vec.emplace_back(1,2);

    vector <int> v(5, 100); // {100, 100, 100, 100, 100};
    vector <int> v(5); // {_, _, _, _, _} <- any garbage value depending upon compiler,, and in this line we can add more value using push_back and can increase the size of the vector.
    vector <int> v1(5,20); // {20, 20, 20, 20, 20}
    vector <int> v2(v1); // v2 will be a copy of v1. -> {20, 20, 20, 20, 20}
    return 0;
}