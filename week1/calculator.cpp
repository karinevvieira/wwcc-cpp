#include <iostream>

int main() {
    double num1, num2;

    // Ask the user for two numbers
    std::cout << "Enter the first number: ";
    std::cin >> num1;
    std::cout << "Enter the second number: ";
    std::cin >> num2;

    std::cout << "\nResults:" << std::endl;

    // Sum
    std::cout << "Sum:        " << num1 << " + " << num2 << " = " << (num1 + num2) << std::endl;

    // Difference
    std::cout << "Difference: " << num1 << " - " << num2 << " = " << (num1 - num2) << std::endl;

    // Product
    std::cout << "Product:    " << num1 << " * " << num2 << " = " << (num1 * num2) << std::endl;

    // Quotient with division by zero check
    std::cout << "Quotient:   ";
    if (num2 != 0) {
        std::cout << num1 << " / " << num2 << " = " << (num1 / num2) << std::endl;
    } else {
        std::cout << "Error: Division by zero is not allowed!" << std::endl;
    }

    return 0;
}