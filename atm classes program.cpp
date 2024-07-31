#include <iostream>
#include <string>
using namespace std;

class ATM 
{
private:
    double balance;
    string pin;
    bool loggedIn;

public:
    ATM(double initialBalance = 100000.0) : balance(initialBalance), loggedIn(false) {}
    ~ATM() {}

    void login() 
	{
        cout << "Please enter your pin: ";
        cin >> pin;
        loggedIn = (pin == "0987");
        if (!loggedIn)
	    {
            cout << "Incorrect pin. Try again." << endl;
            login(); 
        }
    }

    void displayMenu() 
	{
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
    void checkBalance()
	 {
        cout << "Your balance is: RS " << balance << endl;
    }
    void withdrawMoney() 
	{
        double amount;
        cout << "Enter the amount to withdraw: RS ";
        cin >> amount;
        if (amount > balance)
		 {
            cout << "Insufficient funds. Withdrawal failed." << endl;
        } else 
	{
            balance -= amount;
            cout << "Withdrawal successful. Remaining balance: RS " << balance << endl;
        }
    }
    void depositMoney()
	 {
        double amount;
        cout << "Enter the amount to deposit: RS ";
        cin >> amount;
        if (amount < 0)
		 {
            cout << "Invalid amount. Deposit failed." << endl;
        } else
	{	
            balance += amount;
            cout << "Deposit successful. Updated balance: RS " << balance << endl;
        }
    }
};
int main() 
{
    ATM atm;
    atm.login();
    atm.operate();
    return 0;
}
