/// Reverse a Number:

/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

Example 3:
Input: x = 120
Output: 21

constraints: -2^31 <= x <= 2^31 - 1
*/

#include <bits/stdc++.h>
using namespace std;

int reverseNumber(int n)
{
    int revNum = 0;
    while (n != 0)
    {
        int rem = n % 10;
        revNum = (revNum * 10) + rem;
        n = n / 10;
    }
    // Now, check the reversed number for the constraints
    if (revNum >= INT_MAX || revNum <= INT_MIN)
        return 0;
    return revNum;
}

int main()
{
    int n;
    cout << "Enter a number to reverse it: ";
    cin >> n;
    int reverseNum = reverseNumber(n);
    cout << endl
         << "The reverse of the number " << n << " is: " << reverseNum;
    return 0;
}