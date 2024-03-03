// 1 2 3 4 5
// 1 2 3 4
// 1 2 3
// 1 2
// 1

#include <iostream>
using namespace std;

void Pattern6 (int n){
    for (int i = 0; i<n; i++){
        for (int j = 1; j<=(n-i); j++){
            cout << j << " ";
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
        Pattern6(n);
        cout << endl;
    }
    return 0;
}