/*
Rosolino Mangano
CIS 3100
Professor Jairam
05/05/2024
*/

#include <iostream>
using namespace std;

// Function Prototypes:
void print2Darray(char[][3], int, int);
bool checkWin(char[][3]);
bool checkDraw(char[][3]);
void playerMove(char[][3], char);

int main() {
    
    char choice;
    
    // Game loop:
    do {
        // Initialize the game board with all cells empty: ('-')
        char grid[3][3] = {
                            { '-', '-', '-' },
                            { '-', '-', '-' },
                            { '-', '-', '-' }
        };

        // Print the initial empty board:
        cout << "\n\n";
        print2Darray(grid, 3, 3);

        // Initialize the first player to 'X':
        char currentPlayer = 'X';
        bool gameOver = false;

        // Continue playing until the game is over:
        while (!gameOver) {
            
            // Handle the current player's move:
            playerMove(grid, currentPlayer);
            cout << "\n\n";
            print2Darray(grid, 3, 3);
            
            // Check for win condition after the move:
            if (checkWin(grid)) {
                cout << "Player " << currentPlayer << " wins!\n";
                gameOver = true;
                
            // Check for draw condition (no more moves possible):
            } else if (checkDraw(grid)) {
                cout << "It's a draw!\n";
                gameOver = true;
            }
            
            // Switch to the other player:
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        // After the game ends, ask if players want to play again:
        cout << "1. Play again\n2. Exit\nEnter your choice: ";
        cin >> choice;
    } while (choice != '2');

    return 0;
}

// Function to print the current state of the Tic Tac Toe board:
void print2Darray(char arr[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check for a win by examining all rows, columns, and diagonals:
bool checkWin(char grid[][3]) {
    for (int i = 0; i < 3; i++) {
        if ((grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][0] != '-') ||
            (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[0][i] != '-'))
            return true;
    }
    if ((grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != '-') ||
        (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] != '-'))
        return true;
    
    return false;
}

// Function to check if the board is completely filled without any winner:
bool checkDraw(char grid[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] == '-')
                return false;
        }
    }
    return true;
}

// Function to handle player moves by ensuring they choose an empty cell within bounds:
void playerMove(char grid[][3], char player) {
    int row, col;
    do {
        cout << "Player " << player << ": Enter the row & col numbers for your move (0-2): ";
        cin >> row >> col;
    } while (row < 0 || row > 2 || col < 0 || col > 2 || grid[row][col] != '-');
    grid[row][col] = player;
}
