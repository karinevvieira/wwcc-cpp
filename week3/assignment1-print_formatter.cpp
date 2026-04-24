#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

// Proper function prototypes (declarations)
string format(int);
string format(double);
string format(double, int);
string format(string);

// Functions Implementations
string format(int num) {
    string convertString = to_string(num); // Convert the integer to a string
    bool isNegative = false; // This will be used to handle negative numbers

    if (num < 0) {
        isNegative = true;
        convertString.erase(0, 1); // If the number is negative, remove the - sign to put the commas in the correct spot
    }

    int length = convertString.length(); // Grab the length of the string to know where to insert the commas

    // Get the length value subtract 3 (starting in the end) and as long as that value is greater than 0, keep inserting commas every 3 digits
    for (int i = length - 3; i > 0; i -= 3) {
        convertString.insert(i, ",");
    }

    if (isNegative == true) {
        convertString.insert(0, "-"); // If the number is negative, add the negative sign back to the front of the string
    }

    return convertString;
}

string format(double num) {
    stringstream ss; // This makes it easier to format the double with the fixed and setprecision manipulators
    ss << fixed << setprecision(2) << num; // fixed works with setprecision to set the number of decimal places, in this case 2
    return ss.str(); // convert the stringstream to a string and return it
}

string format(double num, int decimalPlaces) {
    stringstream ss;
    ss << fixed << setprecision(decimalPlaces) << num;
    return ss.str(); // The same logic as the one above but this time without a set precision, instead using a parameter.
}

string format(string str) {
    if (str.empty()) { // Handles the case of an empty string input
        return "";
    }

    stringstream ss(str); // This handles whitespace and allows us to extract each word from the string
    string word;
    string formattedString = ""; // Start with an empty string and rewrite it in the formatted form

    while (ss >> word) {
        if (!word.empty()) {
            word[0] = toupper(word[0]); // Handles each word as an array of characters and capitalizes the first character of each word [0]
        }
         formattedString += word + " ";
    }

    return formattedString;
}

int main() {
    int int1 = 9512898;
    double double1 = -3.648745;
    string string1 = "hello world of c++ programming";
    int decimalPlaces = 3;

    // Integer formatting function
    cout << "Integer formatting:" << endl;
    cout << "Original: " << int1 << endl;
    cout << "Formatted: " << format(int1) << endl << endl; 

    // Double formatting function (default 2 decimal places)
    cout << "Double formatting (default 2 decimal places):" << endl;
    cout << "Original: " << double1 << endl;
    cout << "Formatted: " << format(double1) << endl << endl; 
    

    // Double formatting function (custom decimal places)
    cout << "Double formatting (" << decimalPlaces << "):" << endl;
    cout << "Original: " << double1 << endl;
    cout << "Formatted: " << format(double1, decimalPlaces) << endl << endl; 

    // String formatting function
    cout << "String formatting:" << endl;
    cout << "Original: " << string1 << endl;
    cout << "Formatted: " << format(string1) << endl << endl; 

    return 0;
}
