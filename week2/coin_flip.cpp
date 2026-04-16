#include <iostream>
#include <cstdlib>  // For rand()
#include <ctime>    // For time()
using namespace std;

int main() {
    srand(time(0));

    int flips;
    int heads = 0;
    int tails = 0;

    cout << "Coin Flip Simulator" << endl;
    cout << "How many flips would you like to simulate? ";
    cin >> flips;

    for (int i = 0; i < flips; i++) { // As long as i is less than the number of flips, keep looping and fliping the coin
        int flip_result = rand() % 2; // 0 for heads, 1 for tails
        if (flip_result == 0) { // if the result is 0, then add 1 to the heads variable
            heads++;
        } else { // if the result is 1, then add 1 to the tails variable
            tails++;
        }
    }

    // Calculate percentages
    int heads_percentage = (heads * 100) / flips; 
    int tails_percentage = (tails * 100) / flips;

    // Show the results as the example output in the instructions
    cout << "Results:" << endl; 
    cout << "Heads: " << heads << " (" << heads_percentage << "%)" << endl;
    cout << "Tails: " << tails << " (" << tails_percentage << "%)" << endl;

    return 0;
}