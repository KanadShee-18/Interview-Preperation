// 4 4 4 4 4 4 4 
// 4 3 3 3 3 3 4
// 4 3 2 2 2 3 4
// 4 3 2 1 2 3 4
// 4 3 2 2 2 3 4
// 4 3 3 3 3 3 4
// 4 4 4 4 4 4 4

#include <iostream>
using namespace std;

void Pattern22 (int n){
    for (int i = 0; i<(2*n-1); i++){
        for (int j = 0; j<(2*n-1); j++){
            int topDist = i;
            int leftDist = j;
            int rightDist = (2*n - 2)-j;
            int bottomDist = (2*n - 2)-i;
            cout << (n-(min(min(topDist, bottomDist), min(leftDist, rightDist)))) << " ";
        }
        cout  << endl;
    }
} 

int main() {
    int t;
    int n;
    cin >> t;
    for (int i = 0; i<t; i++){
        cin >> n;
        Pattern22(n);
        cout << endl;
    }
    return 0;
}