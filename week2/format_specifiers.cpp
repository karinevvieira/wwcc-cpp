#include <iostream>
#include <cstdio>   // For printf
using namespace std;

int main() {
    int integer_value = 42;
    float float_value = 3.14159265f;
    double double_value = 3.14159265;
    char char_value = 'X';
    const char* string_value = "Hello, World!";

    printf("Format Specifier Practice\n");
    printf("------------------------\n\n");

    // Integer format specifier
    printf("Integer formats:\n");
    printf("Decimal: %d\n", integer_value); // Signed decimal integer
    printf("Hexadecimal: %#x\n", integer_value); // Hexadecimal lowercase - followed the example 
    printf("Octal: %#o\n", integer_value); // Octal integer
    printf("With width (5): |%5d|\n", integer_value); // Signed decimal integer with width of 5
    printf("Left-aligned: |%-5d|\n", integer_value); // Signed decimal integer left-aligned with width of 5

    // Float Format specifier
    printf("\nFloat formats:\n");
    printf("Default: %f\n", float_value); // float decimal floating point
    printf("With precision (2): %.2f\n", double_value); // double decimal floating point with 2 digits after the decimal point
    printf("Scientific: %e\n", float_value); // float scientific notation
    printf("Fixed with precision (4): %.4f\n", float_value); // float fixed-point with 4 digits after the decimal point

    // Character and String formats
    printf("\nCharacter and String formats:\n"); 
    printf("Character: %c\n", char_value); // Single character specifier 
    printf("String: %s\n", string_value); // String of characters
    printf("String with Width (20): |%20s|\n", string_value); // String of characters with width of 20, right-aligned

    return 0;
}