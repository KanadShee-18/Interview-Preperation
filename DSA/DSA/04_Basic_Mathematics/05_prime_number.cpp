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


////    Another Process --> GFG //////

#include <bits/stdc++.h>
using namespace std;

bool checkPrime(int n){
    if (n == 1){
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0){
            return false;
        }
        else {
            return true;
        }
    }
    
}

int main() {
    int n;
    cin >> n;
    
    checkPrime(n);
    return 0;
}