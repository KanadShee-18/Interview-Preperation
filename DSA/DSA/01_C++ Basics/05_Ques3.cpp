/* Take the age from the user and then decide accordingly
1. If age < 18; print -> not eligible for job.
2. If age >=18 and age <= 54; print -> eligible for job.
3. If age >= 55 and age <= 57; print -> eligible for job but retirement soon.
4. If age > 57; print -> retirement time.
*/

#include <iostream>
using namespace std;

int main() {
    int age;
    cout << "Enter your age: ";
    cin >> age;
    if (age < 18){
        cout << "Not eligible for job.";
    }
    // Now, nested loops
    else if (age <= 57){
        cout << "Eligible for job.";
        if (age >= 55){
            cout << ", but retirement Soon.";
        }
    }
    else{
        cout << "Retirement Time";
    }
    return 0;
}