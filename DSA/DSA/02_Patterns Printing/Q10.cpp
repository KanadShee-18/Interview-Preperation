// *
// **
// ***
// ****
// *****
// ****
// ***
// **
// *     

#include <iostream>
using namespace std;

void Pattern10 (int n){
    for (int i = 1; i<=2*n-1; i++){
        int stars = i;
        if (i>n) stars = (2*n-i);
        for (int j = 1; j<=stars; j++){
            cout << "*";
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
        Pattern10(n);
        cout << endl;
    }
    return 0;
}