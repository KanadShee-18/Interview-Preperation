//// Print ALl Divisors   ///////

#include <bits/stdc++.h>
using namespace std;

// int printDivisors (int n){
//     cout << "The divisors of " << n << " are: ";
//     for (int i = 1; i<=n; i++){
//         if (n % i == 0) cout << i << " ";
//     }
// }

/// Another Process ///
void printDivisors (int n){
    vector <int> ls;
    // TC -> O(sqrt(n)) 
    for (int i = 1; i*i<=n; i++){
        if(n % i == 0){
            ls.push_back(i);
        }
        if ((n/i) != i){
            ls.push_back(n/i);
        }
    }
    // TC -> O(no. of factors * log(no. of factors))  
    sort (ls.begin(), ls.end());
    // O(number of factors)
    for (auto it : ls) cout << it << " ";
}

int main (){
    int num;
    cin >> num;
    printDivisors(num);
    return 0;
}