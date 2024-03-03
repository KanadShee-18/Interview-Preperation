// // What is STL?
// // --> STL is basically the compilation of long long algorithms, functions, iterators for which we dont have to write long long codes.

// // STL has basically 4 items: (1) Algorithms, (2) Containers, (3) Functions & (4) Iterators.

// /// Now, we will learn what is container. 
// // And to learn container we have to know how to use pairs or, what is pair!!!

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     pair<int, int> p1 = {5, 4}; // And here we can also use string, char and float.
//     cout << p1.first << " " << p1.second << " " << endl;

//     pair <int, pair<int, int>> p2 = {7, {8,9}};
//     cout << p2.first << " " << p2.second.first << " " << p2.second.second << " " << endl;

//     pair <int, int> arr[] = {{10,20}, {30, 40}, {50, 60}, {70, 80}, {90, 100}};
//     for (int i = 0; i<4; i++){
//         cout << arr[i].first << " " << arr[i].second << endl;
//     }
//     return 0;
// }

// /// So, now we will learn what is Vector!!! //////

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     vector <int> v;
//     v.push_back(10);
//     v.emplace_back(20);
//     cout << v[0] << endl;

//     vector <pair <int, int>> vec;
//     vec.push_back({4,5});
//     vec.emplace_back(7,8);
    
//     vector <int> v(5, 100); // {100, 100, 100, 100, 100}
//     vector <int> v5(5); // if we don't store any value here, then it will store any garbage value depending upon the compiler.

//     for (int i = 0; i<5; i++){
//         cout << "Enter the " << i+1 << "element of the vector: ";
//         cin >> v5[i];
//     }
//     for (int i = 0; i<5; i++){
//         cout << "The first element of the vector is: " << v5[i] << endl;
//     }

//     // We also can copy the values of one vector to another vector.
//     vector <int> v10(5,20);
//     vector <int> v2(v10); // It will copy the value of v10 in v2.
//     return 0;
// }

// /////// Now, we have to know, what is Iterators ////////

// // Iterators:

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     vector<int> v;
//     v = {12, 48, 56, 47, 45};
//     cout << v[2] << " ";
//     v.push_back(100);
//     cout << v[5] << " ";

//     vector<int>::iterator it = v.begin(); // It is directing to 12 in the beginning 0th position and after it++, it will be pointing towards 45.
//     it++;
//     cout << *(it) << " ";
//     it = it + 2;
//     cout << *(it) << " ";

//     There are some other syntaxes except v.begin()
//     vector <int> :: iterator it = v.end(); // This will not pointing to 45, this will pointing right after 45. to get 45 we have to use it--.

//     vector <int> :: iterator it = v.rend(); --> {45, 47, 56, 48, 12},, and this is pointing right after 12 and it-- => 12
//     vector <int> :: iterator it = v.rbegin(); -> {45, 47, 56, 48, 12},,
//     and this is pointing to 45 and it++ => 47.

//     cout << v[0] << " " << v.at(0) << " ";
//     cout << v.back() << " "; // this will pointing to the last element and here the last element is 100.

//     // We can also run a for loop using these terms.
//     for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//     {
//         cout << *(it) << " "; // {}
//     }
//     In STL in the place of
//     for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
//     we can use for (auto it = v.begin(); it != v.end(); it++){

//     As there is integer, so it will automatically asigned it as an int,
//     if it was float, string or any other datatypes, then it will automatically detect that and will assign according to the datatyoes.

//     for (auto it = v.begin(); it != v.end(); it++){
//         cout << *(it) <<  " ";
//     }

//     vector <int> v3 = {15, 45, 78, 14, 36};
//     for (auto it : v3){
//         cout << it << " "; // First it will target 15 and then to the upcoming values.
//     }

//     //// We also can erase the values from a vector. ////////
//     /////         ERASE Function          ///////
//     vector <int> v4 = {12, 47, 58, 95, 41};
//     v4.erase(v4.begin() + 2); // It will erase 58 form the vector. {12 47 95 41}

//     / We also can erase multiple elements from a vector. To do that---->
//     v4.erase (v4.begin()+2, v4.begin()+4); [start, end]
//     for (auto it = v4.begin(); it != v4.end(); it++){
//         cout << *(it) << " "; // {12 47 41}
//     }

//     ////// We also can insert some elements in a defined vector. ///////
//     vector <int> v5(2,100); // {100, 100}
//     // v5.insert(v5.begin(), 300); // {300, 100, 100}
//     v5.insert(v5.begin()+1, 2, 10); // {100, 10, 10, 100} 
//     v5.insert(v5.begin()+1, 5, 10); // {100, 10, 10, 10, 10, 10, 100} 
//     // here it will insert two 10 in the 1st position.

//     ///// ERASE and INSERT are very important.

//     vector <int> copy(4,30);
//     v5.insert(v5.begin(), copy.begin(), copy.end()); // {30 30 30 30 100 10 10 10 10 10 10 10 100 }
//     cout << endl;
//     cout << v5.size() << endl; // This will give the size of the vector.
//     v5.pop_back(); // {30 30 30 30 100 10 10 10 10 10 10 10} This will delete the last element.
//     // for (auto it = v5.begin(); it != v5.end(); it++){
//     //     cout << *(it) << " ";
//     // }
//     vector <int> v20 = {15, 48};
//     vector <int> v30 = {45, 98};
//     v20.swap(v30);
//     cout << v20[0] << " " << v20[1] << endl; // v20 = {45, 98}
//     cout << v30[0] << " " << v30[1]; // v30 = {15, 48}

//     v5.clear(); // Clear the entire vector.
//     cout << v5.empty();
//     return 0;
// }

// ///////          LIST           ////

// #include <bits/stdc++.h>
// using namespace std;

// int main (){
//     list <int> ls;

//     ls.push_back(56); // {56}
//     ls.emplace_back(67); // {56, 67}

//     ls.push_front(34); // {34, 56, 67}
//     ls.emplace_front(); // {56, 67}

//     // rest functions are same as vector.
//     // begin, end, rbegin, rend, clear, insert, size, swap
//     return 0;
// }

// //////              DEQUE            ///////

// #include <bits/stdc++.h>
// using namespace std;

// int main () {
//     deque <int> dq;
//     dq.push_back(32); // {32}
//     dq.emplace_back(51); // {32, 51}

//     dq.push_front(40); // {40, 32, 51}
//     dq.emplace_front(70); // {70, 40, 32, 51}

//     dq.back();
//     dq.front();
    
//     // rest functions are same as vector.
//     // begin, end, rbegin, rend, clear, insert, size, swap
//     return 0;
// }

// ///////       STACK      ///////
// /// --> (LIFO) Last In Front Out
// // just push, pop, top are the main here.
// // In stack, the time complexity is O(1). Everything happens in constants. 
// #include <bits/stdc++.h>
// using namespace std;

// int main (){
//     stack <int> st;
//     st.push(1); // {1}
//     st.push(2); // {2, 1}
//     st.push(3); // {3, 2, 1}
//     st.push(3); // {3, 3, 2, 1}
//     st.push(5); // {5, 3, 3, 2, 1}

//     cout << st.top(); // This will print 5. st[0], sy[1].... st[5] <-- these are invalid.

//     st.pop(); // {3, 3, 2, 1}
//     cout << st.top(); // 3
//     cout << st.size(); // 4
//     cout << st.empty();

//     stack <int> st1, st2;
//     st1.swap(st2);
//     return 0;
// }

// ///////         QUEUE          ///////
// /// FIFO --> First In First Out


// #include <bits/stdc++.h>
// using namespace std;

// int main (){
//     queue <int> q;
//     q.push(4); // {4}
//     q.push(6); // {4, 6}
//     q.emplace(8); // {4, 6, 9}

//     q.back() += 5; // {4, 6, 13}
//     cout << q.back() << endl; // it will print 13.
//     cout << q.front() << endl; // it will print 4.
    
//     q.pop(); // {6, 13}
//     cout << q.front() << endl; // it will print 6.
//     // Size, swap, empty are same as stack.
//     return 0;
// }

// ///////        PRIORITY QUEUE       ////////
// // -> The guy with the largest value stays at the top.

// #include <bits/stdc++.h>
// using namespace std;

// int main (){
//     priority_queue <int> pq;

//     pq.push(6); // {6}
//     pq.push(8); // {8, 6}
//     pq.push(10); // {10, 8, 6}
//     pq.emplace(43); // {43, 10, 8, 6}

//     cout << pq.top(); // print 43
//     // Now, if we insert 7 in pq, then it will be inserted between 6 and 8.
//     pq.pop(); // {10, 8, 6}
//     cout << pq.top(); // print 10
//     // size, swap, empty function are same as others.

//     // What will be the functions if I want to store minimum element in the top of the priority_queue
//     priority_queue <int, vector<int>, greater<int>> pq;
//     pq.push(5); // {5}
//     pq.push(3); // {3, 5}
//     pq.push(2); // {2, 3, 5}
//     pq.emplace(10); // {2, 3, 5, 10}

//     cout << pq.top(); // print 2
//     return 0;
// }


// ////   Time Complexity of some of the functions.
// // (1) push => log(n)
// // (2) top  => O(1)
// // (1) pop  => log(n)

// /////           SET             /////
// // --> Stores everything in a sorted order and sotres unique.
// // find(), count(), insert() are most important here.

// #include <bits/stdc++.h>
// using namespace std;

// int main (){
//     set <int> st;
//     st.insert(1); // {1}
//     st.insert(2); // {1, 2}
//     st.insert(2); // {1, 2} it will not store 2 again.
//     st.insert(4); // {1, 2, 4}
//     st.insert(3); // {1, 2, 3, 4}
//     // Functionality of insert an vector can be used also, that only increases efficiency.
//     // begin(), end(), rbegin(), rend(), size(), empty() and swap() are same as others.

//     // {1, 2, 3, 4, 5}
//     auto it = st.find(3); // -> it will return an iterator which points to 3. (basically points to the address)
//     auto it = st.find(7); // if the element is not in the set, then the iterator will point to the st.end()
    
//     // {1, 2, 3, 4, 5}
//     st.erase (5); // erase 5 // takes logarithmic time
//     st.erase(it); // we can also give the address of the element which is to be erased.
//     // st.erase(it1, it2); // after erase {1, 4, 5} [first, last]

//     int cnt = st.count(1); // if present then shows 1 else 0.

//     // lower_bound() and upper_bound() function works in the same way as in the vector does. This is the syntax.
//     auto it = st.lower_bound(2);
//     auto it = st.upper_bound(4);

//     // In a set, everything happens in (logN) time complexity.
//     // size(), empty(), begin() everything is same as others.
//     return 0;
// }

// ////////            Multiset               /////////
// // --> Stores everything in a sorted order.

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     multiset <int> ms;
//     ms.insert(1); // {1}
//     ms.insert(1); // {1, 1}
//     ms.insert(1); // {1, 1, 1}

//     ms.erase(1); // all 1 are erased

//     int count = ms.count(1);
//     // To erase only a single element we have to point to the iterator
//     ms.erase(ms.find(1)); // {1, 1} Erase the first 1 as the iterator pointing to it. 
//     // ms.erase(ms.find(1), ms.find(1)+2); // {1} it will erase first two 1. erase(start, end)
//     // Rest all functions are same as set.
//     return 0;
// }

// /////////        Unordered Set         /////////
// // --> it does not have any order, we can store randomly but it is unique.
// #include <bits/stdc++.h>
// using namespace std;

// int main (){
//     unordered_set <int> us;
//     // {6, 8, 1, 2, 5, 4}
//     // lower_bound() and upper_bound() functions doesn't work here.
//     // rest all functions are same.
//     // it does not store in any particular order.
//     // it has a better complexity than set in most cases, except some when collision happens.
//     return 0;
// }

// ///////     Map     ///////
// // -----> Stores unique key in sorted order.
// // --> {key, value} key may be of any datatypes
// // --> keys are unique but there may be multiple same value
// // --> Time Complexity >>> log(N)
// #include <bits/stdc++.h>
// using namespace std;

// int main (){
//     map <int, int> mpp;
//     map <int, pair<int, int>> mpp2;
//     map <pair<int, int>, int> mpp3;

//     mpp[1] = 2; //{1, 2} // key->1 and value->2
//     mpp.emplace(3,5); // {1, 2} {3, 5}
//     mpp.insert({2,4}); // {1, 2} {3, 5} {2, 4}

//     mpp3 [{2,3}] = 10; // {{2,3}, 10}

//     for (auto it: mpp){                                 // 1 2
//         cout << it.first << " " << it.second << endl;   // 2 4
//     }                                                   // 3 5
//     // here see the keys are unique.
//     cout << mpp[1]; // print 2 // as the key is 1 and value is 2.
//     cout << mpp[34]; // print 0 // as there is no 34.
    
//     auto it = mpp.find(3); // {5,6} {1,2} {3,4}
//     //cout << *(it).second; // print 4

//     auto it = mpp.find(5); // if 5 is there ok, else it will pointing to mpp.end()
//     auto it = mpp.lower_bound(2);
//     auto it = mpp.upper_bound(3);
//     // erase(), swap(), size(), empty() are same as others.
//     return 0;
// }

// ///////         Multimap        ////////
// // -----> everything similar to map but can able to store duplicate keys in sorted order. Only map[key] cann't be used here. 
// // {1, 2} {1, 4}

// ///////         Unordered map          ////////
// // -----> it will have unique keys but will not be sorted. it will be randomised.
// // Time Complexity >> O(1) in all most cases and in worst case O(N)

// //// Some Important Algorithms  ////

// #include <bits/stdc++.h>
// using namespace std;

// bool comp (pair <int, int>p1, pair <int, int>p2){
//     if (p1.second < p2.second) return true;
//     if (p1.second > p2.second) return false;
//     // they will same
//     if (p1.first > p2.first) return true;
//     else false;
// }

// int main(){
//     // let say, we have given an array and we have to sort it. In C++, we can use an function without any sorting operation.
//     // {1, 6, 8, 3}
//     sort(a, a+n); // a -> the starting position the first iterator and a+n the last iterator which is after the last element.
//     // now, {1, 3, 6, 8}
//     // We can also use----->
//     sort(v.begin(), v.end());

//     // Another Example: 
//     // {1, 4, 7, 5, 2} and we just want to sort 5 and 2
//     sort(a+3, a+5);
//     // Now, I want to sort them in descending order. 
//     //ex:  {1, 3, 5, 2}
//     sort(a, a+n, greater<int>); // {5, 3, 2, 1} // start end greater<datatype>
//     // Here we have done asscending and descending order
//     // Now, there can be any order 

//     pair <int, int> a[] = {{1,2}, {2,1}, {4,1}};
//     // Sort it according to the second element.// {2,1} {4,1} {1,2}
//     // if second element is same, then sort.
//     // according to the first element but in descending. // {4,1} {2,1} {1,2}
//     // here, we have to do sort(start, end, comp) -> comp >> self written comperator and comp is a boolian function.
//     sort(a, a+n, comp); // comp function is written above

//     int num = 7; // 7 -> 111
//     int cnt = __builtin_popcount(); // it asks how many set bits are there, according to here there are 3 set bits.

//     long long num2 = 1256548759547;
//     int cnt = __builtin_popcountll();

//     string s = "123"; // Let say I want all the permutation of string s.
//     sort (s.begin(), s.end());
//     do {
//         cout << s << endl;
//     } while(next_permutation(s.begin(), s.end()));
    
//     // Let say we want the maximum or minimum element from the array. 
//     // {1, 10, 45, 4, 87}
//     int maxi = *max_element(a, a+n);
//     int mini = *min_element(a, a+n);
//     return 0;
// }