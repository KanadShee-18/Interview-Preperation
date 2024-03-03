/// Function Pass by Value and Reference:

// #include <iostream>
// using namespace std;

// /// Pass By Value ///
// void doSomething(int num){
//     cout << num << endl;
//     num +=5;
//     cout << num << endl;
//     num +=5;
//     cout << num << endl;

// }

// int main() {
//     int num = 10;
//     doSomething(num);
//     cout << num << endl;
//     return 0;
// }



///// Pass By Reference: //////

// #include <iostream>
// using namespace std;

// void doSomething (string &s){
//     s[0] = 't';
//     cout << s << endl;
// }

// int printNum (int &num){
//     cout << num << endl;
//     num += 5;
//     cout << num << endl;
//     num += 5;
//     cout << num << endl;
// }

// int main() {
//     // string s  = "Kanad";
//     // doSomething (s);    
//     // cout << s << endl;
    
//     int num;
//     cin >> num;
//     printNum (num);
//     cout << num << endl;
//     return 0;
// }


#include <iostream>
using namespace std;

void doSomething (int arr[], int n){
    arr[0] += 100;
    cout << "Value inside function: " << arr[0] << endl;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0 ; i<n; i++){
        cin >> arr[i];
    }
    
    doSomething(arr, n);
    cout << "Value inside int main: " << arr[0] << endl;
    return 0;
}