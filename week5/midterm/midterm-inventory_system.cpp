#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

/*  The Product struct contains all the information about each product on the vector */
struct Product {
    string name;
    string sku;
    int quantity;
    double price;
    int reorderPoint;
    int salesCount = 0;
};

// Functions prototypes
void addProduct(vector<Product>& inventory);
void updateQuantity(vector<Product>& inventory);
void generateSale(vector<Product>& inventory);
void calculateInventory(const vector<Product>& inventory);
void generateSalesReport(const vector<Product>& inventory);
void displayMenu();
void validateInt(int &number);
void searchByName(const vector<Product>& inventory);

/*  I kept all the functions separate so the main could look cleaner
    I used the do/while loop so the menu would run at least once, displaying all the options 
    Opted for using the <vector> because it is a more dynamic data storage, an array would need a set size to work with
    */
int main() {
    vector<Product> productsList;
    int choice;

    do {
        displayMenu();
        cin >> choice;
        validateInt(choice);

        switch (choice) {
            case 1:
                addProduct(productsList);
                break;
            case 2:
                updateQuantity(productsList);
                break;
            case 3:
                generateSale(productsList);
                break;
            case 4:
                calculateInventory(productsList);
                break;
            case 5:
                generateSalesReport(productsList);
                break;
            case 6:
                searchByName(productsList);
                break;
            case 7:
            break;
            default: 
                cout << "Invalid choice! Please try again." << endl;
                break;      
        }

    } while (choice != 7);

    cout << "Exiting Program..." << endl;

    return 0;

}

// Simple function only to display the menu and keep the main shorter and cleaner
void displayMenu() {
    cout << "\n-----------------------" << endl;
    cout << "  Store Items Manager" << endl;
    cout << "-----------------------" << endl;
    cout << "Please select one of the following options: " << endl;

    cout << " 1. Add a product to the list. " << endl;
    cout << " 2. Update stock quatities. " << endl;
    cout << " 3. Register sale. " << endl;
    cout << " 4. Calculate total inventory value. " << endl;
    cout << " 5. Generate sales report. " << endl;
    cout << " 6. Search product by name. " << endl;
    cout << " 7. Exit Manager. " << endl;
    cout << " Enter your choice (1 - 7): ";

}

/*  Function that adds the products to the store inventory 
    Using cin.ignore because of the mix between getline and cin (string/int)
    Using the reference to the Product vector so the changes will be kept outside of the function
    The vector is more dynamic than the array, as this is user dependent on how many items they want to add this =>
    made more sense 
    */
void addProduct(vector<Product>& inventory) {
    Product p;
    cin.ignore(1000, '\n');

    cout << "Enter the product name: ";
    getline(cin, p.name);
    cout << "SKU: ";
    getline(cin, p.sku);
    cout << "Quantity: ";
    cin >> p.quantity;
    validateInt(p.quantity);
    while (p.quantity < 0) {
        cout << "Quantity cannot be negative" << endl;
        cin >> p.quantity;
        validateInt(p.quantity);
    }
    cout << "Price: ";
    cin >> p.price;
    cout << "Reorder threshold: ";
    cin >> p.reorderPoint;
    validateInt(p.reorderPoint);
    p.salesCount = 0;

    inventory.push_back(p);
    cout << "Product added successfully! " << endl;
}

/*  In this feature I opted to search by the SKU because it is a unique identifier in the system 
    While the name could be the same for two products the SKU should identify different products
    If the SKU is found, the function will validate if the quantity is a number and then it will update the quantity 
    in the inventory
*/
void updateQuantity(vector<Product>& inventory) {
    string targetSku;
    cout << "Enter the SKU to search for the product: ";
    cin >> targetSku;

    bool found = false;

    for (Product &p : inventory) {
        if (p.sku == targetSku) {
            found = true;
            cout << "Current quantity is: " << p.quantity << ". Enter new quantity: ";
            cin >> p.quantity;
            validateInt(p.quantity);
            break;
        }
    }
    if (!found) {
        cout << "Product with SKU: " << targetSku << " not found. " << endl;
    }
}

/*  Same logic, searching by the SKU to register the sale correctly 
    This function ensures the sold quantity is not higher than the quantity in stock 
    In a real store, this could not happen as you need to have the product in stock to sell it 
*/
void generateSale(vector<Product>& inventory) {
    string targetSku;
    int sold;
    cout << "Enter the SKU to search for the product: ";
    cin >> targetSku;

    bool found = false;

    for (Product &p : inventory) {
        if (p.sku == targetSku) {
            found = true;
            cout << "Enter amount sold: ";
            cin >> sold;
            validateInt(sold);
            while (sold > p.quantity) {
                cout << "Quantity cannot be negative! " << endl;
                cin >> sold;
                validateInt(sold);
            }

            p.quantity -= sold;

            if (p.quantity <= p.reorderPoint) {
                cout << "Warning: Stock for " << p.name << " is low. " << endl;
            }

            p.salesCount += sold;
            cout << "Sale registered" << endl;
            break;
        }
    }
    if (!found) {
        cout << "Product with SKU: " << targetSku << " not found. " << endl;
    }
}

/*  This loops through the inventory to display the total of products in stock plus the amount in dollars contained in 
    the inventory 
    It also alerts to any products with low stock. 
*/
void calculateInventory(const vector<Product>& inventory) {
    int totalUnits = 0;
    double totalValue = 0;

    cout << "\n-----------------------------" << endl;
    cout << "----- Inventory Summary -----" << endl;
    cout << "-----------------------------" << endl;
    for (const auto &p : inventory) {
        totalUnits += p.quantity;
        totalValue += (p.quantity * p.price);

        if (p.quantity <= p.reorderPoint) {
            cout << "ALERT: " << p.name << " (SKU: " << p.sku << ") is low! Current stock: " << p.quantity << endl;
        }
    }


    cout << "Total Units: " << totalUnits << endl;
    cout << "Total Value: $" << totalValue << endl;
}

/*  Loops through the whole inventory and displays all the products 
    It includes the ones without any registered sales also but it will calculate it's revenue to 0.00 
    It will calculate how many sales were done and the total revenue
*/
void generateSalesReport(const vector<Product>& inventory) {
    double totalRevenue = 0;

    cout << "\n------------------------------" << endl;
    cout << "---------SALES REPORT---------" << endl;
    cout << "------------------------------" << endl;

    for (const auto &p : inventory) {
        double productRevenue = p.salesCount * p.price;

        cout << "Product: " << p.name << endl;
        cout << "  - SKU: " << p.sku << endl;
        cout << "  - Units Sold: " << p.salesCount << endl;
        cout << "  - Revenue: $" << fixed << setprecision(2) << productRevenue << endl;
        cout << "------------------------------" << endl;

        totalRevenue += productRevenue;
    }

    cout << "Total Store Revenue: $" << totalRevenue << endl << endl;
}

/*  Uses cin fail to check if the input is the same kind as the program was expectig
    If not it will ask the user to input a new number, then check again if it is valid
    cin.ignore alone would only get rid of the first character, using the 1000 or '\n' option guarantees it will be cleared
    It will clear up to 1000 characters or until the new line 
    This is to prevent the program from crashing
*/
void validateInt(int &number) {
    while(cin.fail()) {
        cout << "That was not a valid number. Try Again!";

        cin.clear();
        cin.ignore(1000, '\n');
        cout << endl;

        cin >> number;
    }
}
// Simple function to transform a string in lowercase for comparisson 
string toLowerCase(string str) {
    for (char &c : str) {
        c = tolower(c);
    }

    return str;
}

/*  Search by name will display the product the manager asks for with all its features 
    Uses the toLowerCase function to be more accurate on the search 
*/
void searchByName(const vector<Product>& inventory) {
    string searchName;
    cin.ignore(1000, '\n');

    cout << "Enter product name to search: ";
    getline(cin, searchName);

    bool found = false;

    for (const Product &p : inventory) {
        if (toLowerCase(p.name) == toLowerCase(searchName)) {
            found = true;

            cout << "\nProduct found:\n";
            cout << "Name: " << p.name << endl;
            cout << "SKU: " << p.sku << endl;
            cout << "Quantity: " << p.quantity << endl;
            cout << "Price: $" << fixed << setprecision(2) << p.price << endl;
            cout << "Reorder Point: " << p.reorderPoint << endl;
            cout << "Sales Count: " << p.salesCount << endl;
            cout << "-----------------------------\n";
        }
    }

    if (!found) {
        cout << "No product with that name was found.\n";
    }
}

