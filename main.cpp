#include <iostream>

using namespace std;

// 3 users stored in arrays
string names[3] = {"Malcom", "Lerato", "Ricia"};
int accountNumbers[3] = {1004, 1005, 1006};
int pins[3] = {1234, 1111, 2468};
double balances[3] = {500.00, 1000.00, 250.00};

void displayMenu()
{
    cout <<"------------------------------"<<endl;
    cout << "======== GCC BANK ========"<<endl;
    cout <<"------------------------------"<<endl;
    cout << "1. Deposit"<<endl;
    cout << "2. Withdraw"<<endl;
    cout << "3. Send Cash"<<endl;
    cout << "4. Check Balance"<<endl;
    cout << "5. Exit"<<endl;
    cout << "Enter choice: ";
}

double deposit(double balance, double amount) {
    if (amount <= 0) {
        cout << "Invalid amount. Must be more than 0."<<endl;
        return balance;
    }
    balance += amount;
    cout << "Deposit successful. New balance: R" << balance << endl;
    return balance;
}

double withdraw(double balance, double amount) {
    if (amount <= 0)
    {
      cout << "Invalid amount. Must be more than 0."<<endl;
        return balance;
    }

    if (amount > balance) {
        cout << "Insufficient funds. You cannot withdraw more than your balance."<<endl;
        return balance;
    }
    balance -= amount;
    cout << "Withdrawal successful. New balance: R" << balance << endl;
    return balance;
}

void checkBalance(double balance) {
    cout << "Your current balance is: R" << balance << endl;
}
void sendCash(int senderIndex, int recipientIndex, double amount) {
    if (amount <= 0) {
        cout << "Invalid amount." << endl;
        return;
    }
    if (amount > balances[senderIndex]) {
        cout << "Insufficient funds." << endl;
        return;
    }
    balances[senderIndex] -= amount;
    balances[recipientIndex] += amount;
    cout << "Send Cash successful to " << names[recipientIndex] << "." << endl;
    cout << "Your new balance: R" << balances[senderIndex] << endl;
}

int findAccount(int accNo) {
    for (int i = 0; i < 3; i++) {
        if (accountNumbers[i] == accNo)
            {
            return i;
            }
    }
    return -1;
}

int main() {
    int accNo, pin;
    cout << "Welcome to GCC BANK" <<endl;
    cout << "Enter account number: ";
    cin >> accNo;
    cout << "Enter PIN: ";
    cin >> pin;

    int userIndex = findAccount(accNo);

    if (userIndex == -1 || pins[userIndex] != pin) {
        cout << "Invalid account number or PIN."<<endl;
        return 0;
    }

    cout << "Welcome, " << names[userIndex] << "!" <<endl;

    int choice;
    double amount;
    do {
        displayMenu();
        cin >> choice;

    switch (choice) {
         case 1:
            cout << "Enter amount to deposit: R";
            cin >> amount;
            balances[userIndex] = deposit(balances[userIndex], amount);
            break;
         case 2:
            cout << "Enter amount to withdraw: R";
            cin >> amount;
            balances[userIndex] = withdraw(balances[userIndex], amount);
            break;
         case 3:
          {
        int recipientAcc;
        cout << "Enter recipient account number: ";
        cin >> recipientAcc;
        int recipientIndex = findAccount(recipientAcc);

    if (recipientIndex == -1) {
        cout << "Recipient account does not exist." << endl;
    } else if (recipientIndex == userIndex) {
        cout << "You cannot send cash to yourself." << endl;
    } else {
        cout << "Enter amount to send: R";
        cin >> amount;
        sendCash(userIndex, recipientIndex, amount);
    }
    break;
    }

        case 4:
                checkBalance(balances[userIndex]);
                break;
        case 5:
                cout << "Thank you for banking with GCC BANK. Goodbye!"<<endl;
                break;
            default:
                cout << "Invalid choice. Please choose 1-5."<<endl;
                break;
        }
    } while (choice != 5);

    return 0;
}

