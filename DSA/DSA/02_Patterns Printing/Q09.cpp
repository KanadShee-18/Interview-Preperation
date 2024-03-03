//  *********
//   *******
//    *****
//     ***
//      *

#include <iostream>
using namespace std;

void Pattern9 (int n){
    for (int i = 0; i<n; i++){
        for (int j = 0; j<(n-i-1); j++){
            cout << " ";
        }
        for (int j = 0; j<(2*i)+1; j++){
            cout << "*";
        }
        for (int j = 0; j<(n-i-1); j++){
            cout << " ";
        }
        cout << endl;
    }
     for (int i = 0; i<n; i++){
        for (int j = 0; j<i; j++){
            cout << " ";
        }
        for (int j = 0; j<(2*n)-(2*i)-1; j++){
            cout << "*";
        }
        for (int j = 0; j<i; j++){
            cout << " ";
        }
        cout << endl;
    }
}


int main() {
    int t;
    int n;
    cin >> t;
    for (int i = 0; i<t; i++){
        cin >> n;
        Pattern9(n);
        cout << endl;
    }
    return 0;
}