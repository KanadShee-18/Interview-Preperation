// * 
// * * 
// * * * 
// * * * * 
// * * * * *

#include <iostream>
using namespace std;

void Pattern2 (int n){
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=i; j++){
            cout << "* ";
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
        Pattern2(n);
        cout << endl;
    }
    return 0;
}