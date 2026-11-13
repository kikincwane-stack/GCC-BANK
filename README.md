# GCC-BANK
GCC BANK Banking system in C++ -Login with account number &amp; Pin, Deposit, Withdraw, Send Cash &amp; Check Balance. Built for computer Programming NQF level 4. 

# GCC BANK - Banking System in C++

**Student Name:** Patricia Ncwane  
**Student Number:** 0705271479085  
**Lecturer:** Mr Owami  
**Module:** Computer Programming - NQF Level 4  
**Due Date:** 20 November 2026

## Description of Program

This program is a simple Banking System for GCC BANK. It allows a user to log in with an account number and PIN, then choose from a menu to Deposit, Withdraw, Send Cash, Check Balance, or Exit.

The program stores 3 users using arrays for names, account numbers, PINs, and balances. It uses a `do-while` loop to keep showing the menu until the user chooses Exit. It uses `switch-case` for menu choices and `if-else` for validation.

## Features

1. **Login** - User logs in with account number and PIN
2. **Deposit** - Add money to your account
3. **Withdraw** - Remove money from your account
4. **Send Cash** - Send money to another account
5. **Check Balance** - View your current balance
6. **Exit** - Close the program

## Validation

Validation is done to make sure:

1. Deposit amount must be more than 0.
2. Withdrawal amount must be more than 0 and cannot be more than the balance.
3. Send Cash checks if the recipient account exists, checks if there is enough balance, then updates both accounts.

## Functions Used

1. `displayMenu()` - Shows the menu
2. `deposit(balance, amount)` - Adds money and returns new balance
3. `withdraw(balance, amount)` - Removes money if enough balance and returns new balance
4. `checkBalance(balance)` - Displays the current balance
5. `findAccount(accNo)` - Searches the array and returns the user position, or -1 if not found

## Test Accounts to Use

| Name | Account | PIN | Balance |
| Malcom | 1004 | 1234 | R500 |
| Lerato | 1005 | 1111 | R1000 |
| Ricia | 1006 | 2468 | R250 |

## How to Run the Program

### Option 1: Using Visual Studio Code
1. Open the project folder in Visual Studio Code
2. Open the `.cpp` file
3. Click **Run > Run Without Debugging** or press `Ctrl + F5`

### Option 2: Using Terminal / Command Prompt
```bash
g++ main.cpp -o bank
./bank
