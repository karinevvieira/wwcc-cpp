#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include "Book.h"

class Library {
private:
    std::string name;
    std::vector<Book> books;

public:
    // Constructor
    Library(const std::string& libraryName);

    // Method to add a book to the collection
    void addBook(const Book& book);

    // Method to display all books in the catalog
    void displayBooks() const;

    // Methods to search for books by author name
    void searchBooksByAuthor(const std::string& authorName) const;

    // Method to search for books by title keyword
    void searchBooksByTitle(const std::string& title) const;

    // Method to display basic stats: total book count
    void displayStats() const;
};

#endif