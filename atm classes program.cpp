#include <iostream>
#include <string>
using namespace std;

class BankAccount {
protected:
    double balance;
    string accountNumber;

public:
    BankAccount(double initialBalance = 0.0, string accNumber = "") 
        : balance(initialBalance), accountNumber(accNumber) {}

    virtual ~BankAccount() {}

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. Updated balance: RS " << balance << endl;
        } else {
            cout << "Invalid amount. Deposit failed." << endl;
        }
    }

    virtual void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds. Withdrawal failed." << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal successful. Remaining balance: RS " << balance << endl;
        }
    }

    virtual void displayAccountInfo() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: RS " << balance << endl;
    }
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(double initialBalance = 0.0, string accNumber = "", double rate = 0.02) 
        : BankAccount(initialBalance, accNumber), interestRate(rate) {}

    void addInterest() {
        balance += balance * interestRate;
        cout << "Interest added. Updated balance: RS " << balance << endl;
    }

    virtual void displayAccountInfo() const override {
        BankAccount::displayAccountInfo();
        cout << "Interest Rate: " << interestRate * 100 << "%" << endl;
    }
};

class ATM : public BankAccount {
private:
    string pin;
    bool loggedIn;

public:
    ATM(double initialBalance = 100000.0, string accNumber = "0000") 
        : BankAccount(initialBalance, accNumber), loggedIn(false) {}

    virtual ~ATM() {}

    void login() {
        cout << "Please enter your pin: ";
        cin >> pin;
        loggedIn = (pin == "0987");
        if (!loggedIn) {
            cout << "Incorrect pin. Try again." << endl;
            login(); 
        }
    }

    void displayMenu() const {
        cout << "\nATM Menu:\n";
        cout << "1. Check Balance\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Deposit Money\n";
        cout << "4. Exit\n";
    }

    void operate() {
        while (loggedIn) {
            displayMenu();
            int choice;
            cout << "Enter your choice (1-4): ";
            cin >> choice;
            switch (choice) {
                case 1:
                    checkBalance();
                    break;
                case 2:
                    withdrawMoney();
                    break;
                case 3:
                    depositMoney();
                    break;
                case 4:
                    cout << "Thank you for using the ATM. Have a nice day!" << endl;
                    loggedIn = false;
                    break;
                default:
                    cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
            }
        }
    }

    void checkBalance() const {
        cout << "Your balance is: RS " << getBalance() << endl;
    }

    void withdrawMoney() {
        double amount;
        cout << "Enter the amount to withdraw: RS ";
        cin >> amount;
        withdraw(amount);
    }

    void depositMoney() {
        double amount;
        cout << "Enter the amount to deposit: RS ";
        cin >> amount;
        deposit(amount);
    }
};

int main() {
    SavingsAccount savings(50000.0, "12345");
    savings.addInterest();
    savings.displayAccountInfo();

    ATM atm;
    atm.login();
    atm.operate();

    return 0;
}
