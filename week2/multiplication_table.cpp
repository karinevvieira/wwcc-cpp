#include <iostream>
#include <iomanip>  // For setw()
using namespace std;

int main() {
    int start, end;

    cout << "Multiplication Table Generator" << endl << endl;
    // 1. Ask the user for a starting number
    cout << "Enter starting number: ";
    cin >> start;
    // 2. Ask the user for an ending number
    cout << "Enter ending number: ";
    cin >> end;
    // 3. Check if the starting number is less than the ending number. If not, display an error message. 
    if (start > end) {
        cout << "Error: Starting number must be less than ending number." << endl;
        return 1;
    }

    cout << endl;

    // Your code here
    // Include the column header showing the numbers being multiplied
    cout << "    " << "|"; // Initial spacing for the top-left corner
    for (int h = start; h <= end; h++) {
        cout << setw(4) << h << "|"; // Format the output for better alignment
    }
    cout << endl;

    // Include a separator line after the column header
    cout << "----|"; // Separator for the top-left corner
    for (int s = start; s <= end; s++) {
        cout << "----|"; // Separator for each column
    }
    cout << endl;

    // Generate a multiplication table from the starting number to the ending number
    for (int i = start; i <= end; i++) {
            cout << setw(4) << i << "|"; // Row header for the current number
        for (int j = start; j <= end; j++) {
            cout << setw(4) << i * j << "|"; // Format the output for better alignment
        }
        cout << endl; // Move to the next line after each row
    }

    return 0;
}