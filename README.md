# GCC Bank - Console Banking System

A simple command-line banking application written in **C++**. It simulates an ATM-style experience: users log in with an account number and PIN, then can deposit, withdraw, transfer money to other accounts, and check their balance.

This project is great for learning core C++ concepts such as arrays, functions, loops, input validation, and pass-by-reference.

## Features

- **Secure login** with account number and PIN (3 attempts max)
- **Deposit** money into your account
- **Withdraw** money (with insufficient funds check)
- **Send cash** to another account holder
- **Check balance** at any time
- **Input validation** for menu choices, amounts, and recipient accounts


## Requirements

- A C++ compiler that supports C++11 or later (e.g. `g++`, `clang++`, MSVC)


## Getting Started

### 1. Clone the repository

```bash
git clone https://github.com/<your-username>/<your-repo-name>.git
cd <your-repo-name>
```

### 2. Compile

```bash
g++ main.cpp -o gcc_bank
```

### 3. Run

```bash
./gcc_bank        # Linux / macOS
gcc_bank.exe      # Windows
```



## Demo Accounts

Use these test accounts to try out the program:

| Name            | Account Number | PIN  | Starting Balance |
|-----------------|----------------|------|------------------|
| Thabo Mokoena   | 246811         | 1234 | R2500.00         |
| Lerato Dlamini  | 369122         | 5678 | R1500.00         |
| Sipho Nkosi     | 481215         | 9012 | R500.00          |


## How It Works

1. **Login** - Enter your account number and PIN. After 3 failed attempts, the program exits.
2. **Menu** - Choose an option from the main menu:

```
================ GCC BANK ================
1. Deposit
2. Withdraw
3. Send Cash
4. Check Balance
5. Exit
```

3. **Transactions** - Follow the prompts. The program validates that:
   - Amounts are greater than R0
   - You have enough funds for withdrawals and transfers
   - The recipient account exists
   - You can't send money to your own account

---

## Project Structure

```
.
├── main.cpp      # All source code
└── README.md     # Project documentation
```

### Key Functions

| Function             | Description                                              |
|----------------------|----------------------------------------------------------|
| `displayMenu()`      | Prints the main banking menu                             |
| `findAccountIndex()` | Looks up an account number and returns its array index   |
| `loginUser()`        | Handles login with up to 3 attempts                      |
| `deposit()`          | Adds funds to the logged-in account                      |
| `withdraw()`         | Removes funds, checking the balance first                |
| `sendCash()`         | Transfers money between two accounts                     |
| `checkBalance()`     | Displays the current balance                             |

---

## License

This project is open source and available under the [MIT License](LICENSE).

---

## Author

Made by Nkateko Ndala
