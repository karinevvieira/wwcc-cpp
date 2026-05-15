#ifndef AUTHOR_H
#define AUTHOR_H

#include <string>
#include <iostream>

class Author {
private:
    std::string name;
    int birthyear;

public:
    // Constructor only initializing
    Author(const std::string& authorName, int authorBirthyear);

    // Getters
    std::string getName() const;
    int getBirthyear() const;

    // Display method to print the author's info
    void display() const;
};

#endif