/*
Rosolino Mangano
CIS 3100
Professor Jairam
05/05/2024
*/

#include <iostream>
#include <string>

using namespace std;

// Constants for portfolio dimensions:
const int MAX_STOCKS = 10;
const int ATTRIBUTES = 4;  // Includes Symbol, Number of Shares, Purchase Price, Current Price

// Global portfolio array to hold stock information:
string portfolio[MAX_STOCKS][ATTRIBUTES];
int stockCount = 0;  // Counter to track the number of stocks currently in the portfolio

// Function to add a stock to the portfolio:
void addStock() {
    if (stockCount >= MAX_STOCKS) {
        cout << "Portfolio is full. Cannot add more stocks.\n";
        return;
    }

    string symbol, shares, purchasePrice;
    cout << "Enter stock symbol: ";
    cin >> symbol;
    // Check if stock already exists in the portfolio
    for (int i = 0; i < stockCount; i++) {
        if (portfolio[i][0] == symbol) {
            cout << "Stock symbol already exists in the portfolio.\n";
            return;
        }
    }

    // Get stock details from user:
    cout << "Enter number of shares: ";
    cin >> shares;
    cout << "Enter purchase price: ";
    cin >> purchasePrice;

    // Add the new stock to the portfolio:
    portfolio[stockCount][0] = symbol;
    portfolio[stockCount][1] = shares;
    portfolio[stockCount][2] = purchasePrice;
    portfolio[stockCount][3] = "100";  // Assign a mock current price for simplicity
    stockCount++;
    cout << "Stock added successfully.\n";
}

// Function to delete a stock from the portfolio:
void deleteStock() {
    if (stockCount == 0) {
        cout << "Portfolio is empty.\n";
        return;
    }

    string symbol;
    cout << "Enter stock symbol to delete: ";
    cin >> symbol;
    
    // Find and remove the stock by shifting others down:
    for (int i = 0; i < stockCount; i++) {
        if (portfolio[i][0] == symbol) {
            for (int j = i; j < stockCount - 1; j++) {
                for (int k = 0; k < ATTRIBUTES; k++) {
                    portfolio[j][k] = portfolio[j + 1][k];
                }
            }
            stockCount--;
            cout << "Stock deleted successfully.\n";
            return;
        }
    }
    cout << "Stock symbol not found.\n";
}

// Function to display all stocks in the portfolio:
void viewPortfolio() {
    if (stockCount == 0) {
        cout << "Portfolio is empty.\n";
        return;
    }

    cout << "Current Portfolio:\n";
    cout << "Symbol\tShares\tPurchase Price\tCurrent Price\n";
    for (int i = 0; i < stockCount; i++) {
        for (int j = 0; j < ATTRIBUTES; j++) {
            cout << portfolio[i][j] << "\t";
        }
        cout << endl;
    }
}

// Function to calculate the total value of the portfolio:
void calculateTotalValue() {
    double totalValue = 0;
    for (int i = 0; i < stockCount; i++) {
        double shares = stod(portfolio[i][1]);  // Convert string to double
        double currentPrice = stod(portfolio[i][3]);  // Convert string to double
        totalValue += shares * currentPrice;  // Calculate value of each stock and add to total
    }
    cout << "Total Portfolio Value: $" << totalValue << endl;
}

// Main function to handle user interactions and execute menu choices:
int main() {
    char choice;
    do {
        cout << "1. Add Stock\n2. Delete Stock\n3. View Portfolio\n4. Calculate Total Value\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case '1':
                addStock();  // Handles adding a stock
                break;
            case '2':
                deleteStock();  // Handles deleting a stock
                break;
            case '3':
                viewPortfolio();  // Displays the entire portfolio
                break;
            case '4':
                calculateTotalValue();  // Calculates and display the total portfolio value
                break;
            case '5':
                cout << "Exiting the program.\n";  // Exits the program
                break;
            default:
                cout << "Invalid choice. Please try again.\n";  // Handles invalid input
        }
    } while (choice != '5');
    return 0;
}
