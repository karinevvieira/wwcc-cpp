#include <iostream>
#include <string>

int main() {
    std::string name;
    std::string favoriteFood;

    // Prompt the user for their name
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    // Print greeting message with the user's name
    std::cout << "Hello, " << name << "! Welcome to C++!" << std::endl;

    // Ask one additional question
    std::cout << "What is your favorite food? ";
    std::getline(std::cin, favoriteFood);

    // Print the answer back with additional context (not very creative)
    std::cout << favoriteFood << "? Who eats that? " << name;
    std::cout << ", just kidding, you have an excellent palate!" << std::endl;

    return 0;
}