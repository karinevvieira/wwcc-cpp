#ifndef BOOK_H
#define BOOK_H

#include <string>
#include "Author.h"

class Book {
private:
    std::string title;
    int publicationYear;
    std::string isbn;
    Author author;
public:
    // Constructor
    Book(std::string bookTitle, int bookPublicationYear, std::string bookIsbn, Author bookAuthor);

    // Getters
    std::string getTitle() const;
    int getPublicationYear() const;
    std::string getIsbn() const;
    const Author& getAuthor() const;

    // Setter for publicationYear with validation
    void setPublicationYear(int newPublicationYear);

    // Display method to print the book's info
    void display() const;
};

#endif