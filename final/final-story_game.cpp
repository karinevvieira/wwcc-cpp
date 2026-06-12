/*
 * Interactive Story Game - Dwarves and Turnips
 * Author: Karine Vieira
 * Date: 06/12/2026
 *
 * ==== Project Features ====
 * Variables (3+ types): Lines 34, 35, 48
 * If/else: Lines 133, 142, 146, 154, 164, 181, 188, 223, 227, 235, 239, 246, 248, 250.
 * Switch: Line 62, 217
 * Loop: Lines 208, 215
 * Function w/ return value: Line 48, 122
 * Void function: Line 99, 108
 * Function w/ parameters: Line 99, 108
 * Vector or array: Lines 45
 * Struct or class: Lines 33
 * Enum: Lines 38
 * File reading: Lines 199
 * File writing: Lines 244
 * Modern feature 1 (vector): Lines 45
 * Modern feature 2 (range-based for loop): Lines 112, 255
 * ==========================
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <vector>
#include <fstream>

using namespace std;

struct Inventory {
    string name;
    int quantity;
};

enum class GameState
{
    INTRO,
    WIN,
    LOSE
};

vector <Inventory> items;
GameState state = GameState::INTRO;

bool dwarfRiddle()
{
    int choice;

    cout << "The fat dwarf whispers in the ear of the skinny one before replying:\n";
    cout << "\"How many turnips could you purchase with the GDP of this region?\"\n\n";

    cout << "1. The GDP overall or the GDP per capita?\n";
    cout << "2. Ask the dwarf to define GDP.\n";
    cout << "3. Use your years of turnip farming to estimate the answer.\n";
    cout << "4. Look to the aristocrat for help.\n";

    cin >> choice;

    switch(choice)
    {
        case 1:
            cout << "\nThe dwarves immediately begin arguing amongst themselves "
                 << "about whether GDP means Gross Domestic Product or "
                 << "General Dwarf Product.\n\n";

            cout << "After several minutes they admit they do not know the answer.\n";
            cout << "\"You're probably close enough,\" says the fat dwarf.\n";
            return true;

        case 2:
            cout << "\nYou ask the dwarf to define GDP.\n";
            cout << "The two dwarves stare blankly at each other.\n";
            cout << "An argument breaks out.\n";
            cout << "\"You may pass,\" they finally declare.\n";
            return true;

        case 3:
            cout << "\nYou begin calculating based on years of turnip farming.\n";
            cout << "After a long explanation involving crop yields and taxes,\n";
            cout << "the dwarves become confused and wave you through.\n";
            return true;

        case 4:
            cout << "\nYou look to the aristocrat for help.\n";
            cout << "\"I have absolutely no idea,\" he replies.\n";
            cout << "The dwarves laugh so hard they forget the riddle entirely.\n";
            cout << "You are allowed to pass.\n";
            return true;

        default:
            cout << "\nUnable to answer, you remain trapped at the mountain pass.\n";
            return false;
    }
}

void addItem(vector <Inventory>& items, string i){
    Inventory item;

    item.name = i;
    item.quantity = 1;

    items.push_back(item);
}

void showInventory(const vector<Inventory>& items)
{
    cout << "\nInventory:\n";

    for (const auto& item : items)
    {
        cout << "- "
             << item.name
             << " x"
             << item.quantity
             << endl;
    }
}

GameState pathAccept() {
    int choice1;
    int choice2;
    int choice3;
    cout << "You accept his proposal. He tells you to meet at the castle gates at dusk" << endl;
    cout << "Your settlement is bordered by a costal region and a large mountain range. In addition to basic provisions you purchase: " << endl;
    cout << "1. Simple moutainering equipament." << endl;
    cout << "2. Maritime navigational equipament." << endl;
    cout << "What is your choice? ";
    cin >> choice1;

    if (choice1 == 1) {
        addItem(items, "Moutaineering Equipament");
        showInventory(items);
        cout << "The handsome aristocrat meets you at the castle gate and informs you that you are traveling across the Carmillion sea. You travel together to a small coastal city. He gives you 30 gold to purchase a ship while he procures supplies " << endl;
        cout << "1. This is more money than you have ever seen before in your life. You take it an leave the city as quickly as possible" << endl;
        cout << "2. You go to the harbor and begin haggling with a particularly rotund sailor. The negotiations become heated as the sailor is slightly intoxicated. " << endl;
        cout << "What is your choice? ";
        cin >> choice2;

        if (choice2 == 1) {
            cout << "Your reputation is irreperably damaged and so you choose to start a new life somewhere far away from here. Fortunately, the gold buys you passage across the sea and a comfortable life in exile." << endl;
            return GameState::WIN;
        }
        else {
            cout << "You go to the harbor and begin haggling with a particularly rotund sailor. The negotiations become heated as the sailor is slightly intoxicated. " << endl;
            cout << "Insult the sailors weight and turn to look for another to bargain with" << endl;
            cout << "The sailor hits you over the head with an oar" << endl;
            cout << "The strike knocks you unconcsious and you fall off the dock into the harbor and drown. YOU ARE DEAD" << endl;
            return GameState::LOSE;
        }
    }
    else {
        addItem(items, "Navigation Equipament");
        showInventory(items);
        cout << "The handsome aristocrat meets you at the castle gate and informs you that you are traveling across the Takur Gar Mountain range. He purchases two horses and you begin traveling west " << endl;
        cout << "You arrive at the mountain pass crossing where your path is blocked by two dwarves. They demand you answer their riddles in order to pass" << endl;
        cout << "1. You accept their offer and ask for the first riddle" << endl;
        cout << "2. You decline to waste time here and challenge the Dwarves to combat" << endl;
        cout << "What is your choice? ";
        cin >> choice3;

        if (choice3 == 1) {
            if(dwarfRiddle()) {
                cout << "\nThe dwarves step aside.\n";

                cout << "Beyond the pass lies an ancient shrine carved into the mountain.\n";

                 cout << "The handsome aristocrat finally reveals his purpose.\n";

                cout << "\"I seek the Crown of Aurelion, lost for centuries.\"\n";

                cout << "Together you recover the relic.\n";

                cout << "The aristocrat rewards you with enough gold to live freely.\n";

                cout << "YOU WIN\n";
                return GameState::WIN;
            }
            else
            {
                cout << "The dwarves refuse to let you pass.\n";
                cout << "YOU ARE DEAD\n";
                return GameState::LOSE;
            }
        }
        else {
            cout << "The handsome stranger pulls out an exceptionally well crafted greatsword and charges between you and the dwarves. They vanish in an instant and you feel something cold press into your back. The handsome stranger turns around and the last thing you remember is the look of sorrow on his face as you collapse to the ground lifeless, stabbed in the back by a magic dagger." << endl;
            cout << "YOU ARE DEAD" << endl;
            return GameState::LOSE;
        }
    }
}


int main() {

    ifstream inFile("intro.txt");

    if (!inFile) {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

    string line;

    while(getline(inFile,line))
    {
        cout << line << endl;
    }

    int introChoice;

    while (state != GameState::WIN && state != GameState:: LOSE)
    {
        switch(state) {
            case GameState::INTRO:
            cout << "\n1. Accept the offer\n";
            cout << "2. Refuse the offer\n";
            cin >> introChoice;

            if (introChoice == 1) {
                state = pathAccept();
            }

            else {
                cout << "You remain in debt for the rest of your life." << endl;
                state = GameState::LOSE;
            }
            break;
        }
    }

    if(state == GameState::WIN)
    {
        cout << "Congratulations!" << endl;
    }
    else
    {
        cout << "YOU LOSE" << endl;
    }

    ofstream outFile("summary.txt");

    if(outFile)
    {
        if(state == GameState::WIN)
            outFile << "Ending: Victory\n";
        else
            outFile << "Ending: Death\n";

        outFile << "\nInventory:\n";

        for(const auto& item : items)
        {
            outFile << item.name
                    << " x"
                    << item.quantity
                    << endl;
        }
    }


    return 0;
}


