// *****
// *   *
// *   *
// *   *
// *****

#include <iostream>
using namespace std;

void Pattern21 (int n){
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            if (i==0 || i==n-1 || j==0|| j==n-1){
                cout << "*";
            }
            else {
                cout << " ";
            }
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
        Pattern21(n);
        cout << endl;
    }
    return 0;
}