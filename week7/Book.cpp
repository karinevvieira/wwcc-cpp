#include "Book.h"
#include <iostream>

Book::Book(std::string bookTitle, int bookPublicationYear, std::string bookIsbn, Author bookAuthor) 
    : title(bookTitle), publicationYear(bookPublicationYear), isbn(bookIsbn), author(bookAuthor) {
}

// Getters implementations
std::string Book::getTitle() const {
    return title;
}
int Book::getPublicationYear() const {
    return publicationYear;
}
std::string Book::getIsbn() const {
    return isbn;
}
const Author& Book::getAuthor() const {
    return author;
}


// Setter implementation with validation
void Book::setPublicationYear(int newPublicationYear) {
    if (newPublicationYear <= 0) {
        std::cout << "Error: publication year cannot be a negative number" << std::endl;
    }
    else {
        publicationYear = newPublicationYear;
    }
}

// Display method implementation
void Book::display() const {
    std::cout << "\"" << title <<  "\" (" << publicationYear << ")" << std::endl;
    author.display();
    std::cout << "ISBN: " << isbn << std::endl;
}