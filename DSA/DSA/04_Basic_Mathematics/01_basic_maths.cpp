/////////               Basic Maths                 ///////////


//////      Reverse Number      ///////
#include <bits/stdc++.h>
using namespace std;

int count (int n){
    int cnt = (int) log10(n) + 1;
    // int cnt = 0;
    // while (n > 0){
    //     // int last_digit = n % 10;
    //     cnt = cnt + 1;
    //     n = n/10;
    // }
    return cnt;
}

int revNum (int n){
    int revN = 0;
    while (n > 0){
        int last_digit = n % 10;
        revN = revN*10 + last_digit;
        n = n/10;
    }
    return revN;
}
int main (){
    int n;
    cin >> n;
    int ans = revNum(n);
    cout << ans;
    return 0;
}