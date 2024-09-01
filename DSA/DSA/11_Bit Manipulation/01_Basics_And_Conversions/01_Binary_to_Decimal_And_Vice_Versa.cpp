// Bit Manipulation:

// - Bit Manipulation is the act of algorithmically manipulating bits or binary digits.

#include <bits/stdc++.h>
using namespace std;

// Binary to Decimal:
// TC: O(logn) and SC: O(logn)
string Decimal_To_Binary(int num)
{

    if (num == 0)
        return "0";
    string result = "";
    while (num > 0)
    {
        if (num % 2 == 1)
            result += "1";
        else
            result += "0";
        num /= 2;
    }
    reverse(result.begin(), result.end());
    return result;
}

// Without using revers, we can directly insert the number in the beginning of the string. Here's how...

string Decimal_To_Binary2(int num)
{
    if (num == 0)
        return 0;
    string res = "";
    while (num > 0)
    {
        res.insert(res.begin(), (num % 2) ? '1' : '0');
        num /= 2;
    }
    return res;
}

// Binary To Decimal:
// TC: O(length of binary number) and SC: O(1)
int Binary_To_Decimal(string str)
{
    int n = str.length();
    int powerOf2 = 1;
    int num = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        // only check if there is 1. No need to check for 0. Bcz it will give us 0 whatever the power is.
        if (str[i] == '1')
        {
            num += powerOf2;
        }
        powerOf2 *= 2;
    }
    return num;
}

int main()
{
    int num;
    cout << "Enter a number to convert it into decimal: ";
    cin >> num;
    string binaryNum = Decimal_To_Binary2(num);
    cout << "The binary number is: " << binaryNum;

    string binaryNumber;
    cout << endl
         << endl
         << "Enter a binary number to convert it into decimal: ";
    cin >> binaryNumber;
    int decNum = Binary_To_Decimal(binaryNumber);
    cout << "The decimal number of " << binaryNumber << " is: " << decNum;
    return 0;
}