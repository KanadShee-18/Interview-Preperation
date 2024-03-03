////        Armstrong Number        /////

#include <bits/stdc++.h>
using namespace std;

void armNum (int n){
    int dup = n;
    int sum = 0;
    while(n > 0){
        int ld = n % 10;
        sum = sum + (ld* ld* ld);
        n = n/10;
    }
    if (dup == sum) cout << dup << " is an armstrong number.";
    else cout << dup << " is not an armstrong number.";
}

int main(){
    int num;
    cin >> num;
    armNum(num);
    return 0;
}

//////// Second Method /////////

// #include <bits/stdc++.h>
// using namespace std;

// int armNum(int n){
//     int dup = n;
//     int sum = 0;
//     while (n > 0){
//         int ld = n % 10;
//         sum = sum + (ld * ld * ld);
//         n = n / 10;
//     }
//     if (dup == sum) return 1;
//     else return 0;
// }

// int main() {
//     int num;
//     cin >> num;
//     if (armNum(num)) cout << num << " is an armstrong number.";
//     else cout << num << " is not an armstrong number.";
//     return 0;
// }