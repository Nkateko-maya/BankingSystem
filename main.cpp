
#include <iostream>
#include <string>
using namespace std;

// ------------------ User data (arrays) ----------------------
const int MAX_USERS = 3;

string names[MAX_USERS]        = {"Thabo Mokoena", "Lerato Dlamini", "Sipho Nkosi"};
string accountNumbers[MAX_USERS] = {"246811", "369122", "481215"};
int    pins[MAX_USERS]         = {1234, 5678, 9012};
double balances[MAX_USERS]     = {2500.00, 1500.00, 500.00};

//---------------------- Function prototypes ------------------
void displayMenu();
int  findAccountIndex(string accNumber);
bool loginUser(int &loggedInIndex);
void deposit(int userIndex);
void withdraw(int userIndex);
void sendCash(int userIndex);
void checkBalance(int userIndex);

//---------------------- MAIN FUNCTION ------------------------
int main() {
    int choice;
    int loggedInIndex = -1;

    cout << "===========================================\n";
    cout << "            WELCOME TO GCC BANK\n";
    cout << "===========================================\n";

    // Login first: program repeats until a correct acc + PIN is given
    if (!loginUser(loggedInIndex)) {
        cout << "Too many wrong attempts. Program ending.\n";
        return 0;
    }

    // Menu loop: keeps running until the user chooses Exit (5)
    do {
        displayMenu();
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            // Validation for non-numeric input
            cout << "Invalid input! Please enter a number 1 - 5.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1: deposit(loggedInIndex);
             break;

            case 2: withdraw(loggedInIndex);
             break;

            case 3: sendCash(loggedInIndex);
             break;

            case 4: checkBalance(loggedInIndex);
             break;

            case 5: cout << "Thank you for banking with GCC Bank. Goodbye!"<<endl;
             break;

            default: cout << "Invalid choice! Please choose 1 - 5."<<endl;
        }

        cout << endl;
    } while (choice != 5);

    return 0;
}

//---------------------- FUNCTION DEFINITIONS -----------------

// Shows the banking menu
void displayMenu() {
    cout << "================ GCC BANK ================"<<endl;
    cout << "1. Deposit"<<endl;
    cout << "2. Withdraw"<<endl;
    cout << "3. Send Cash"<<endl;
    cout << "4. Check Balance"<<endl;
    cout << "5. Exit"<<endl;
}

// Finds the position of an account number in the arrays.
// Returns the index if found, otherwise returns -1.
int findAccountIndex(string accNumber) {
    for (int i = 0; i < MAX_USERS; i++) {
        if (accountNumbers[i] == accNumber) {
            return i;
        }
    }
    return -1;
}

// Asks for account number and PIN. On success the index of the
// logged-in user is stored in loggedInIndex and true is returned.
bool loginUser(int &loggedInIndex) {
    string accNumber;
    int pin;

    for (int attempts = 1; attempts <= 3; attempts++) {
        cout << "Enter your account number : "<<endl;
        cin >> accNumber;
        cout << "Enter your PIN: "<<endl;
        cin >> pin;

        int index = findAccountIndex(accNumber);
        if (index != -1 && pins[index] == pin) {
            loggedInIndex = index;
            cout << "\nWelcome back, " << names[index] << "!"<<endl;
            return true;
        } else {
            cout << "Wrong account number or PIN. (" << attempts << "/3 attempts)"<<endl;
        }
    }
    return false;
}

// Adds money to the account. Amount must be more than 0.
void deposit(int userIndex) {
    double amount;
    cout << "Enter the amount you want to deposit: R";
    cin >> amount;

    if (amount <= 0) {
        cout << "Invalid amount! You can only deposit more than R0."<<endl;
    } else {
        balances[userIndex] += amount;
        cout << "Deposit successful! R" << amount
             << " added to your account."<<endl;
    }
}

// Removes money from the account. Cannot withdraw more than balance.
void withdraw(int userIndex) {
    double amount;
    cout << "Enter the amount you want to withdraw: R"<<endl;
    cin >> amount;

    if (amount <= 0) {
        cout << "Invalid amount! You must withdraw more than R0."<<endl;
    } else if (amount > balances[userIndex]) {
        cout << "Insufficient funds! Your balance is R"<<endl;
        cout << balances[userIndex] << "\n";
    } else {
        balances[userIndex] -= amount;
        cout << "Withdrawal successful! Please collect your R" << amount << ".\n";
    }
}

// Transfers money to another account. Checks the recipient exists
// and that the sender has enough balance.
void sendCash(int userIndex) {
    string recipientAcc;
    double amount;

    cout << "Enter the recipient's account number: ";
    cin >> recipientAcc;

    int recipientIndex = findAccountIndex(recipientAcc);

    if (recipientIndex == -1) {
        cout << "That account does not exist!\n";
        return;
    }

    if (recipientIndex == userIndex) {
        cout << "You cannot send money to your own account!\n";
        return;
    }

    cout << "Sending to: " << names[recipientIndex] << "\n";
    cout << "Enter the amount to send: R";
    cin >> amount;

    if (amount <= 0) {
        cout << "Invalid amount! You must send more than R0.\n";
    } else if (amount > balances[userIndex]) {
        cout << "Insufficient funds! Your balance is R"
             << balances[userIndex] << "\n";
    } else {
        balances[userIndex] -= amount;
        balances[recipientIndex] += amount;
        cout << "Success! R" << amount << " sent to "
             << names[recipientIndex] << ".\n";
    }
}

// Displays the current balance
void checkBalance(int userIndex) {
    cout << "Your current balance is: R" << balances[userIndex] << "\n";
}



