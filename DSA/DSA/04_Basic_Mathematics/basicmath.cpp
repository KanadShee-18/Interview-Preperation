/////////               Basic Maths                 ///////////

//////    Q1.  Reverse Number      ///////
// 3 solutions are given.

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

////// Q2. Palindrome or not    ///////
// Example of Palindrome Number: 212  121 1331 2112

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

////   Q3.     Armstrong Number        /////
//  2 Solutions are given.

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

#include <bits/stdc++.h>
using namespace std;

int armNum(int n){
    int dup = n;
    int sum = 0;
    while (n > 0){
        int ld = n % 10;
        sum = sum + (ld * ld * ld);
        n = n / 10;
    }
    if (dup == sum) return 1;
    else return 0;
}

int main() {
    int num;
    cin >> num;
    if (armNum(num)) cout << num << " is an armstrong number.";
    else cout << num << " is not an armstrong number.";
    return 0;
}