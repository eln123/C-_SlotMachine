#include <iostream>
#include <map>
#include <vector>
#include <array>
#include <tuple>
#include <string>
#include <random>
using namespace std;
// g++ -std=c++11 -o run main.cpp

/* 1) */
int deposit()
{
    int amount;
    while (true)
    {
        cout << "What would you like to deposit? $";
        cin >> amount;
        if (amount)
        {
            /*
            The if statement is used to check if its an int. If it is, you break
            */
            break;
        }
        else
        {
            cin.clear();
            cin.ignore();
            cout << endl;
            cout << "Must be a number, try again" << endl;
            continue;
        }
    }
    return amount;
}
int MAX_LINES = 3;
/* 2) */
int get_number_of_lines()
{
    int lines;
    while (true)
    {
        cout << "Enter the number of lines to bet on (1-" + to_string(MAX_LINES) + ")? ";
        cin >> lines;
        if (lines)
        {
            if (1 <= lines && lines <= MAX_LINES)
            {
                cout << "valid";
                bool valid = 1 <= lines;
                bool valid2 = lines <= MAX_LINES;
                cout << valid << endl;
                cout << valid2;
                break;
            }
            cout << "Enter a valid number of lines (1-3)" << endl;
            continue;
        }
        else
        {
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

// 3)

int MAX_BET = 100;
int MIN_BET = 1;

int get_bet()
{
    int amount;
    while (true)
    {
        cout << "What would you like to bet?";
        cin >> amount;
        if (amount)
        {
            if (MIN_BET <= amount && amount <= MAX_BET)
            {
                break;
            }
            else
            {
                cout << "Amount must be between " + to_string(MIN_BET) + "-" + to_string(MAX_BET) << endl;
                continue;
            }
        }
    }
    return amount;
}

int ROWS = 3;
int COLS = 3;

int symbols_count[4][2] = {{'A', 2}, {'B', 4}, {'C', 6}, {'D', 8}};
// 4)

string convert_hash_to_str(int hash)
{
    if (hash == 65)
    {
        return "A";
    };
    if (hash == 66)
    {
        return "B";
    };
    if (hash == 67)
    {
        return "C";
    };
    if (hash == 68)
    {
        {
            return "D";
        }
    };
    return "";
}

vector<vector<string>> get_slot_machine_spin(int rows, int cols, int symbols[4][2])
{
    vector<string> all_symbols = {};
    for (int i = 0; i < (sizeof(symbols_count) / sizeof(symbols_count[0])); i++)
    {
        string symbol = to_string(symbols[i][0]);
        int count = stoi(to_string(symbols[i][1]));
        // stoi converts string to int
        for (int j = 0; j < count; j++)
        {
            all_symbols.push_back(symbol);
        }
    }
    for (int i = 0; i < all_symbols.size(); i++)
    {
        all_symbols[i] = convert_hash_to_str(stoi(all_symbols[i]));
    }
    vector<vector<string>> columns = {};
    for (int i = 0; i < cols; i++)
    {
        vector<string> column = {};
        vector<string> current_symbols = all_symbols;
        for (int j = 0; j < rows; j++)
        {
            shuffle(current_symbols.begin(), current_symbols.end(), random_device());
            string value = current_symbols[current_symbols.size() - 1];
            current_symbols.pop_back();
            column.push_back(value);
        }
        columns.push_back(column);
    }
    cout << columns[0][0] << columns[0][1] << columns[0][2] << endl;
    cout << columns[1][0] << columns[1][1] << columns[1][2] << endl;
    cout << columns[2][0] << columns[2][1] << columns[2][2] << endl;
    return columns;
};

int main()
{
    int balance = deposit();
    while (true)
    {
        cout << "Current balance is $" + to_string(balance) << endl;
        string answer;
        cout << "Type 'enter' to play or 'q' to quit. ";
        cin >> answer;
        if (answer == "q")
        {
            cout << "You entered q" << endl;
            break;
        }
        else
        {
            vector<vector<string>> columns = get_slot_machine_spin(ROWS, COLS, symbols_count);
            // balance += spin(balance);
        }
    }
    cout << "You left with $" + to_string(balance) << endl;
    return 0;
}