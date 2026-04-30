#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// The size of the array is initialized here so it can be reused throughout the code
const int sizeArr = 5;

// Functions prototypes
double averageScore(int scores[]);
int highestScore(int scores[], int &index);
int lowestScore(int score[], int &index);
string overallGrade(int scores[]);
void gradeDist(int scores[]);
void letterGrade(int scores[]);

/*  Displays the stats based on the scores that the user inserts
    Uses a for loop to fill the array with the 5 values the user inserts
    Displays the functions as demonstrated on the example output in the instructions 
    Note: I tried to make functions for everything so I could keep the main function cleaner but this became a bit more complicated than antecipated 
*/
int main() {
    int scoreArr[5];

    cout << "QUIZ GRADE TRACKER" << endl;
    cout << "------------------" << endl;

    for (int i = 0; i < sizeArr; i++) {
        cout << "Enter score for Quiz " << i + 1 << " (0-100): ";
        cin >> scoreArr[i];
    }

    int highIdx;
    int highScore = highestScore(scoreArr, highIdx);
    int lowIdx;
    int lowScore = lowestScore(scoreArr, lowIdx);

    cout << "\nQuiz Results: " << endl;
    letterGrade(scoreArr);
    cout << endl << endl;

    cout << "Statistics: " << endl;
    cout << "  Average score: " << averageScore(scoreArr) << fixed << setprecision(1) << endl;
    cout << "  Highest score: " << highScore << " (Quiz " << highIdx + 1 << ")" << endl;
    cout << "  Lowest score: " << lowScore << " (Quiz " << lowIdx + 1 << ")" << endl;
    cout << "  Overall grade: " << overallGrade(scoreArr) << endl << endl;

    cout << "Grade Distribution: " << endl;
    gradeDist(scoreArr);

    return 0;
}

// Calculates the average by adding all the numbers in the array and dividing by 5.0 (the total number of quizzes) and returns the average
double averageScore(int scores[]) {
    int sumScore = 0;
    for (int i = 0; i < sizeArr; i++){
        sumScore += scores[i];
    }

    return sumScore / 5.0;
}

/*  Starts comparing the numbers in the array on the first index and if the next is highest it takes the highVal place
    The index also changes so I can display which quiz that result comes from 
*/
int highestScore(int scores[], int &index) {
    int highVal = scores[0];
    index = 0;

    for (int i = 1; i < sizeArr; i++) {
        if (scores[i] > highVal) {
            highVal = scores[i];
            index = i;
        }
    }

    return highVal;
}

/*  Starts comparing the numbers in the array on the first index and if the next is lowest it takes the lowVal place
    The index also changes so I can display which quiz that result comes from 
*/
int lowestScore(int scores[], int &index) {
    int lowVal = scores[0];
    index = 0;

    for (int i = 1; i < sizeArr; i++) {
        if (scores[i] < lowVal) {
            lowVal = scores[i];
            index = i;
        }
    }

    return lowVal;
}

/*  Takes the averageScore results and compares to the if conditions to see what is the average grade
*/
string overallGrade(int scores[]) {
    int avgScore = averageScore(scores);
    if (avgScore >= 90) {
        return "A";
    }
    else if (avgScore >= 80) {
        return "B";
    }
    else if (avgScore >= 70) {
        return "C";
    }
    else if (avgScore >= 60) {
        return "D";
    }
    else {
        return "F";
    }
}

// Used to display the quiz results with its respective letter grade
void letterGrade(int scores[]) {
    for (int i = 0; i < sizeArr; i++) {
        string letter;
        if (scores[i] >= 90) {
            letter = "A";
        }
        else if (scores[i] >= 80) {
            letter = "B";
        }
        else if (scores[i] >= 70) {
            letter = "C";
        }
        else if (scores[i] >= 60) {
            letter = "D";
        }
        else {
            letter = "F";
        }

        cout << "  Quiz " << i + 1 << ": " << scores[i] << " (" << letter << ")" << endl;
    }

}

// Function to count how many grades of the same letter the student has 
void gradeDist(int scores[]) {
    int countA = 0, 
        countB = 0, 
        countC = 0, 
        countD = 0, 
        countF = 0;

    for (int i = 0; i < sizeArr; i++) {
        string letter;
        if (scores[i] >= 90) {
            countA++;
        }
        else if (scores[i] >= 80) {
            countB++;
        }
        else if (scores[i] >= 70) {
            countC++;
        }
        else if (scores[i] >= 60) {
            countD++;
        }
        else {
            countF++;
        }
    }

    cout << "  A: " << countA << endl;
    cout << "  B: " << countB << endl;
    cout << "  C: " << countC << endl;
    cout << "  D: " << countD << endl;
    cout << "  F: " << countF << endl;
}



