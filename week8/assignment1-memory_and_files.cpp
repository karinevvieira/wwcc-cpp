#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

// Function Prototypes
void referenceDemonstration(int& changeByRef);
void pointerDemonstration(int& a);
void swapByReference(int &a, int &b);
void arrPointerRelationship(int* arr, int size);
void writeNotes(ofstream& out, const string& note);
void displayNotes(ifstream& file);
int findMax(int* arr, int size);

/*  I tried to keep main as clean as I could but I also did not want to complicate the code too much with separate functions
    Variables use 4 different data types (the instructions asked for at least 3)
    Calls all the functions, separates part 1 and part 2 clearly */
int main() {

    // Part 1: Memory and Addressing

    string movieTitle = "Inception";
    int releaseYear = 2010;
    double rating = 8.8;
    char oscarWinner = 'Y'; // Y for yes, N for no
    int a = 5, b = 10;
    int arr[5] = {10, 20, 30, 40, 50};

    cout << "=== PART 1: MEMORY AND ADDRESSING ===" << endl;
    cout << "\nVariable values and addresses:" << endl;
    cout << "string movieTitle = '" << movieTitle << "' at address " << &movieTitle << endl;
    cout << "int releaseYear = " << releaseYear << " at address " << &releaseYear << endl;
    cout << "double rating = " << rating << " at address " << &rating << endl;
    cout << "char oscarWinner = '" << oscarWinner << "' at address " << &oscarWinner << endl;

    cout << "\nReference demonstration:" << endl;
    referenceDemonstration(releaseYear);

    cout << "\nPointer demonstration:" << endl;
    pointerDemonstration(a);

    cout << "\nSwap Function (by reference):" << endl;
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    swapByReference(a, b);
    cout << "After swap: a = " << a << ", b = " << b << endl;

    cout << "\nArray-pointer relationship:" << endl;
    arrPointerRelationship(arr, 5);

    // Part 2: File Handling

    cout << "\n=== PART 2: FILE HANDLING ===" << endl;
    ofstream outFile("notes.txt", ios::app);

    if (!outFile) {
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }

    string note1, note2, note3;
    cout << "Enter note 1: ";
    getline(cin, note1);
    writeNotes(outFile, note1);

    cout << "Enter note 2: ";
    getline(cin, note2);
    writeNotes(outFile, note2);

    cout << "Enter note 3: ";
    getline(cin, note3);
    writeNotes(outFile, note3);

    outFile.close();

    cout << "Notes written to 'notes.txt' successfully." << endl;

    ifstream inFile("notes.txt");

    if (!inFile) {
    cerr << "Error opening file for reading!" << endl;
    return 1;
    }   

    displayNotes(inFile);
    inFile.close();

    return 0;
}

/* Function to demonstrate references by modifying the release year of a movie through a reference variable 
    Attributes changeByRef to the alias refX 
    Changes the value of the referenced variable 
*/
void referenceDemonstration(int& changeByRef) {
    int &refX = changeByRef; 

    cout << "Before : releaseYear = " << refX << endl;
    refX = 2020;
    cout << "After modifying through reference: releaseYear = " << refX << endl;
}

/* Function to demonstrate pointers by modifying the value of an integer through a pointer variable 
    Checks if the pointer is not null (nullptr)
    Displays the address and value before modification
    Modifies the value through the pointer and displays the new value
*/
void pointerDemonstration(int& a) {
    int* ptr = &a;

    if (ptr != nullptr) {
        cout << "Pointer stores address: " << ptr << endl;
        cout << "Value at that address: " << *ptr << endl;

        *ptr = 15;
        cout << "After modifying through pointer: a = " << a << endl;
    }
}

/* Function to swap two integers using references
    Swaps the values of the two referenced variables
    This is displayed in main before and after the swap to show the change
*/
void swapByReference(int &a, int &b) {
    int swap = a;
    a = b;
    b = swap;
}

/* Function to find the maximum value in an array using pointers
    Takes a pointer to the array and its size as arguments
    Returns the maximum value found
*/
int findMax(int* arr, int size) {
    int max = *arr;

    for (int i = 1; i < size; ++i) {
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
    }

    return max;
}

/* Function to demonstrate the relationship between arrays and pointers
    Takes a pointer to the array and its size as arguments
    Displays the elements of the array using both array indexing and pointer arithmetic
    Also calls the findMax function to display the maximum value in the array
*/
void arrPointerRelationship(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << "arr[" << i << "] = " << arr[i] << "  *(arr + " << i << ") = " << *(arr + i) << endl;
    }

    cout << "Maximum value (via pointer): " << findMax(arr, size) << endl;
}

/* Function to write notes to a file
    Takes an ofstream reference and a string note as arguments
    Writes the note to the file
*/
void writeNotes(ofstream& out, const string& note) {
    out << note << endl;
}

/* Function to display notes from a file
    Takes an ifstream reference as an argument
    Reads and displays each line from the file
*/
void displayNotes(ifstream& file) {
    string line;

    cout << "\nReading notes back from file:" << endl;

    while (getline(file, line)) {
        cout << line << endl;
    }
}
