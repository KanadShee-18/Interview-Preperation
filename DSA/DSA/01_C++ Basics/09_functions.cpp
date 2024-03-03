//// Functions: ////

/// How function actually work?

//  -> Functions are set of code which performs something for you.
//  -> Functions are used to modularised codes.
//  -> Functions are used to increase readability.
//  -> Functions are used to use same code in multiple times.
// void -> does not return anything.
// return
// parameterised
// non parameterised

#include <iostream>
using namespace std;

void printName(string name) {
    cout << "Hey, " << name;
}

int sum (int num1, int num2){
    int num3  = num1 + num2;
    return num3;
}

int main() {
    // string name;
    // cin >> name;
    // printName(name);

    // string name2;
    // cin >> name2;
    // printName(name2);

    ///// Take two numbers and print its sum.
    int num1, num2;
    cout << "ENter two numbers: ";
    cin >> num1 >> num2;
    // int num3 = num1 + num2;
    // cout << num3;
    int minimum = min(num1, num2); // Inbuilt
    cout << minimum;
    int res = sum (num1, num2);
    cout << "The sum is: " << res; 
    return 0;
}