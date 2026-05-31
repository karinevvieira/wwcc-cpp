#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <iomanip>
using namespace std;

enum class Department { ENGINEERING, SALES, HR, OPERATIONS };

constexpr double OVERTIME_THRESHOLD = 40.0;
constexpr double OVERTIME_MULTIPLIER = 1.5;
constexpr double MAX_WEEKLY_HOURS = 168.0;

// BUG: hourlyRate was defined as an int but later used as double and in calculations with doubles.
// FIX: I changed the variable to a double so it could be more accurate.
struct Employee {
    string name;
    Department dept;
    double hourlyRate;      // Bug 2: should be double *Done
    double hoursWorked;
};

// Returns the display name for a department
// BUG: The switch case had no default as a fall through.
// FIX: I added a default case where it would return unknown if it is none of the department options. 
string deptName(Department d) {
    switch (d) {
        case Department::ENGINEERING: return "Engineering";
        case Department::SALES:       return "Sales";
        case Department::HR:          return "HR";
        case Department::OPERATIONS:  return "Operations";
        default:                      return "Unknown";
                                      // Bug 3: no default case *Done
    }
}

// Validate hours input — returns true if valid
// BUG: This function only validated if hours exceeded the maximun weekly hours but did not check for negative hour input
// FIX: I added a check for hours less than 0 (negative) so it returns an error.
bool validHours(double hours) {
    if (hours > MAX_WEEKLY_HOURS) {    // Bug 4: only checks upper bound *Done
        cout << "Error: hours cannot exceed " << MAX_WEEKLY_HOURS << "\n";
        return false;
    }
    if (hours < 0) {
        cout << "Error: hours cannot be negative" << endl;
        return false;
    }
    return true;
}

// Calculate weekly pay for one employee (with overtime)
// BUG: The final calculated pay was just multiplying all the values without considering normal working hours (40 hours a week).
// FIX: I created a new variable to calculate the exceeding hours, then multiplied the normal hours (40) by the hourly rate plus the overtime hours with the multiplier.
double calculatePay(const Employee& e) {
    if (e.hoursWorked <= OVERTIME_THRESHOLD) {
        return e.hoursWorked * e.hourlyRate;
    } else {
        double overtimeCalc = e.hoursWorked - 40;
        // Bug 1: applies overtime rate to ALL hours, not just excess *Done
        return (40 * e.hourlyRate) + (overtimeCalc * e.hourlyRate * OVERTIME_MULTIPLIER);
    }
}

// Display a single employee row
void printEmployee(const Employee& e) {
    cout << left  << setw(20) << e.name
         << setw(14) << deptName(e.dept)
         << right << setw(8)  << fixed << setprecision(2) << e.hoursWorked << " hrs"
         << setw(10) << "$" + to_string((int)e.hourlyRate) + "/hr"
         << setw(12) << "$" + to_string((int)calculatePay(e))
         << "\n";
}

// Display all employees
void displayAll(const vector<Employee>& employees) {
    cout << "\n=== Employee Time Report ===\n";
    cout << left  << setw(20) << "Name"
         << setw(14) << "Department"
         << right << setw(8)  << "Hours"
         << setw(10) << "Rate"
         << setw(12) << "Pay"
         << "\n";
    cout << string(64, '-') << "\n";
    for (const auto& emp : employees) {
        printEmployee(emp);
    }
}

// Calculate total payroll cost
double totalPayroll(const vector<Employee>& employees) {
    return accumulate(employees.begin(), employees.end(), 0,  // Bug 5: integer init
        [](double sum, const Employee& e) {
            return sum + calculatePay(e);
        });
}

// TODO Feature 1: sortByHours
// Sort employees by hours worked, most to least, then display a ranked list.
// Use std::sort with a lambda comparator.
// Header: "=== Hours Ranking ==="
void sortByHours(vector<Employee>& employees) {
    sort(employees.begin(), employees.end(),
        [](const Employee& a, const Employee& b) {
            return a.hoursWorked > b.hoursWorked;
        });
 }

// TODO Feature 2: getDepartmentStats
// Display count, total hours, and average pay for employees in a given department.
// Use std::copy_if with a lambda to filter, then compute stats.
// Header: "=== [DeptName] Department Stats ==="
void getDepartmentStats(const vector<Employee>& employees, Department dept) { 
    vector<Employee> filteredDept;

    // Uses copy if to insert in the filteredDept only the employees in that department plus their information
    copy_if(employees.begin(), employees.end(), back_inserter(filteredDept),
        [dept](const Employee& e) { 
            return  e.dept == dept;
    }); 

    cout << "\n === " << deptName(dept) << " Department Stats ===" << endl;
    for (const auto& d : filteredDept) {
        printEmployee(d);
    }
 }

// TODO Feature 3: exportPayrollReport
// Write a payroll summary to filename grouped by department.
// For each department: list employees and their pay, then a subtotal line.
// After writing, print: "Payroll report saved to <filename>"
// Use ofstream; handle file open failure.
// 
void exportPayrollReport(const vector<Employee>& employees, const string& filename) { 
    ofstream outFile(filename);

    // Handler of file open failure
    if (!outFile) {
        cerr << "Error: Could not create file" << endl;
        return;
    }

    // Header for the file 
    outFile << string(30, '-') << endl;
    outFile << " === Payroll by Department === " << endl;
    outFile << string(30, '-') << endl << endl;

    // Created a vector to hold all the departments to be able to loop through them
    vector<Department> depts = {Department::ENGINEERING, Department::SALES, Department::HR, Department::OPERATIONS};

    // This loop iterates through each department and displays the information required in the instructions
    for (Department d : depts) {
        outFile << " === " << deptName(d) << " Department ===\n";

        // This keeps track of the subtotal per individual department and hasEmployees checks if a department is empty
        double deptSubtotal = 0.0;
        bool hasEmployees = false;

        // Inner loop handles the employees in each department and displays the information of each one
        for (const auto& e : employees) {
            if (e.dept == d) {
                double pay = calculatePay(e);

                outFile << left 
                        << setw(20) << e.name
                        << right
                        << setw(8) << fixed << setprecision(2) << e.hoursWorked << " hrs @ "
                        << "$" << e.hourlyRate << "/hr = "
                        << "$" << pay << endl;

                deptSubtotal += pay;
                hasEmployees = true;
            }
        }

        // Edge case handler for empty departments
        if (!hasEmployees) {
            outFile << "No employees in this department\n";
        }

        // Display the subtotal per department
        outFile << left << setw(15) << "Department Subtotal: $" 
                << right << setw(7) << fixed << setprecision(2) << deptSubtotal << endl;
        outFile << string(30, '-') << endl << endl;
    }

    outFile.close();
    cout << "\nPayroll report saved to " << filename << endl << endl; // Success message
}

int main() {
    vector<Employee> employees = {
        {"Alice Chen",      Department::ENGINEERING, 42,   45.0},
        {"Bob Martinez",    Department::SALES,       28,   38.0},
        {"Carol Singh",     Department::HR,          35,   32.5},  // fractional rate
        {"David Park",      Department::ENGINEERING, 38,   50.0},
        {"Emma Wilson",     Department::OPERATIONS,  30,   29,  },
        {"Frank Torres",    Department::SALES,       45,   44.5},  // overtime
        {"Grace Kim",       Department::HR,          33,   33.5},  // fractional rate
        {"Henry Okafor",    Department::OPERATIONS,  29,   55.0},  // overtime
    };

    cout << "=== HR Time Tracker ===\n";

    // Validate a sample input
    cout << "\nValidating hours entry -5: "
         << (validHours(-5) ? "valid" : "invalid") << "\n";  // should be invalid

    displayAll(employees);

    cout << "\nTotal payroll this week: $"
         << fixed << setprecision(2) << totalPayroll(employees) << "\n";

    // Uncomment after implementing features:
    sortByHours(employees);
    cout << "\n === Hours Ranking === " << endl;
    for (const auto& e : employees){
        printEmployee(e);
    }


    getDepartmentStats(employees, Department::ENGINEERING);
    
    exportPayrollReport(employees, "payroll_report.txt");

    return 0;
}