#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Account {
private:
    string accountNumber;
    string pin;
    double balance;
    vector<string> transactionHistory;

    void logTransaction(const string& transaction) {
        transactionHistory.push_back(transaction);
    }

public:
    Account(const string& accNum, const string& pinCode, double initialBalance)
        : accountNumber(accNum), pin(pinCode), balance(initialBalance) {}

    bool authenticate(const string& pinCode) {
        return pin == pinCode;
    }

    void checkBalance() const {
        cout << fixed << setprecision(2);
        cout << "Your current balance is: $" << balance << endl;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            logTransaction("Deposited: $" + to_string(amount));
            cout << "Successfully deposited $" << amount << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            logTransaction("Withdrew: $" + to_string(amount));
            cout << "Successfully withdrew $" << amount << endl;
            return true;
        } else {
            cout << "Insufficient funds or invalid amount." << endl;
            return false;
        }
    }

    bool transfer(Account& recipient, double amount) {
        if (withdraw(amount)) {
            recipient.deposit(amount);
            logTransaction("Transferred: $" + to_string(amount) + " to account " + recipient.accountNumber);
            recipient.logTransaction("Received: $" + to_string(amount) + " from account " + accountNumber);
            return true;
        }
        return false;
    }

    void showTransactionHistory() const {
        cout << "\nTransaction History:\n";
        for (const auto& transaction : transactionHistory) {
            cout << transaction << endl;
        }
        cout << endl;
    }
};

void displayMenu() {
    cout << "\n--- ATM Simulator Menu ---" << endl;
    cout << "1. Check Balance" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Transfer" << endl;
    cout << "5. View Transaction History" << endl;
    cout << "6. Exit" << endl;
    cout << "Choose an option (1-6): ";
}

int main() {
    Account myAccount("1234567890", "1234", 5000.00);
    Account otherAccount("0987654321", "4321", 3000.00);

    string enteredPin;
    int option;
    double amount;

    cout << "Welcome to the ATM Simulator!" << endl;
    cout << "Please enter your PIN: ";
    cin >> enteredPin;

    if (!myAccount.authenticate(enteredPin)) {
        cout << "Invalid PIN. Access Denied." << endl;
        return 1;
    }

    while (true) {
        displayMenu();
        cin >> option;

        switch (option) {
            case 1:
                myAccount.checkBalance();
                break;
            case 2:
                cout << "Enter deposit amount: $";
                cin >> amount;
                myAccount.deposit(amount);
                break;
            case 3:
                cout << "Enter withdrawal amount: $";
                cin >> amount;
                myAccount.withdraw(amount);
                break;
            case 4:
                cout << "Enter amount to transfer: $";
                cin >> amount;
                if (myAccount.transfer(otherAccount, amount)) {
                    cout << "Transfer successful." << endl;
                } else {
                    cout << "Transfer failed." << endl;
                }
                break;
            case 5:
                myAccount.showTransactionHistory();
                break;
            case 6:
                cout << "Thank you for using the ATM Simulator. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }
}
