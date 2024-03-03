//// Count the Digits:

// #include <bits/stdc++.h>
// using namespace std;

// int count(int n){
//     int cnt = 0;
//     while (n > 0){
//         int ld = (n % 10);
//         cnt ++;
//         n = n / 10;
//     }
//     return cnt;
// }

// int main() {
//     int num;
//     cout << "Enter the number: ";
//     cin >> num;
//     int digit = count (num);
//     cout << "The number of digits in " << num << " is: " << digit << endl;
//     return 0;
// }

// ////// Reverse a Number: ///////

// #include <bits/stdc++.h>
// using namespace std;

// int revNum (int n){
//     int rev = 0;
//     while (n > 0){
//         int ld = n % 10;
//         rev = rev * 10 + ld;
//         n = n / 10;
//     }
//     return rev;
// }

// int main() {
//     int num;
//     cout << "Enter a number to reverse it: ";
//     cin >> num;
//     int newNum = revNum(num);
//     cout << "After reversing the new number is: " << newNum << endl;
//     return 0;
// }

/////// Palindrome number or not:   ///////

// #include <bits/stdc++.h>
// using namespace std;

// int palinNum (int n){
//     int dup = n;
//     int revN = 0;
//     while (n > 0){
//         int ld = n % 10;
//         int revN = revN * 10 + ld;
//         n = n / 10;
//     }
//     if (dup == revN) return 1;
//     else return 0;
// }

// int main() {
//     int num;
//     cout << "Enter the number to check if it is palindrome or not: ";
//     cin >> num;
//     if (palinNum(num)){
//         cout << num << " is a palindrome number";
//     }
//     else {
//         cout << "No, " << num << " is not a palindrome number.";
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main (){
    int n;
    cin >> n;
    int revNum = 0;
    int dup = n;
    while(n > 0){
        int ld = n % 10;
        revNum = revNum * 10 + ld;
        n = n/10;
    }
    if (dup == revNum) cout << "true";
    else cout << "false";
    return 0;
}