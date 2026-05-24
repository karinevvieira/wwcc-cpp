#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm> // Required for the max/min functions to work. This was an error when compiling the file

using namespace std;

struct Student {
    string lastName;
    string firstName;
    int g1, g2, g3;
    double average;
    int high;
    int low;
};

int main() {
    // --- Read input file ---
    ifstream inFile("grades.txt");

    // FIX: Check if file opened successfully before proceding with reading
    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

    // Bug 1 is here - BUG: Added a check to see if the file opened successfully before trying to read from it
    cout << "Reading records from grades.txt..." << endl;

    vector<Student> students;
    string line;

    // FIX: Erased all the first part which was not correct but kept the second part which had some of the bugs corrected
    // --- Parse properly (replace the loop above with this corrected version) ---
    // BUG: The first loop uses a condition that caused the last record to be processed twice [while (!inFile.eof())...] - this was the bug
    // FIX: This loop is fixed already with getline(inFile, line) - this reads line-by-line
    while (getline(inFile, line)) {
        if (line.empty() || line[0] == '#') {
            continue;
        } // Skip empty lines and comments
        
        // BUG: In the first part this was outside the while loop which 
        // FIX: This is now inside the loop so the lines don't bleed into the next line
        stringstream ss;    // move ss inside loop to fix Bug 4 - This was already fixed in this second part
        ss.str(line);       // This starts a new stream per line

        Student s;
        ss >> s.lastName >> s.firstName >> s.g1 >> s.g2 >> s.g3;

        s.high = max({s.g1, s.g2, s.g3}); // Added <algorithm> header so this function works
        s.low  = min({s.g1, s.g2, s.g3}); // Added <algorithm> header so this function works

        // BUG: total was an int variable making the calculation with the wrong types
        // FIX: I changed the data type to a double and I changed the division number to a floating point (3.0)
        double total = s.g1 + s.g2 + s.g3;
        s.average = total / 3.0;    // Bug 5 is here - FIXED

        students.push_back(s);
    }

    inFile.close();

    // ADDED: Safe guarding the program to always handle edge-cases
    if (students.empty()) {
        cout << "No students data found" << endl;
    }

    cout << students.size() << " students loaded." << endl << endl;

    // --- Write report ---
    // BUG: The output file is opened in a mode that erases any existing data
    // FIX: I added ios::app which guarantees the file will just append next time it is opened instead of erasing the data
    ofstream outFile("grade_report.txt", ios::app);   // Bug 3 is here -FIXED
    // ADDED: Checking if the file was created/opened safely
    if (!outFile) {
        cerr << "Error: Could not create file" << endl;
        return 1;
    }

    // --- Display to console and write to file ---
    auto printReport = [&](ostream& out) {
        out << "GRADE REPORT" << endl;
        out << string(20, '-') << endl;

        out << left
            << setw(20) << "Name" 
            << right // FIX: I fixed the output to have only the name left-aligned and the rest right-aligned so it looks like the expected output
            << setw(7)  << "Avg"
            << setw(7)  << "High"
            << setw(7)  << "Low"
            << endl;
        out << string(20, '-') << endl;

        double classTotal = 0;
        int topIdx = 0, lowIdx = 0;

        // Bug 6: setw is applied once here, outside the loop - FIXED
        // out << setw(20);

        for (int i = 0; i < (int)students.size(); i++) {
            Student& s = students[i];
            string name = s.lastName + ", " + s.firstName;

            // Bug 7: numbers should be right-aligned, not left - FIXED
            // FIX: I changed the left alignment to right alignment only for the numbers as I did above (name is still left-aligned)
            out << left
                << setw(20) << name // BUG: setw(20) was applied once outside of the loop but it is not useful there
                                    // FIX: I set the width inside the loop on the name column
                << right
                << setw(7)  << fixed << setprecision(1) << s.average
                << setw(7)  << s.high
                << setw(7)  << s.low
                << endl;

            classTotal += s.average;
            if (s.average > students[topIdx].average) topIdx = i;
            if (s.average < students[lowIdx].average) lowIdx = i;
        }

        double classAvg = classTotal / students.size();

        out << endl << "CLASS STATISTICS" << endl;
        out << string(20, '-') << endl;
        out << fixed << setprecision(1);
        out << "Class average: " << classAvg << endl;
        out << "Top student:   "
            << students[topIdx].lastName << ", "
            << students[topIdx].firstName
            << " (" << students[topIdx].average << ")" << endl;
        out << "Low student:   "
            << students[lowIdx].lastName << ", "
            << students[lowIdx].firstName
            << " (" << students[lowIdx].average << ")" << endl;
    };

    printReport(cout);
    printReport(outFile);
    outFile.close();

    cout << endl << "Report written to grade_report.txt" << endl;
    return 0;
}
