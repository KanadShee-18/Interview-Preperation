// A B C D E 
// A B C D
// A B C
// A B
// A

#include <iostream>
using namespace std;

void Pattern15 (int n){
    for (int i = 1; i<=n; i++){
        for (char ch = 'A'; ch <= 'A'+n-i; ch++){
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
        Pattern15(n);
        cout << endl;
    }
    return 0;
}