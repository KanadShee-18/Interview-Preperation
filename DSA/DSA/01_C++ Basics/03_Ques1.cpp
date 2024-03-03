// Write a program to take input the age and print it you are adult or not

#include <iostream>
using namespace std;

int main() {
    int age;
    cout << "Enter your age: ";
    cin >> age;
    cout << "Your age is: " << age << " and \n";
    if (age>=18)cout << "You are adult.";
    else cout << "You are not an adult.";
    return 0;
}