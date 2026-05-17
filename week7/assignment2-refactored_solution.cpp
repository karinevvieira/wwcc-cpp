#include <iostream>
#include <iomanip>

using namespace std;

/* Changes I made here:
    Proper encapsulation, private for the class members and public for the methods
    More descriptive member variable names: customerName(accountOwner), money(currentBalance), open(isOpen), acc_number(accountNumber), type(accountType)
    Added constants for the interest rates of each account type, this way it is easier to handle the interest calculation and it is more readable
    I used all uppercase for the constants to make it clear that they are constants and should not be modified
*/
class Account {
private:
    string accountOwner;
    double currentBalance;
    bool isOpen;
    int accountNumber;
    string accountType;

    const double SAVINGS_INTEREST_RATE = 0.03; // 3% interest for savings accounts
    const double CHECKING_INTEREST_RATE = 0.01; // 1% interest for checking accounts
    const double BUSINESS_INTEREST_RATE = 0.05; // 5% interest for business accounts

/*  Replaced the setup() method with a constructor 
    Added checks for negative deposits and withdrawals (Also made sure the user cannot withdraw more than the current balance in the account)
    The calculateInterest() method now uses the accountType to determine which interest rate to apply, and it updates the current balance
    I added a message when the calculateInterest() method is called to show the interest earned
    I added just some visual improvements to the displayAccountInfo() method to make it more organized and visually appealing
    The closeAccount() method now prints a message letting the user know the account has been closed
    The deposit and withdraw methods use better naming for the parameters and also print the current balance after the operation is performed
*/
public:
    // Constructor to initialize the account with the provided values
    Account(const string& owner, double balance, int accNumber, const string& type)
        : accountOwner(owner), currentBalance(balance), isOpen(true), accountNumber(accNumber), accountType(type) {
    }

    // Getter for account balance
    double getBalance() const {
        return currentBalance;
    }

    // Method to deposit money into the account
    void deposit(double amount) {
        if (amount > 0) {
            currentBalance += amount;
            cout << "Deposit of $" << amount << " successful. Current balance: $" << currentBalance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    // Method to withdraw money from the account
    void withdraw(double amount) {
        if (amount > 0 && amount <= currentBalance) {
            currentBalance -= amount;
            cout << "Withdrawal of $" << amount << " successful. Current balance: $" << currentBalance << endl;
        } 
        else {
            cout << "Invalid withdrawal amount or insufficient funds." << endl;
        }
    }

    // Method to calculate interest in different account types
    void calculateInterest() {
        double interestEarned;

        if (accountType == "savings") {
            interestEarned = currentBalance * SAVINGS_INTEREST_RATE;
        } 
        else if (accountType == "checking") {
            interestEarned = currentBalance * CHECKING_INTEREST_RATE;
        }
        else if (accountType == "business") {
            interestEarned = currentBalance * BUSINESS_INTEREST_RATE;
        }
        else {
            cout << "Unknown account type. No interest calculated." << endl;
            return;
        }

        cout << "Interest earned: $" << interestEarned << endl;
        currentBalance += interestEarned;
        cout << "Current balance after interest: $" << currentBalance << endl;
    }

    // Method to display account information
    void displayAccountInfo() const {
        cout << fixed << setprecision(2);
        cout << "\n-- Account Information --" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Customer Name: " << accountOwner << endl;
        cout << "Balance: $" << currentBalance << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Account Status: " << (isOpen ? "Open" : "Closed") << endl;
        cout << "-------------------------" << endl;
    }

    // Method to close the account
    void closeAccount() {
        isOpen = false;
        cout << "Account closed." << endl;
    }

};

/*  Made 3 different types of accounts so the test could run for all the interest rates and make sure it works correctly
    Used all of the methods created
    Displayed the account information in the beginning and the end to see the changes that were made
*/
int main() {
    // Savings account
    Account personalAccount1("William Williams", 1000.0, 12345678, "savings"); // Create a savings account
    personalAccount1.displayAccountInfo(); // Display initial account information
    personalAccount1.deposit(650.0); // Deposit money into the account
    personalAccount1.withdraw(400.0); // Withdraw money from the account
    personalAccount1.calculateInterest(); // Calculate interest for the savings account
    personalAccount1.displayAccountInfo(); // Display account information after transactions and interest calculation
    personalAccount1.closeAccount(); // Close the account

    // Checking account
    Account personalAccount2("Henry Madison", 1589.0, 98784532, "checking"); // Create a checking account
    personalAccount2.displayAccountInfo(); // Display initial account information
    personalAccount2.deposit(1000.0); // Deposit money into the account
    personalAccount2.withdraw(500.0); // Withdraw money from the account
    personalAccount2.calculateInterest(); // Calculate interest for the checking account
    personalAccount2.displayAccountInfo(); // Display account information after transactions and interest calculation
    personalAccount2.closeAccount(); // Close the account

    // Business account
    Account businessAccount("Tech Solutions Inc.", 5000.0, 24681357, "business"); // Create a business account
    businessAccount.displayAccountInfo(); // Display initial account information
    businessAccount.deposit(2000.0); // Deposit money into the account
    businessAccount.withdraw(1000.0); // Withdraw money from the account
    businessAccount.calculateInterest(); // Calculate interest for the business account
    businessAccount.displayAccountInfo(); // Display account information after transactions and interest calculation
    businessAccount.closeAccount(); // Close the account

    return 0;
}