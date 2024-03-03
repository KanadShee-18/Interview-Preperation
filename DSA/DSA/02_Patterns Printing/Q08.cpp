//  *********
//   *******
//    *****
//     ***
//      *

#include <iostream>
using namespace std;

void Pattern8 (int n){
    for (int i = 0; i<n; i++){
        // Spaces
        for (int j = 0; j<=i; j++){
            cout << " ";
        }
        // Stars
        for (int j = 1; j<=(2*n)-(2*i)-1; j++){
            cout << "*";
        }
        // Spaces
        for (int j = 0; j<=i; j++){
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
        Pattern8(n);
        cout << endl;
    }
    return 0;
}