// * * * * * 
// * * * *
// * * *
// * * 
// *

#include <iostream>
using namespace std;

void Pattern5 (int n){
    for (int i = 0; i<n; i++){
        for (int j = 1; j<=(n-i); j++){
            cout << "*" << " ";
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
        Pattern5(n);
        cout << endl;
    }
    return 0;
}