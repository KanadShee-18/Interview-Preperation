// Problem using Switch Statement.
/*
Take the day number and print the corresponding day.
for 1 print Monday.
For 2 print Tuesday and so on for 7 print Sunday.
*/

#include <iostream>
using namespace std;

int main() {
    int dayNo;
    cout << "Enter the day number: " ;
    cin >> dayNo;
    switch(dayNo){
        case 1:
            cout << "Monday";
            break;
        case 2:
            cout << "Tuesday";
            break;
        case 3:
            cout  << "Wednesday";
            break;
        case 4:
            cout << "Thursday";
            break;
        case 5:
            cout << "Friday";
            break;
        case 6:
            cout << "Saturday";
            break;
        case 7:
            cout << "Sunday";
            break;
        default: 
            cout << "Invalid Check";
    }
    cout << "Check";
    return 0;
}