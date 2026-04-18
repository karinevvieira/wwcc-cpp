#include <iostream>
#include <cstdlib>  // For rand()
#include <ctime>    // For time()
using namespace std;

int main() {
    srand(time(0));

    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    cout << "Number Guessing Game" << endl;
    cout << "I'm thinking of a number between 1 and 100." << endl << endl;

    // Generate a random number between 1 and 100
    secretNumber = rand() % 100 + 1;

    // Ask the user to guess the number
    cout << "Enter your guess: ";
    cin >> guess;

    // Provide feedback if the guess is too high or too low
    while (guess != secretNumber) {
        attempts++;
        if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Too high! Try again." << endl;
        }
        // Continue until the user guesses correctly
        cout << "Enter your guess: ";
        cin >> guess;
    }
    attempts++; // Make sure to count the last guess (correct one)

    // Display a congratulatory message with the number of guesses when the user wins
    cout << "Congratulations! You guessed the number " << secretNumber << " correctly!" << endl;
    cout << "It took you " << attempts << " guesses." << endl;

    return 0;
}