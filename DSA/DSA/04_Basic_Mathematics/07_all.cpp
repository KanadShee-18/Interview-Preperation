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


////// Palindrome or not    ///////
// ex: 212  121 1331 2112

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


////        Armstrong Number        /////

#include <bits/stdc++.h>
using namespace std;

bool armNum (int n){
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


//// Print ALl Divisors   ///////

#include <bits/stdc++.h>
using namespace std;

// int printDivisors (int n){
//     cout << "The divisors of " << n << " are: ";
//     for (int i = 1; i<=n; i++){
//         if (n % i == 0) cout << i << " ";
//     }
// }

/// Another Process ///
// the overall time complexity of the problem.
void printDivisors (int n){
    vector <int> ls;
    // TC -> O(sqrt(n)) 
    for (int i = 1; i*i<=n; i++){
        if(n % i == 0){
            ls.push_back(i);
        }
        if ((n/i) != i){
            ls.push_back(n/i);
        }
    }
    // TC -> O(no. of factors * log(no. of factors))  
    sort (ls.begin(), ls.end());
    // O(number of factors)
    for (auto it : ls) cout << it << " ";
}

int main (){
    int num;
    cin >> num;
    printDivisors(num);
    return 0;
}


////// Prime Numbers  ///////

#include <bits/stdc++.h>
using namespace std;

int main() {
    int num;
    cin >> num;
    int count = 0;
    for (int i = 1; i*i <= num; i++){
        if (num % i == 0){
            count ++;
            if ((num/i) != 0){
                count ++;
            }
        }
    }
    if (count == 2) {
        cout << num << " is a prime number.";
    }
    else{
        cout << num << " is not a prime number.";
    }
    return 0;
}


//////   GCD  //////

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    while(a > 0 && b > 0){
        if (a>b) a = a % b;
        else b = b % a;
    }
    if (a == 0) cout << b;
    else cout << a;
    return 0;
}