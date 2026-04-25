#include <iostream>
#include <iomanip> 

using namespace std;

/*  Takes a temperature value as its first parameter
    Takes a character indicating the source unit ('C' for Celsius, 'F' for Fahrenheit, 'K' for Kelvin)
    Uses three pass-by-reference parameters to return the temperature in all three units (Celsius, Gahrenheit, and Kelvin)
    Handles invalid input for the unit, only allowing ('C', 'F', or 'K')
*/
void convertTemperature(double temp, char unit, float &c, float &f, float &k) {

    switch (unit) {
        case 'C':
            c = temp;
            f = (temp * 9 / 5) + 32;
            k = temp + 273.15;
            break;
        case 'F':
            c = (temp - 32) * 5 / 9;
            f = temp;
            k = c + 273.15;
            break;
        case 'K':
            c = temp - 273.15;
            f = (c * 9 / 5) + 32;
            k = temp;
            break;
        default:
            cout << "Invalid unit. Please use C, F, or K." << endl;
            return;
    }

    /*  The output displays only two decimal places for the converted temperatures.
        This was the only way I found to display the degree symbol (°) in the output, using the ASCII code 248.
    */
    cout << fixed << setprecision(2);
    cout << "Celsius: " << c << (char)248 << "C" << endl;
    cout << "Fahrenheit: " << f << (char)248 << "F" << endl;
    cout << "Kelvin: " << k << "K" << endl; // Kelvin scale does not use the degree symbol
}

/*  Prompt the user to enter a temperature value and its unit
    Call the convertTemperature() function
    Display the temperature in all three units
*/
int main() {
    double temp;
    char unit;
    float c, f, k;

    cout << "Enter a temperature value: " << endl;
    cin >> temp;

    cout << "Enter the unit (C for Celsius, F for Fahrenheit, K for Kelvin): " << endl;
    cin >> unit;

    cout << "Temperature Conversions: " << endl;
    convertTemperature(temp, unit, c, f, k);

    return 0;
}