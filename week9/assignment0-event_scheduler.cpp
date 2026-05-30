#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <iomanip>

using namespace std;

enum class EventCategory { CONCERT, CONFERENCE, SPORTS, WORKSHOP };

struct Event {
    string name;
    string date;          // format: "YYYY-MM-DD"
    EventCategory category;
    int attendees;
    double ticketPrice;
};

// Returns the display name for a category
string categoryName(EventCategory cat) {
    switch (cat) {
        // BUG: Concert and workshop were in the wrong spots (Swapped return statements)
        //FIX: I fixed the return statement to show the correct string for the category.
        case EventCategory::CONCERT:    return "Concert";   // Bug 5
        case EventCategory::CONFERENCE: return "Conference";
        case EventCategory::SPORTS:     return "Sports";
        case EventCategory::WORKSHOP:   return "Workshop";    // Bug 5
        default:                        return "Unknown";
    }
}

// Display a single event
void printEvent(const Event& e) {
    cout << left << setw(30) << e.name
         << setw(12) << e.date
         << setw(12) << categoryName(e.category)
         << "Attendees: " << setw(5) << e.attendees
         << " Price: $" << fixed << setprecision(2) << e.ticketPrice
         << "\n";
}

// Display all events
void displayAll(const vector<Event>& events) {
    cout << "\n=== All Events ===\n";
    cout << left << setw(30) << "Name" << setw(12) << "Date"
         << setw(12) << "Category" << "\n";
    cout << string(70, '-') << "\n";
    for (const auto& e : events) {
        printEvent(e);
    }
}

// Calculate total revenue across all events
// BUG: It was only returning the sum of the number of attendees
// FIX: I added * e.ticketPrice so the amount of attendees will be multiplied by the price to find the revenue for each event and will return the sum of everything
double totalRevenue(const vector<Event>& events) {
    return accumulate(events.begin(), events.end(), 0.0,
        [](double sum, const Event& e) {
            return sum + e.attendees * e.ticketPrice;   // Bug 1: missing * e.ticketPrice
        });
}

// Calculate average ticket price across all events
// BUG: The total variable was defined as int and the division had an int parenthesis on events.size()
// FIX: I changed the total variable from an int to a double and erased the (int) before the events.size()
double averageTicketPrice(const vector<Event>& events) {
    double total = 0;                      // Bug 2: should be double
    for (const auto& e : events) {
        total += e.ticketPrice;         // Bug 2: fractional part truncated
    }
    return total / events.size(); // Bug 2: integer division
}

// Sort events by date, oldest first
// BUG: The sorting order here was descending and not ascending (what the function actually is supposed to return)
// FIX: I changed the sign from > to < so now it compares if a is lower than b.
void sortByDateAscending(vector<Event>& events) {
    sort(events.begin(), events.end(),
        [](const Event& a, const Event& b) {
            return a.date < b.date;     // Bug 3: > sorts descending, not ascending
        });
}

// Search for events whose name contains the search term (case-sensitive)
// BUG: The function was only printing the first match because the find_if only finds one element and not multiple
// FIX: I changed the function to loop through all the events and return the matching ones. The if condition executes if the result is not "Not Found" (string::npos)
void searchByName(const vector<Event>& events, const string& term) {
    cout << "\n=== Search Results for \"" << term << "\" ===\n";
    bool found = false;

    for (const auto& e : events) {
        if (e.name.find(term) != string::npos){
            printEvent(e);
            found = true;
        }
    }
    if (!found) {
        cout << "No events found.\n";
    }             // Bug 4: only prints first match, not all
}

// TODO Feature 1: sortByAttendees
// Sort events by attendee count, highest first, then display them.
// Use a lambda comparator with std::sort.
// Used the same logic as the sorting by date function and displayed the same way. 
void sortByAttendees(vector<Event>& events) { 
    sort(events.begin(), events.end(),
        [](const Event& x, const Event& y) {
            return x.attendees > y.attendees;
        });
}

// TODO Feature 2: filterByCategory
// Return a vector containing only events matching the given category.
// Use std::copy_if with a lambda.
// I used the copy_if to insert the events that match the cat parameter.
// I displayed the results directly in the function instead of main. 
void filterByCategory(const vector<Event>& events, EventCategory cat) { 
    vector<Event> filteredCategory;

    copy_if(events.begin(), events.end(), back_inserter(filteredCategory),
        [cat](const Event& e) { 
            return  e.category == cat;
    }); 

    cout << "\n === Concerts ===\n";
    for (const auto& f : filteredCategory) {
        printEvent(f);
    }
}

// TODO Feature 3: exportUpcomingEvents
// Write all events with date >= "2025-06-01" to the given filename.
// Each line: "Name | Date | Category | Attendees | $Price"
// Use ofstream; print a confirmation message when done.
void exportUpcomingEvents(const vector<Event>& events, const string& filename) { 
    ofstream outFile(filename);

    // Check if file was created/opened safely
    if (!outFile) {
        cerr << "Error: Could not create file" << endl;
        return;
    }

    // The header for the file 
    outFile << "UPCOMING EVENTS" << endl;
    outFile << string(20, '-') << endl << endl;

    outFile << right
            << setw(7) << "Name | " 
            << setw(7)  << "Date | "
            << setw(10)  << "Category |" 
            << setw(11)  << " Attendees | "
            << setw(7) << "Price |"
            << endl;

    // The contents of the file filtered by dates after 2025-06-01. 
    // Simple for loop that will display the contents if they match the condition on the if statement.
    for (const auto& e : events) {
        if (e.date >= "2025-06-01") {
            outFile << e. name << " | "
                    << e.date << " | "
                    << categoryName(e.category) << " | "
                    << e.attendees << " | $"
                    << e.ticketPrice<< "\n";
        }
    }

    outFile.close();

    cout << "File exported successfuly!" << endl; // Confirmation message 
}

int main() {
    vector<Event> events = {
        {"Spring Music Fest",     "2025-04-12", EventCategory::CONCERT,    1200, 45.50},
        {"Tech Summit 2025",      "2025-06-20", EventCategory::CONFERENCE,  350, 129.00},
        {"City 5K Run",           "2025-05-03", EventCategory::SPORTS,      800, 25.25},
        {"Watercolor Workshop",   "2025-07-15", EventCategory::WORKSHOP,     40, 60.00},
        {"Jazz Under the Stars",  "2025-08-02", EventCategory::CONCERT,     600, 35.75},
        {"Leadership Workshop",   "2025-06-28", EventCategory::WORKSHOP,     75, 89.00},
        {"Regional Soccer Cup",   "2025-09-14", EventCategory::SPORTS,     2500, 18.00},
        {"Dev Conf Northwest",    "2025-10-05", EventCategory::CONFERENCE,   420, 199.00},
    };

    cout << "=== Community Event Scheduler ===\n";

    displayAll(events);

    cout << "\nTotal revenue (all events): $"
         << fixed << setprecision(2) << totalRevenue(events) << "\n";

    cout << "Average ticket price: $"
         << fixed << setprecision(2) << averageTicketPrice(events) << "\n";

    sortByDateAscending(events);
    cout << "\n=== Events sorted by date (oldest first) ===\n";
    for (const auto& e : events) {
        printEvent(e);
    }

    searchByName(events, "Workshop");

    // Uncomment after implementing features:
    sortByAttendees(events);
    cout << "\n=== Events by Popularity ===\n";
    for (const auto& e : events) {
        printEvent(e);
    }

    filterByCategory(events, EventCategory::CONCERT);
    
    exportUpcomingEvents(events, "upcoming_events.txt");

    return 0;
}