#include "Library.h"
#include "Book.h"
#include "Author.h"
#include <iostream>
#include <string>

using namespace std;

// Prototypes
void displayMenu();
void validateInput(int &number);
void addBookToLibrary(Library& library);

int main() {
    cout << "-------------------------" << endl;
    cout << "LIBRARY MANAGEMENT SYSTEM" << endl;
    cout << "-------------------------" << endl;

    cout << "Library: The Real Gabinete Portugues de Leitura" << endl;
    Library library("The Real Gabinete Portugues de Leitura");

    displayMenu();
    int choice;

    do {
        cout << "\nEnter your choice: ";
        cin >> choice;
        cout << endl;
        validateInput(choice);
        
        switch (choice) {
            case 1: {
                addBookToLibrary(library);
                break;
            }

            case 2: {
                library.displayBooks();
                break;
            }

            case 3: {
                string authorName;
                cout << "Enter author name: ";
                cin.ignore(1000, '\n');
                getline(cin, authorName);
                library.searchBooksByAuthor(authorName);
                break;
            }

            case 4: {
                string title;
                cout << "Enter title keyword: ";
                cin.ignore(1000, '\n');
                getline(cin, title);
                library.searchBooksByTitle(title);
                break;
            }

            case 5: {
                library.displayStats();
                break;
            }
            case 6: {
                cout << "Exiting program..." << endl;
                break;
            }
            default: {
                cout << "Invalid choice! Please try again." << endl;
                break;
            }
        }
    } while (choice != 6);

    return 0;

}

/*  Function to display the menu options, keeping the main function cleaner and more organized
*/
void displayMenu() {
    cout << "\n1. Add Book" << endl;
    cout << "2. Display All Books" << endl;
    cout << "3. Search by Author" << endl;
    cout << "4. Search by Title" << endl;
    cout << "5. Show Stats" << endl;
    cout << "6. Exit" << endl;

}

void validateInput(int &number) {
    while(cin.fail()) {
        cout << "That was not a valid number. Try Again!";

        cin.clear();
        cin.ignore(1000, '\n');
        cout << endl;

        cout << "\nEnter your choice: ";
        cin >> number;
    }
}

void addBookToLibrary(Library& library) {
    string title;
    string authorName;
    string isbn;
    int publicationYear;
    int authorBirthyear;

    cin.ignore();

    cout << "Enter book title: ";
    getline(cin, title);

    cout << "Enter author name: ";
    getline(cin, authorName);

    cout << "Enter publication year: ";
    cin >> publicationYear;
    validateInput(publicationYear);

    cout << "Enter ISBN: ";
    cin >> isbn;

    cout << "Enter author birth year: ";
    cin >> authorBirthyear;
    validateInput(authorBirthyear);

    Author author(authorName, authorBirthyear);

    Book book(title, publicationYear, isbn, author);

    library.addBook(book);

    cout << "Book added successfully!" << endl;
}