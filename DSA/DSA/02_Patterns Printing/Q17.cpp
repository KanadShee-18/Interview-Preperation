//      A     
//     ABA
//    ABCBA
//   ABCDCBA
//  ABCDEDCBA

#include <iostream>
using namespace std;

void Pattern17 (int n){
    for (int i = 0; i<n; i++){
        // Spaces
        for (int j = 0; j<=n-i-1; j++){
            cout << " ";
        }
        // Characters
        char ch = 'A';
        int breakPoint = (2*i+1)/2;
        for (int j = 1; j<=(2*i+1); j++){
            cout << ch;
            if (j<=breakPoint) ch++;
            else ch--;
        }
        // Spaces
        for (int j = 0; j<=n-i-1; j++){
            cout << " ";
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
        Pattern17(n);
        cout << endl;
    }
    return 0;
}