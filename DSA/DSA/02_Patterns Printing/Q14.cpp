// A 
// A B
// A B C
// A B C D
// A B C D E

#include <iostream>
using namespace std;

void Pattern14 (int n){
    for (int i = 0; i<n; i++){
        for (char ch = 'A'; ch <= 'A'+i; ch++){
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
        Pattern14(n);
        cout << endl;
    }
    return 0;
}