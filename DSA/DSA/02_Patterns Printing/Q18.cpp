// E         
// D E       
// C D E     
// B C D E   
// A B C D E

#include <iostream>
using namespace std;

void Pattern18 (int n){
    for (int i = 0; i<n; i++){
        for (char ch = 'E'-i; ch <= 'E'; ch++){
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
        Pattern18(n);
        cout << endl;
    }
    return 0;
}