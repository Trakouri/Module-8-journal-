\* student name : Trakouri Roberson *\
#include <limits>


using namespace std;

// Function to validate user input
double validateInput(const string& prompt, const string& errorMessage, double minValue = 0) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;

        // Check if input is valid and meets the minimum value condition
        if (cin.fail() || value < minValue) {
            cout << errorMessage << endl;

            // Clear input and ignore invalid characters
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
            return value; // Return valid input
        }
    }
}

// Function to display initial investment information
void displayInitialScreen(double P, double monthlyDeposit, double r, int t) {
    cout << "**********************************" << endl;
    cout << "*      AIRGEAD BANKING APP       *" << endl;
    cout << "**********************************" << endl;
    cout << "Initial Investment Amount: $" << fixed << setprecision(2) << P << endl;
    cout << "Monthly Deposit: $" << monthlyDeposit << endl;
    cout << "Annual Interest (Compounded): " << r * 100 << "%" << endl;
    cout << "Number of Years: " << t << endl;
    cout << "Press any key to continue...";
    cin.get();
}

// Function to display year-end reports
void displayYearEndReport(double P, double r, int t, double monthlyDeposit) {
    // Same content as before
    // ...
}

// Function to display monthly reports
void displayMonthlyReport(double P, double r, int t, double monthlyDeposit) {
    // Same content as before
    // ...
}

int main() {
    double P, r, monthlyDeposit; // User inputs
    int t; // Investment duration in years
    char choice; // User's choice to recalculate or exit

    do {
        // Validate user inputs
        P = validateInput("Enter Initial Investment Amount ($): ", 
         "Invalid input. Please enter a positive amount greater than or equal to 0.", 0);
        r = validateInput("Enter Annual Interest Rate (%): ", 
         "Invalid input. Please enter a positive rate greater than 0.", 0) / 100; // Convert to decimal
        t = static_cast<int>(validateInput("Enter Number of Years: ", 
        
          "Invalid input. Please enter an integer greater than 0.", 1));
        monthlyDeposit = validateInput("Enter Monthly Deposit Amount ($): ", 
                                     
          "Invalid input. Please enter a positive amount greater than or equal to 0.", 0);

        // Call functions to display details and reports
        displayInitialScreen(P, monthlyDeposit, r, t);
        displayMonthlyReport(P, r, t, monthlyDeposit);
        displayYearEndReport(P, r, t, monthlyDeposit);

        // Ask user if they want to test again
        cout << "\nWould you like to test a different monthly deposit, interest rate, or time period? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    // Exit message
    cout << "\nThank you for using the Investment Calculator!" << endl;
    return 0;
}