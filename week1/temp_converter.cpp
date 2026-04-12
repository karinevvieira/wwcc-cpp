#include <iostream>

using namespace std;

int main() {
    double temperature;
    char unit;
    double result;

    cout << "Temperature Converter" << endl;

    cout << "Enter temperature value: ";
    cin >> temperature;

    //Get the unit (C or F)
    cout << "Enter unit (C for Celsius, F for Fahrenheit): ";
    cin >> unit;

    //Perform conversion based on the unit entered
    if (unit == 'C' || unit == 'c') {
        // Celsius to Fahrenheit
        result = (temperature * 9 / 5) + 32;
        cout << temperature << "C is equal to " << result << "F" << endl;
    } 
    else if (unit == 'F' || unit == 'f') {
        //Fahrenheit to Celsius
        result = (temperature - 32) * 5 / 9;
        cout << temperature << "F is equal to " << result << "C" << endl;
    } 
    else {
        //Handle unexpected input
        cout << "That is not a valid unit. Please use C or F." << endl;
    }

    return 0;
}