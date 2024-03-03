// **********
// ****  ****
// ***    ***
// **      **
// *        *
// *        *
// **      **
// ***    ***
// ****  ****
// **********

#include <iostream>
using namespace std;

void Pattern19 (int n){
    int initialSpace = 0;
    for (int i = 0; i<n; i++){
        // Stars
        for (int j = 1; j<=(n-i); j++){
            cout << "*";
        }
        // Spaces
        for (int j = 0; j<initialSpace; j++){
            cout << " ";
        }
        // Stars
        for (int j = 1; j<=(n-i); j++){
            cout << "*";
        }
        initialSpace = initialSpace + 2;
        cout << endl;
    }

    int initS = 2*n-2;
    for (int i = 1; i<=n; i++){
        // Stars
        for (int j = 1; j<=i; j++){
            cout << "*";
        }
        // Spaces
        for (int j = 0; j<initS; j++){
            cout << " ";
        }
        // Stars
        for (int j = 1; j<=i; j++){
            cout << "*";
        }
        initS = initS - 2;
        cout << endl;

    }
}

int main() {
    int t;
    int n;
    cin >> t;
    for (int i = 0; i<t; i++){
        cin >> n;
        Pattern19(n);
        cout << endl;
    }
    return 0;
}