#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Proper function prototypes
int countVowels(string);
int countConsonants(string);
bool isPalindrome(string);
char firstLetter(string);
string reverse(string);
bool continueOrNot();
void validateInput(string&);

/*  1. Prompt the user to enter a word.
    2. Validate the user input to see if it is not empty and only contains letters. 
    **I decided to make a separate function for the validation for a cleaner main function.
    3. Display the results of each analysis
    4. Only continue the loop if continueOrNot function retuns true (y) 
*/
int main() {
    string userInput;

    do {
    cout << "Enter a word: ";
    cin >> userInput;
    validateInput(userInput);
    cout << endl;

    cout << "------------" << endl;
    cout << "Word Analysis: " << endl;
    cout << "------------" << endl;
    cout << "Orignal word: " << userInput << endl;
    cout << "Number of vowels: " << countVowels(userInput) << endl;
    cout << "Number of consonants: " << countConsonants(userInput) << endl;
    cout << "First letter: " << firstLetter(userInput) << endl;
    cout << "Reversed: " << reverse(userInput) << endl;
    cout << "Is palindrome: ";
    if (!isPalindrome(userInput)) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    } 
    cout << endl << endl;

    } while (continueOrNot());

    return 0;
}
/*  Function to count the number of vowels in a word
    @param word the user input will be used as the argument here 
    The count starts at 0 
    The for loop will check each letter in the word by its index and compare to the conditions on the if statement
    I added tolower to make it easier to check and for the if statement to look cleaner (less options) 
*/
int countVowels(string word) {
    int vowelCount = 0;

    for (int i = 0; i < word.length(); i++) {
        char letter = tolower(word[i]);
        if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u') {
            vowelCount++;
        }
    }

    return vowelCount;
}

/*  Function to count the number of consonants in a word
    The logic is the same as the one above but this time we check if the letter is not a vowel, instead of checking if it is a vowel 
*/
int countConsonants(string word) {
    int consonantCount = 0;

    for (int i = 0; i < word.length(); i++) {
        char letter = tolower(word[i]);
        if (!(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')) {
            consonantCount++;
        }
    }

    return consonantCount;
}

/*  isPalindrome checks if the word reads the same when reversed or not. 
    The for loop compares each letter of the original word and the reversed word by their index, independently of case (tolower).
    Note: I tried to find a built-in function to put the whole word to lowercase but I could not find it so I had to go for another loop. 
    I used the reverse function to make this function cleaner and to reuse the code.
*/
bool isPalindrome(string word) {
    string reversedWord = reverse(word);

    for (int i = 0; i < word.length(); i++) {
        if (tolower(word[i]) != tolower(reversedWord[i])) {
            return false;
        }
    }
    return true;
}

// Returns the first letter of the word by using the index 0 of the string as an array of characters
char firstLetter(string word) {
    return word[0];
}

/*  Creates a new string with the reversed word 
    Uses the for loop starting by the end (-1 index) and adds to the new string in each iteration
    Returns the complete reversed word (new string) 
*/
string reverse(string word) {
    string reversedWord = "";

    for (int i = word.length() - 1; i >= 0; i--) {
        reversedWord += word[i];
    }

    return reversedWord;
}
/*  Validates the user input to continue or not analyzing another word
    Returns a boolean to the main function 
    Will run the loop again in case the user did not use one of the options (y/n) so the user has the opportunity to try again 
    Will exit the program if the user chose 'n' for no, otherwise it will continue to analyze another word if the user chose 'y' for yes
    I had the response as a char but while testing I found this could be a problem if the user writes more than one character so I changed to string to catch everything.
*/
bool continueOrNot() {
    string response;

    while (true) {
        cout << "Would you like to analyze another word? (y/n): ";
        cin >> response;
        cout << endl;

        if (response == "y" || response == "Y") {
            return true;
        } 
        if (response == "n" || response == "N") {
            cout << "Exiting Program..." << endl;
            return false;
        } 
        cout << "Invalid input. Please enter 'y' for yes or 'n' for no." << endl;
    }
}

/*  Validates the user input for the word to analyze
    1. The function will check if the input is empty or if it contains any character that is not a letter. 
    2. The function takes a reference parameter so it can modify the original variable in the main function and not just a copy of it. 
    This allows the user to enter a new word in cae the input was not valid and the main function to use the new input for the analysis.
    3. The for loop will check each character of the word to against the isalpha function that checks if the character is a letter or not.
    4. If it finds a character that is not a letter, it will set the isValid variable to false and break the loop to ask for a new input 
    5. The loop will continue until the user enters a valid input. 

*/
void validateInput(string &word) {
    bool isValid = false;

    while (!isValid) {
        isValid = true;

        if (word.empty()) {
            isValid = false;
        } 
        else {
            for (int w = 0; w < word.length(); w++) {
                if (!isalpha(word[w])) {
                    isValid = false;
                    break;
                }
            } 
        }

        if (!isValid) {
            cout << "Invalid input. Please enter a single word with only letters: ";
            cin >> word;
        }
    } 
}