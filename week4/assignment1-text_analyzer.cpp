#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

// Prototypes
void analysis(string);
void upperCase(string);
void lowerCase(string);

/*  1. Validate the user input on main to make sure it is not empty
    2. Call the proper functions and display results. 
*/
int main() {
    string sentence;
    bool isValid = false;

    while (!isValid) {
        cout << "TEXT ANALYZER" << endl;
        cout << "-------------" << endl;
        cout << "Enter a sentence or paragraph: ";
        getline(cin, sentence);
        cout << endl << endl;

        if (sentence.length() == 0) {
            cout << "This string is empty. Please type a valid string" << endl;
            isValid = false; 
        }
        else {
            isValid = true;
        }
    }

    analysis(sentence);
    upperCase(sentence);
    lowerCase(sentence);

    return 0;
}

/*  1. Get the word count of the phrase the user input. 
    2. Separate the letter from the other special characters to put in a new string (only with letter)
    3. Get the amount of characters each word has to make the average math 
    4. The longest word will be analyzed on each iteration of the while loop and compared with the word of the last iteration 
    If is is longer than it will take the longestword's place 
    If it is shorter then the loop continues without any changes
    5. The countSentence counts based on the delimiter ('.' , '!' , '?'). Once it reaches one of these it will add 1 to the sentence counter. 
*/
void analysis(string sentence) {
    stringstream ss(sentence);
    string word;
    string longestWord = "";
    int countWord = 0;
    int countSentence = 0;
    int totalCharCount = 0;

    while (ss >> word) {
        countWord++;

        string cleanWord = "";
        for (char c : word) {
            if (isalpha(c)) 
            cleanWord += c;
        }

        int len = cleanWord.length();
        totalCharCount += len;

        if (len > longestWord.length()) {
            longestWord = cleanWord;
        }
    }

    double avgLen = (double)totalCharCount / countWord;

    for (char c : sentence) {
        if (c == '.' || c == '!' || c == '?')
        countSentence++;
    }

    cout << "Analysis: " << endl;
    cout << "  Characters (with spaces): " << sentence.length() << endl;
    cout << "  Word count: " << countWord << endl;
    cout << "  Sentence count: " << countSentence << endl;
    cout << "  Longest word: " << longestWord << endl;
    cout << "  Average word length: " << fixed << setprecision(1) << avgLen << endl << endl;

}

// Changes each character to uppercase
void upperCase(string sentence) {
    for (char &c : sentence) {
        c = toupper(c);
    }

    cout << "Uppercase: " << endl;
    cout << "  " << sentence << endl << endl;
}

// Changes each character to lowercase
void lowerCase(string sentence) {
    for (char &c : sentence) {
        c = tolower(c);
    }

    cout << "Lowercase: " << endl;
    cout << "  " << sentence << endl << endl;
}