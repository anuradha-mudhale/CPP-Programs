#include <iostream>
using namespace std;

class MyBank {
private:
    double balance; 
public:
    MyBank() : balance(0.0) {}
void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Successfully deposited Rs." << amount << ".\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Successfully withdrawn Rs." << amount << ".\n";
        } else if (amount > balance) {
            cout << "Insufficient balance.\n";
        } else {
            cout << "Invalid withdrawal amount.\n";
        }
    }

   
    void displayBalance() {
        cout << "Current balance: Rs." << balance << ".\n";
    }
};


int main() {
    MyBank bank; 
    int choice;
    double amount;

    cout << "Welcome to OOP Bank!\n";

    do {
        
        cout << "\n1] Deposit Amount\n2] Withdraw Amount\n3] Display Balance\n4] Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
                cout << "Enter the deposit amount: ";
                cin >> amount;
                bank.deposit(amount);
                break;

            case 2: 
                cout << "Enter the withdrawal amount: ";
                cin >> amount;
                bank.withdraw(amount);
                break;

            case 3: 
                bank.displayBalance();
                break;

            case 4:
                cout << "Thank you for using OOP Bank. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

