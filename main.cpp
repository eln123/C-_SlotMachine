#include <iostream>
#include <string>
#include <vector>
using namespace std;

int deposit() {
    while (true) {
        int amount;
        cout << "What would you like to deposit? $";
        cin >> amount;
        cout << amount;
        if (amount) {
            break;
        } else {
            cin.clear();
            cin.ignore();
            cout << endl;
            cout << "Must be a number, try again" << endl;
            continue;
        }
    }
    return 0;
}

int main() {
    deposit();
    return 0;
}