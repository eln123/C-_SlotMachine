#include <iostream>
#include <string>
#include <random>
using namespace std;

int MAX_LINES = 3;
int MAX_BET = 100;
int MIN_BET = 1;

int deposit() {
    int amount;
    while (true) {
        cout << "What would you like to deposit? $";
        cin >> amount;
        if (amount) {
            /*
            The if statement is used to check if its an int. If it is, you break
            */
            break;
        } else {
            cin.clear();
            cin.ignore();
            cout << endl;
            cout << "Must be a number, try again" << endl;
            continue;
        }
    }
    return amount;
}

int get_number_of_lines() {
    int lines;
    while (true) {
        cout << "Enter the number of lines to bet on (1-" + to_string(MAX_LINES) + ")? ";
        cin >> lines;
        if (lines) {
            if (1 <= lines && lines <= MAX_LINES) {
                cout << "valid";
                bool valid = 1 <= lines;
                bool valid2 = lines <= MAX_LINES;
                cout << valid << endl;
                cout << valid2;
                break;
            }
            cout << "Enter a valid number of lines (1-3)" << endl;
            continue;
        } else {
            cin.clear();
            cin.ignore();
            /* These 2 lines of code prevent the program from running over and over without input from user
            
            */
            cout << endl;
            cout << "Must be a number, try again" << endl;
            continue;
        }
    }
    return lines;
}

int get_bet() {
    int amount;
    while (true) {
        cout << "What would you like to bet?";
        cin >> amount;
        if (amount) {
            if (MIN_BET <= amount && amount <= MAX_BET) {
                break;
            } else {
                cout << "Amount must be between " + to_string(MIN_BET) + "-" + to_string(MAX_BET) << endl;
                continue;
            }
        }
    }
    return amount;
}

int main() {
    int balance = deposit();
    int lines = get_number_of_lines();
    /* we have to define bet and total bet outside the while loop*/
    int bet = 0;
    int total_bet = 0;
    /* we need to check if bet is within the balance*/
    while (true) {
        bet = get_bet();
        total_bet =  bet * lines;
        if (total_bet > balance) {
            /* bet is higher than balance, try again*/
            cout << "You do not have enough to bet that amount, your current balance is : $" + to_string(balance) + ". You tried to bet: " + to_string(total_bet) << endl;
        } else {
            /* bet is within balance, break*/
            break;
        }
    }
    cout << "You are betting $" + to_string(bet) + " on " + to_string(lines) + ". Total bet = " + to_string(total_bet) << endl;
    return 0;
}