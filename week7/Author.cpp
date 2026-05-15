#include "Author.h"
#include <iostream>

Author::Author(const std::string& authorName, int authorBirthyear) 
    : name(authorName), birthyear(authorBirthyear) {
}

// Getters implementations
std::string Author::getName() const {
    return name;
}
int Author::getBirthyear() const {
    return birthyear;
}

// Display method implementation
void Author::display() const {
    std::cout << "Author : " << name << " (born " << birthyear << ")" << std::endl;
}