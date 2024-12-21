// Week 05: Programming Assignment #1
// Lukaman Islam
// any example usage or helpful command line arguments go here

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// Constants for surfboard prices
const double SMALL_COST = 175.00;
const double MEDIUM_COST = 190.00;
const double LARGE_COST = 200.00;

// Function prototypes
void ShowUsage();
void MakePurchase(int& totalSmall, int& totalMedium, int& totalLarge);
void DisplayPurchase(const int totalSmall, const int totalMedium, const int totalLarge);
void DisplayTotal(const int totalSmall, const int totalMedium, const int totalLarge);

int main() {
    int totalSmall = 0, totalMedium = 0, totalLarge = 0; // Variables to track surfboards sold
    char choice; // User's menu selection

    // Program header
    cout << "\n***** Welcome to my Johnny Utah's PointBreak Surf Shop *****\n";
    cout << "***********************************************************\n";

    ShowUsage(); // Display usage instructions

    do {
        cout << "\nPlease enter selection: ";
        cin >> choice; // Get user input
        choice = tolower(choice); // Convert to lowercase for simplicity

        switch (choice) {
        case 's': // Show program usage
            ShowUsage();
            break;
        case 'p': // Make a purchase
            MakePurchase(totalSmall, totalMedium, totalLarge);
            break;
        case 'c': // Display current purchases
            DisplayPurchase(totalSmall, totalMedium, totalLarge);
            break;
        case 't': // Display total sales and revenue
            DisplayTotal(totalSmall, totalMedium, totalLarge);
            break;
        case 'q': // Quit the program
            cout << "Thank you for visiting Johnny Utah's PointBreak Surf Shop!\n";
            // Write summary to file
            {
                ofstream outFile("total.dat");
                if (outFile) {
                    outFile << "Surfboard Purchase Summary\n";
                    outFile << "Small surfboards: " << totalSmall << endl;
                    outFile << "Medium surfboards: " << totalMedium << endl;
                    outFile << "Large surfboards: " << totalLarge << endl;
                    outFile << fixed << setprecision(2)
                        << "Total Revenue: $" << (totalSmall * SMALL_COST + totalMedium * MEDIUM_COST + totalLarge * LARGE_COST) << endl;
                    outFile.close();
                    cout << "Summary successfully written to 'total.dat'.\n";
                }
                else {
                    cerr << "Error: Unable to write to 'total.dat'.\n";
                }
            }
            break;
        default: // Invalid input
            cout << "Invalid selection. Please try again.\n";
        }
    } while (choice != 'q'); // Exit loop when user enters 'q'

    return 0;
}

// Function to display usage instructions
void ShowUsage() {
    cout << "\nTo show program usage, press 'S'\n";
    cout << "To purchase a surfboard, press 'P'\n";
    cout << "To display current purchases, press 'C'\n";
    cout << "To display total amount due, press 'T'\n";
    cout << "To quit the program, press 'Q'\n";
}

// Function to handle surfboard purchases
void MakePurchase(int& totalSmall, int& totalMedium, int& totalLarge) {
    char size;
    int quantity;

    cout << "Please enter the quantity and type (S=small, M=medium, L=large) of surfboard you would like to purchase: ";
    cin >> quantity >> size;

    size = tolower(size); // Convert size to lowercase for consistency

    // Validate the input
    if (quantity <= 0) {
        cout << "Invalid quantity. Please try again.\n";
        return;
    }

    if (size == 's') {
        totalSmall += quantity;
    }
    else if (size == 'm') {
        totalMedium += quantity;
    }
    else if (size == 'l') {
        totalLarge += quantity;
    }
    else {
        cout << "Invalid size selected. Please try again.\n";
    }
}

// Function to display current purchases
void DisplayPurchase(const int totalSmall, const int totalMedium, const int totalLarge) {
    cout << "\n";
    if (totalSmall == 0 && totalMedium == 0 && totalLarge == 0) {
        cout << "No purchases made yet.\n";
    }
    else {
        if (totalSmall > 0) {
            cout << "The total number of small surfboards is " << totalSmall << endl;
        }
        if (totalMedium > 0) {
            cout << "The total number of medium surfboards is " << totalMedium << endl;
        }
        if (totalLarge > 0) {
            cout << "The total number of large surfboards is " << totalLarge << endl;
        }
    }
}

// Function to display total revenue
void DisplayTotal(const int totalSmall, const int totalMedium, const int totalLarge) {
    double smallTotal = totalSmall * SMALL_COST;
    double mediumTotal = totalMedium * MEDIUM_COST;
    double largeTotal = totalLarge * LARGE_COST;
    double grandTotal = smallTotal + mediumTotal + largeTotal;

    cout << "\n";
    if (totalSmall == 0 && totalMedium == 0 && totalLarge == 0) {
        cout << "No purchases made yet.\n";
    }
    else {
        if (totalSmall > 0) {
            cout << "The total number of small surfboards is " << totalSmall << " at a total of $" << fixed << setprecision(2) << smallTotal << endl;
        }
        if (totalMedium > 0) {
            cout << "The total number of medium surfboards is " << totalMedium << " at a total of $" << fixed << setprecision(2) << mediumTotal << endl;
        }
        if (totalLarge > 0) {
            cout << "The total number of large surfboards is " << totalLarge << " at a total of $" << fixed << setprecision(2) << largeTotal << endl;
        }
        cout << "Amount due: $" << fixed << setprecision(2) << grandTotal << endl;
    }
}
