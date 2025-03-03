\* student name : Trakouri Roberson *\
#ifndef Investment.h
#define Investment.h
#include <iostream>


using namespace std;

// investment Header File
// This header defines all functions required to calculate and display investment details.

// Function to display the initial investment details entered by the user
// Parameters:
// - P: Initial investment amount
// - monthlyDeposit: The amount deposited each month
// - r: Annual interest rate (as a decimal)
// - t: Number of years the investment is held
void displayInitialScreen(double P, double monthlyDeposit, double r, int t);

// Function to generate and display a yearly report without additional monthly deposits
// It calculates year-end balances and earned interest based solely on initial investment and interest
// Parameters:
// - P: Initial investment amount
// - r: Annual interest rate (as a decimal)
// - t: Number of years the investment is held
// - monthlyDeposit: Monthly deposit amount (not used in this function)
void displayYearEndReport(double P, double r, int t, double monthlyDeposit);

// Function to generate and display a yearly report with additional monthly deposits
// It calculates year-end balances and earned interest considering both deposits and interest
// Parameters:
// - P: Initial investment amount
// - r: Annual interest rate (as a decimal)
// - t: Number of years the investment is held
// - monthlyDeposit: Monthly deposit amount added to the balance
void displayYearEndReportWithDeposits(double P, double r, int t, double monthlyDeposit);

// Function to generate and display a detailed monthly breakdown of investment growth
// It includes opening balance, deposited amount, interest earned, and closing balance for each month
// Parameters:
// - P: Initial investment amount
// - r: Annual interest rate (as a decimal)
// - t: Number of years the investment is held
// - monthlyDeposit: Monthly deposit amount added to the balance
void displayMonthlyReport(double P, double r, int t, double monthlyDeposit);

#endif // Investment.h 
