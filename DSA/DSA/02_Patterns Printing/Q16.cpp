// A 
// B B
// C C C
// D D D D
// E E E E E

#include <iostream>
using namespace std;

void Pattern16 (int n){
    for (int i = 0; i<n; i++){
        char ch = 'A' + i;
        for (int j = 0; j<=i; j++){
            cout << ch << " ";
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
        Pattern16(n);
        cout << endl;
    }
    return 0;
}