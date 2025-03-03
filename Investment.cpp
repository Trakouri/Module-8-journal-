\* student name : Trakouri Roberson *\
#include "Investment.h"

using namespace std;

// Function to display initial investment information
void displayInitialScreen(double P, double monthlyDeposit, double r, int t) {
    // Display the application title and user input details
    cout << "**********************************" << endl;
    cout << "*      AIRGEAD BANKING APP       *" << endl;
    cout << "**********************************" << endl;
    cout << "Initial Investment Amount: $" << fixed << setprecision(2) << P << endl;
    cout << "Monthly Deposit: $" << monthlyDeposit << endl;
    cout << "Annual Interest (Compounded): " << r * 100 << "%" << endl;
    cout << "Number of Years: " << t << endl;
    cout << "Press any key to continue...";
    cin.ignore();
    cin.get(); // Wait for user input before proceeding
}

// Function to display year-end reports
void displayYearEndReport(double P, double r, int t, double monthlyDeposit) {
    // Variables to store balances
    double balanceWithoutDeposits = P;
    double balanceWithDeposits = P;

    // Display the year-end report without deposits
    cout << "\n*************************************************" << endl;
    cout << "*     Year-End Balances Without Deposits       *" << endl;
    cout << "*************************************************" << endl;
    cout << "Year\tYear-End Balance\tYear-End Earned Interest" << endl;
    cout << "-------------------------------------------------" << endl;

    // Calculate and display balances without monthly deposits
    for (int year = 1; year <= t; year++) {
        double interestWithoutDeposits = balanceWithoutDeposits * r;
        balanceWithoutDeposits += interestWithoutDeposits; // Update the balance
        cout << year << "\t$" << fixed << setprecision(2) << balanceWithoutDeposits
             << "\t$" << interestWithoutDeposits << endl;
    }

    // Display the year-end report with monthly deposits
    cout << "\n*************************************************" << endl;
    cout << "*     Year-End Balances With Monthly Deposits   *" << endl;
    cout << "*************************************************" << endl;
    cout << "Year\tYear-End Balance\tYear-End Earned Interest" << endl;
    cout << "-------------------------------------------------" << endl;

    // Calculate and display balances with monthly deposits
    for (int year = 1; year <= t; year++) {
        double interestWithDeposits = 0;
        for (int month = 1; month <= 12; month++) {
            // Calculate monthly interest and update balance
            interestWithDeposits += (balanceWithDeposits + monthlyDeposit) * (r / 12);
            balanceWithDeposits += monthlyDeposit;
            balanceWithDeposits += interestWithDeposits;
        }
        cout << year << "\t$" << fixed << setprecision(2) << balanceWithDeposits
             << "\t$" << interestWithDeposits << endl;
    }
}

// Function to display monthly investment growth reports
void displayMonthlyReport(double P, double r, int t, double monthlyDeposit) {
    double balance = P;

    // Display header for monthly reports
    cout << "\n************************************************************" << endl;
    cout << "*     Monthly Balances With and Without Deposits         *" << endl;
    cout << "************************************************************" << endl;
    cout << "Month\tOpening Amount\tDeposited Amount\tInterest\tClosing Balance" << endl;
    cout << "----------------------------------------------------------------------------" << endl;

    // Calculate and display monthly details
    for (int month = 1; month <= t * 12; month++) {
        double interest = (balance + monthlyDeposit) * (r / 12);
        double closingBalance = balance + monthlyDeposit + interest;
        cout << month << "\t$" << fixed << setprecision(2) << balance
             << "\t$" << monthlyDeposit << "\t$" << interest
             << "\t$" << closingBalance << endl;
        balance = closingBalance; // Update balance for next iteration
    }
}

int main() {
    double P, r, monthlyDeposit; // User inputs: principal, interest rate, monthly deposit
    int t; // Investment duration in years
    char choice; // User's choice to recalculate or exit

    do {
        // Prompt user for input values
        cout << "Enter Initial Investment Amount ($): ";
        cin >> P;
        cout << "Enter Annual Interest Rate (%): ";
        cin >> r;
        r /= 100; // Convert percentage to decimal
        cout << "Enter Number of Years: ";
        cin >> t;
        cout << "Enter Monthly Deposit Amount ($): ";
        cin >> monthlyDeposit;

        // Call functions to display investment details and reports
        displayInitialScreen(P, monthlyDeposit, r, t);
        displayMonthlyReport(P, r, t, monthlyDeposit);
        displayYearEndReport(P, r, t, monthlyDeposit);

        // Ask user if they want to test different inputs
        cout << "\nWould you like to test a different monthly deposit, interest rate, or time period? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y'); // Continue if user chooses 'y'

    // Exit message
    cout << "\nThank you for using the Investment Calculator!" << endl;
    return 0;
}