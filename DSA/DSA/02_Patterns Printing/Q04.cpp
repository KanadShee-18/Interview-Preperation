// 1
// 2 2
// 3 3 3 
// 4 4 4 4
// 5 5 5 5 5

#include <iostream>
using namespace std;

void Pattern4 (int n){
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=i; j++){
            cout << i << " ";
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
        Pattern4(n);
        cout << endl;
    }
    return 0;
}