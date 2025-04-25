#include <iostream>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    string accountType;
    double balance;

public:
    BankAccount() {
        accountHolder = "Unknown";
        accountNumber = 0;
        accountType = "Savings";
        balance = 0.0;
    }
    BankAccount(string holder, int accNum, string type, double bal) {
        accountHolder = holder;
        accountNumber = accNum;
        accountType = type;
        balance = bal;
    }

    
    string getAccountHolder() { return accountHolder; }
    int getAccountNumber() { return accountNumber; }
    string getAccountType() { return accountType; }
    double getBalance() { return balance; }

    
    void setAccountType(string newType) {
        accountType = newType;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited " << amount << ". New Balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew " << amount << ". New Balance: " << balance << endl;
        } else {
            cout << "Insufficient balance or invalid amount!" << endl;
        }
    }

  
    void displayAccountDetails() {
        cout << "\nAccount Details:\n";
        cout << "Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Type: " << accountType << endl;
        cout << "Balance: " << balance << endl;
    }
};


int main() {
    
    BankAccount acc1;
    acc1.displayAccountDetails();
    BankAccount acc2("Amar Patil", 123456, "Savings", 5000.00);
    acc2.displayAccountDetails();

    cout << "\nDepositing 2000...\n";
    acc2.deposit(2000);

    cout << "\nWithdrawing 1500...\n";
    acc2.withdraw(1500);


    cout << "\nUpdating Account Type to Current...\n";
    acc2.setAccountType("Current");

    acc2.displayAccountDetails();

    return 0;
}

