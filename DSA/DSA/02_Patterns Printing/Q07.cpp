//     *
//    ***
//   *****
//  *******
// *********

#include <iostream>
using namespace std;

void Pattern7 (int n){
    for (int i = 0; i<n; i++){
        // Spaces
        for (int j = 1; j<=(n-i-1); j++){
            cout << " ";
        }
        // Stars
        for (int j = 1; j<=(2*i)+1; j++){
            cout << "*";
        }
        // Spaces
        for (int j = 1; j<=(n-i-1); j++){
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
        Pattern7(n);
        cout << endl;
    }
    return 0;
}