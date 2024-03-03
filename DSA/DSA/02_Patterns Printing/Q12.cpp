// 1      1
// 12    21
// 123  321
// 12344321

#include <iostream>
using namespace std;

void Pattern12 (int n){
    for (int i = 1; i<=n; i++){
        // Numbers
        for (int j = 1; j<=i; j++){
            cout << j;
        }
        // Spaces
        for (int j = 1; j<=(2*n)-(2*i); j++){
            cout << " ";
        }
        // Numbers
        for (int j = i; j>=1; j--){
            cout << j;
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
        Pattern12(n);
        cout << endl;
    }
    return 0;
}