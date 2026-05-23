#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

/*  Recipe struct to store recipes
    I added two vectors to store the ingredients and steps (dynamic sizes dependent on the user input)
*/
struct Recipe {
    string name;
    vector<string> ingredients;
    vector<string> steps;
};

// Function prototypes
void displayMenu();
void addRecipe(vector<Recipe>& recipeManager);
void displayRecipes(const vector<Recipe>& recipeManager);
void searchRecipe(const vector<Recipe>& recipeManager);
void deleteRecipe(vector<Recipe>& recipeManager);
void showStatistics(const vector<Recipe>& recipeManager);
void updateRecipe(vector<Recipe>& recipeManager);
void validateInt(int &number);
string toLowerCase(string str);

/*  I separated all the functions for better organization. Main only calls the menu and handles the main loop 
    I used the same logic as my midterm because they both use vectors 
*/
int main() {
    vector<Recipe> recipeManager;
    int choice;

    do {
        displayMenu();
        cin >> choice;
        validateInt(choice);

        switch (choice) {
            case 1:
                addRecipe(recipeManager);
                break;
            case 2:
                displayRecipes(recipeManager);
                break;
            case 3:
                searchRecipe(recipeManager);
                break;
            case 4:
                deleteRecipe(recipeManager);
                break;
            case 5:
                showStatistics(recipeManager);
                break;  
            case 6:
                updateRecipe(recipeManager);
                break;
            case 7:
                cout << "Exiting Recipe Manager..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 7);

    return 0;
}

/* This function is only  to display the menu options and keep main cleaner */
void displayMenu() {
    cout << "\n DYNAMIC RECIPE MANAGER" << endl;
    cout << "-----------------------" << endl;

    cout << "1. Add a new recipe" << endl;
    cout << "2. Display all recipes" << endl;
    cout << "3. Search for a recipe" << endl;
    cout << "4. Delete a recipe" << endl;
    cout << "5. Show statistics" << endl;
    cout << "6. Update a recipe" << endl;
    cout << "7. Exit" << endl;

    cout << "Enter your choice: ";
}

/*  The addRecipe function allows the user to input a new recipe with its name, ingredients and steps 
    It uses cin.ignore to clear the input buffer before using getline for the recipe name and ingredients
    The new recipe is added to the recipeManager vector, and the ingredients and steps are stored in their respective vectors within the Recipe struct
    I used two separate loops to get the ingredients and steps from the user, allowing for a dynamic number of each based on user input
*/
void addRecipe(vector<Recipe>& recipeManager) {
    Recipe newRecipe;
    cin.ignore(1000, '\n'); // Clear the input buffer

    cout << "\nEnter recipe name: ";
    getline(cin, newRecipe.name);

    cout << "How many ingredients?: ";
    int numIngredients;
    cin >> numIngredients;
    validateInt(numIngredients);
    cin.ignore(1000, '\n'); 

    for (int i = 0; i < numIngredients; ++i) {
        string ingredient;
        cout << "Ingredient " << (i + 1) << ": ";
        getline(cin, ingredient);
        newRecipe.ingredients.push_back(ingredient);
    }

    cout << "\nHow many steps? ";
    int numSteps;
    cin >> numSteps;
    validateInt(numSteps);
    cin.ignore(1000, '\n'); 

    for (int i = 0; i < numSteps; ++i) {
        string step;
        cout << "Step " << (i + 1) << ": ";
        getline(cin, step);
        newRecipe.steps.push_back(step);
    }

    recipeManager.push_back(newRecipe);
    cout << "\nRecipe added successfully!" << endl;
}

/*  The displayRecipes function shows all the recipes in the recipeManager vector
    It checks if the vector is empty and displays a message if so
    Otherwise, it iterates through the vector and displays each recipe's details
    I made nested loops so it could iterate through all the ingredients and steps for each recipe. It iterates through each vector
    It displays each ingredient and step in its own line for better readability
*/
void displayRecipes(const vector<Recipe>& recipeManager) {
    if (recipeManager.empty()) {
        cout << "\nNo recipes to display." << endl;
        return;
    }

    cout << "\n-- All Recipes --" << endl;
    for (int i = 0; i < recipeManager.size(); ++i) {
        cout << "\nRecipe " << (i + 1) << ": " << recipeManager[i].name << endl;

        cout << "Ingredients:\n";
        for (const string& ingredient : recipeManager[i].ingredients) {
            cout << "- " << ingredient << endl;
        }

        cout << endl;
        
        cout << "Steps:\n";
        for (const string& step : recipeManager[i].steps) {
            cout << "- " << step << endl;
        }
    }
}

// Simple function to transform a string in lowercase for comparisson 
string toLowerCase(string str) {
    for (char &c : str) {
        c = tolower(c);
    }

    return str;
}

/*  The searchRecipe function allows the user to search for a recipe by name
    It iterates through the recipeManager vector and displays the recipe if a match is found
    If no match is found, it displays a message indicating that the recipe was not found
    This uses the toLowerCase function to make the search case-insensitive
    I used nested loops to display the recipe if it is found with all its details (ingredients and steps)
*/
void searchRecipe(const vector<Recipe>& recipeManager) {
    if (recipeManager.empty()) {
        cout << "\nNo recipes to search." << endl;
        return;
    }

    cin.ignore(1000, '\n'); // Clear the input buffer
    cout << "\nEnter recipe name to search: ";
    string searchName;
    getline(cin, searchName);

    bool found = false;

    for (const Recipe& recipe : recipeManager) {
        if (toLowerCase(recipe.name) == toLowerCase(searchName)) {
            cout << "Recipe found!" << endl;

            cout << "Ingredients:\n" << endl;
            for (const string& ingredient : recipe.ingredients) {
                cout << "- " << ingredient << endl;
            }

            cout << "Steps:\n" << endl;
            for (const string& step : recipe.steps) {
                cout << "- " << step << endl;
            }

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Recipe not found." << endl;
    }
}

/*  The deleteRecipe function allows the user to delete a recipe by name
    It iterates through the recipeManager vector and removes the recipe if a match is found
    If no match is found, it displays a message indicating that the recipe was not found
    This also uses the toLowerCase function to make the search case-insensitive
    I used the vector's erase method to remove the recipe from the vector if it is found
*/
void deleteRecipe(vector<Recipe>& recipeManager) {
    if (recipeManager.empty()) {
        cout << "\nNo recipes to delete." << endl;
        return;
    }

    cin.ignore(1000, '\n'); // Clear the input buffer
    cout << "\nEnter recipe name to delete: ";
    string searchName;
    getline(cin, searchName);

    bool found = false;

    for (int i = 0; i < recipeManager.size(); ++i) {
        if (toLowerCase(recipeManager[i].name) == toLowerCase(searchName)) {
            recipeManager.erase(recipeManager.begin() + i);
            cout << "Recipe deleted successfully!" << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Recipe not found." << endl;
    }
}

/*  The showStatistics function displays the total number of recipes in the recipeManager vector
    It also calculates and displays the average number of ingredients per recipe
    If there are no recipes, it displays a message indicating that there are no statistics to show
*/
void showStatistics(const vector<Recipe>& recipeManager) {
    if (recipeManager.empty()) {
        cout << "\nNo recipes to show statistics." << endl;
        return;
    }

    int totalRecipes = recipeManager.size();
    int totalIngredients = 0;

    for (const Recipe& recipe : recipeManager) {
        totalIngredients += recipe.ingredients.size();
    }

    double averageIngredients = static_cast<double>(totalIngredients) / totalRecipes;

    cout << "\nTotal number of recipes: " << totalRecipes << endl;
    cout << "Average number of ingredients per recipe: " << averageIngredients << endl;
}

/*  Uses cin fail to check if the input is the same kind as the program was expectig
    If not it will ask the user to input a new number, then check again if it is valid
    It will clear up to 1000 characters or until the new line 
    This is to prevent the program from crashing
*/
void validateInt(int &number) {
    while(cin.fail()) {
        cout << "That was not a valid number. Try Again!";

        cin.clear();
        cin.ignore(1000, '\n');
        cout << endl;

        cout << "\nEnter a valid number: ";
        cin >> number;
    }
}

/*  Bonus Challenge: Update Recipe Details 
    This is a helper function to update the ingredients of a recipe, it is called in the updateRecipe function
    This function allows the user to update the ingredients of a recipe in case it is found in the updateRecipe function
    The user has two choices (Add/Remove)
    If the user chooses to add an ingredient, it prompts for the new ingredient and adds it to the recipe's ingredients vector
    If the user chooses to remove an ingredient, it prompts for the ingredient number to remove
    I found it easier to check the ingredient by its number because it seems easier than typing the whole ingredient accurately.
*/
void updateIngredients(Recipe& recipe) {
    cout << "\n1. Add an ingredient" << endl;
    cout << "2. Remove an ingredient" << endl;
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;
    validateInt(choice);
    cin.ignore(1000, '\n');

    if (choice == 1) {
        string newIngredient;
        cout << "\nEnter new ingredient: ";
        getline(cin, newIngredient);
        recipe.ingredients.push_back(newIngredient);
        cout << "Ingredient added successfully!" << endl;

    } else if (choice == 2) {
        int ingredientToRemove;
        cout << "\nEnter ingredient to remove: ";
        cin >> ingredientToRemove;
        validateInt(ingredientToRemove);

        for (int i = 0; i < recipe.ingredients.size(); ++i) {
            if (i == ingredientToRemove - 1) {
                recipe.ingredients.erase(recipe.ingredients.begin() + i);
                cout << "Ingredient removed successfully!" << endl;
                return;
            }
        }

        cout << "Ingredient not found." << endl;

    } else {
        cout << "Invalid choice." << endl;
    }
}

/*  Same logic as the updateIngredients function above
    The user has two options (Add/Remove) a step
    If the user chooses to add a step, it prompts for the new step and adds it to the recipe's steps vector
    If the user chooses to remove a step, it prompts for the step number to remove
    I found it easier to check the step by its number because it seems easier than typing the whole step accurately.
*/
void updateSteps(Recipe& recipe) {
    cout << "\n1. Add a step" << endl;
    cout << "2. Remove a step" << endl;
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;
    validateInt(choice);
    cin.ignore(1000, '\n');

    if (choice == 1) {
        string newStep;
        cout << "\nEnter new step: ";
        getline(cin, newStep);
        recipe.steps.push_back(newStep);
        cout << "Step added successfully!" << endl;

    } else if (choice == 2) {
        int stepToRemove;
        cout << "\nEnter step to remove: ";
        cin >> stepToRemove;
        validateInt(stepToRemove);

        for (int i = 0; i < recipe.steps.size(); ++i) {
            if (i == stepToRemove - 1) { 
                recipe.steps.erase(recipe.steps.begin() + i);
                cout << "Step removed successfully!" << endl;
                return;
            }
        }

        cout << "Step not found." << endl;

    } else {
        cout << "Invalid choice." << endl;
    }
}

void updateRecipe(vector<Recipe>& recipeManager) {
    if (recipeManager.empty()) {
        cout << "\nNo recipes to update." << endl;
        return;
    }

    cin.ignore(1000, '\n'); // Clear the input buffer
    cout << "\nEnter recipe name to update: ";
    string searchName;
    getline(cin, searchName);

    bool found = false;

    for (Recipe& recipe : recipeManager) {
        if (toLowerCase(recipe.name) == toLowerCase(searchName)) {
            cout << "Recipe found! What would you like to update?" << endl;
            cout << "1. Name" << endl;
            cout << "2. Ingredients" << endl;
            cout << "3. Steps" << endl;
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            validateInt(choice);
            cin.ignore(1000, '\n'); 

            switch (choice) {
                case 1:
                    cout << "Enter new name: ";
                    getline(cin, recipe.name);
                    break;
                case 2:
                    updateIngredients(recipe);
                    break;
                case 3:
                    updateSteps(recipe);
                    break;
                default:
                    cout << "Invalid choice." << endl;
            }
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Recipe not found." << endl;
    }
}
