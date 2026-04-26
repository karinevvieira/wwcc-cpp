#include <iomanip>
#include <iostream>

using namespace std;

/*  Function to Convert Dollar to Euro */
double dollarToEuro(double amount) {
    double exchangeRate = 0.85; 
    return amount * exchangeRate;
}
/*  Function to convert Dollar to British Pound */
double DollarToPound(double amount){
    double exchangeRate = 0.74; 
    return amount * exchangeRate;
}
/*  Function to convert Dollar to Yen */
double dollarToYen(double amount) {
    double exchangeRate = 110.33; 
    return amount * exchangeRate;
}
/*  Function to get the count of the static variable in each iteration of the program 
    A static variable will not reset to its original value in each iteration, so as long as the program runs it will keep increasing */
int getConversionCount() {
    static int conversionCount = 0; 
    return ++conversionCount;
}
/*  Function to prompt the user if they want to continue with another conversion or not 
    Handle a response different from the ones expected on the else statement */
bool yesOrNo() {
    char response;

    while (true) {
        cout << "Would you like to perform another conversion? (y/n): ";
        cin >> response;
        cout << endl;

        if (response == 'y' || response == 'Y') {
            return true;
        } else if (response == 'n' || response == 'N') {
            return false;
        } else {
            cout << "Invalid input. Please enter 'y' for yes or 'n' for no." << endl;
        }
    }
}
/*  Do-while will execute at least once the menu 
    The Function handles wrong input with the else statement
    The YesOrNo function comes up after the user chose one of the 3 conversion options but not in the other cases
    Only shows 2 decimal places as per instructions  
    Added some extra lines for a cleaner output (Maybe a bit too much?!)*/
int main() {
    double amount;
    int choice;
    
    do {
        cout << "-------------------" << endl;
        cout << "CURRENCY CONVERTER" << endl;
        cout << "-------------------" << endl;
        cout << "1. Convert USD to Euro (EUR)" << endl;
        cout << "2. Convert USD to British Pound (GBP)" << endl;
        cout << "3. Convert USD to Japanese Yen (JPY)" << endl;
        cout << "4. Exit" << endl << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter amount in USD: ";
            cin >> amount;
            cout << fixed << setprecision(2) << amount << " USD = " << dollarToEuro(amount) << " EUR" << endl << endl;
            cout << "Number of conversions performed: " << getConversionCount() << endl << endl;
            if (yesOrNo() == false) {
                cout << "Exiting Program..." << endl << endl;
                break;
            }
        }
        else if (choice == 2) {
            cout << "Enter amount in USD: ";
            cin >> amount;
            cout << fixed << setprecision(2) << amount << " USD = " << DollarToPound(amount) << " GBP" << endl << endl;
            cout << "Number of conversions performed: " << getConversionCount() << endl << endl;
            if (yesOrNo() == false) {
                cout << "Exiting Program..." << endl << endl;
                break;
            }
        }
        else if (choice == 3) {
            cout << "Enter amount in USD: ";
            cin >> amount;
            cout << fixed << setprecision(2) << amount << " USD = " << dollarToYen(amount) << " JPY" << endl << endl;
            cout << "Number of conversions performed: " << getConversionCount() << endl << endl;
            if (yesOrNo() == false) {
                cout << "Exiting Program..." << endl << endl;
                break;
            }
        }
        else if (choice == 4) {
            cout << "Exiting Program..." << endl << endl;
            break;
        }
        else {
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl << endl;
        }
    } while (choice != 4);

    cout << "Thank you for using the currency converter!" << endl << endl;

    return 0;
}
