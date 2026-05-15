#include "Library.h"
#include "Book.h"
#include <iostream>
#include <cctype>


// Constructor implementation
Library::Library(const std::string& libraryName) 
    : name(libraryName) {
}

std::string toLower(std::string text) {
    for (char& c : text) {
        c = tolower(c);
    }
    return text;
}

// Method to add a book to the collection
void Library::addBook(const Book& book) {
    books.push_back(book);
}

// Method to display all books in the catalog
void Library::displayBooks() const {
    std::cout << "CATALOG: " << std::endl;

    if (books.empty()) {
        std::cout << "No books in the library." << std::endl;
        return;
    }

    int count = 1;
    
    for (const auto& book : books) {
        std::cout << count << ". ";
        book.display();
        std::cout << std::endl;
        count++;
    }
}

// Methods to search for books by author name
void Library::searchBooksByAuthor(const std::string& authorName) const {
    std::cout << "Search by author " << authorName << ":" << std::endl;
    bool found = false;
    std::string searchName = toLower(authorName);

    for (const auto& book : books) {
        if (toLower(book.getAuthor().getName()) == searchName) {
            book.display();
            std::cout << std::endl;

            found = true;
        }
    }

    if (!found) {
        std::cout << "No books found by " << authorName << "." << std::endl;
    }
}

// Method to search for books by title keyword
void Library::searchBooksByTitle(const std::string& title) const {
    std::cout << "Books containing \"" << title << "\":" << std::endl;
    std::string searchTitle = toLower(title);
    bool found = false;

    for (const auto& book : books) {
        if (toLower(book.getTitle()).find(searchTitle) != std::string::npos) {
            book.display();
            std::cout << std::endl;

            found = true;
        }
    }

    if (!found) {
        std::cout << "No books found with title containing \"" << title << "\"." << std::endl;
    }
}

// Method to display basic stats: total book count
void Library::displayStats() const {
    std::cout << "Library Stats" << std::endl;
    std::cout << "Total Books in catalog: " << books.size() << std::endl;
}
