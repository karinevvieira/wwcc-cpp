#include <iostream>
#include <cmath> // For sqrt() and pow() functions
#include <iomanip> // For setprecision() function

using namespace std;

// Declare a function named calculateDistance
// Takes four parameters (all doubles)
// Returns a double representing the calculated distance
double calculateDistance(double x1, double y1, double x2, double y2) {
   return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Bonus Challenge: Add a second function called calculateMidpoint:
void calculateMidpoint(double x1, double y1, double x2, double y2) {
    double midpointX = (x1 + x2) / 2;
    double midpointY = (y1 + y2) / 2;
    cout << "The midpoints between (" << x1 << ", " << x2 << ") and (" << y1 << ", " << y2 << ") are: (" ;
    cout << fixed << setprecision(2) << midpointX << ", " << fixed << setprecision(2) << midpointY << ")" << endl;
    // This one might be wrong but I could not figure out how to format this better
    // For some reason my output is showing the coordinates with decimal points 
}

// Prompt the user to enter the coordinates of two points
int main() {
    double x1, y1, x2, y2;
    // First point 
    cout << "Enter the coordinates of the first point: " << endl;
    cout << "x1: ";
    cin >> x1;
    cout << "y1: ";
    cin >> y1;

    // secomd point
    cout << "Enter the coordinates of the second point: " << endl;
    cout << "x2: ";
    cin >> x2;
    cout << "y2: ";
    cin >> y2;

    // Call the function with these coordinates and display the distance
    double distance = calculateDistance(x1, y1, x2, y2);
    // Format the output to show exactly 2 decimal places (based on the example output in the instructions)
    cout << "The distance between (" << x1 << ", " << y1 << ") and (" << x2 << ", " << y2 << ") is: " << fixed << setprecision(2) << distance << endl;
    // Bonus Challenge: Call the calculateMidpoint function
    calculateMidpoint(x1, y1, x2, y2); // 
    
    return 0;
}