/*
Rosolino Mangano
CIS 3100
Professor Jairam
05/05/2024
*/

#include <iostream>

using namespace std;

// Defining variables:
const int GRID_SIZE = 5; // Define the size of the game grid
const char EMPTY = '-'; // Character to represent an empty cell
const char SHIP = 'S'; // Character to represent a ship
const char HIT = 'X'; // Character to represent a hit on a ship
const char MISS = 'O'; // Character to represent a miss

// Function prototypes:
void printGrid(const char grid[GRID_SIZE][GRID_SIZE]);
void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]);
void placeShips(char grid[GRID_SIZE][GRID_SIZE], int shipCount);
bool makeGuess(char grid[GRID_SIZE][GRID_SIZE], int row, int col);
void computerTurn(char grid[GRID_SIZE][GRID_SIZE]);
bool checkWin(const char grid[GRID_SIZE][GRID_SIZE]);
void playGame();
void showInstructions();

int main() {
    char choice; // Variable to store user menu choice
    do {
        cout << "1. Start New Game\n2. Show Instructions\n3. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case '1':
                playGame(); // Start a new game
                break;
            case '2':
                showInstructions(); // Show game instructions
                break;
            case '3':
                cout << "Exiting the game.\n"; // Exit the game
                break;
            default:
                cout << "Invalid choice. Please try again.\n"; // Handle invalid input
        }
    } while (choice != '3');
    return 0;
}

// Prints the current state of the grid:
void printGrid(const char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

// Initializes the grid by filling it with empty cells:
void initializeGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = EMPTY;
        }
    }
}

// Randomly places a specified number of ships on the grid:
void placeShips(char grid[GRID_SIZE][GRID_SIZE], int shipCount) {
    int placed = 0;
    while (placed < shipCount) {
        int row = rand() % GRID_SIZE;
        int col = rand() % GRID_SIZE;
        if (grid[row][col] == EMPTY) {
            grid[row][col] = SHIP;
            placed++;
        }
    }
}

// Allows the user or computer to guess a location on the grid:
bool makeGuess(char grid[GRID_SIZE][GRID_SIZE], int row, int col) {
    if (grid[row][col] == SHIP) {
        grid[row][col] = HIT;
        return true;
    } else if (grid[row][col] == EMPTY) {
        grid[row][col] = MISS;
        return false;
    }
    return false;
}

// Handles the computer's turn to make a guess:
void computerTurn(char playerGrid[GRID_SIZE][GRID_SIZE]) {
    int row, col;
    do {
        row = rand() % GRID_SIZE;
        col = rand() % GRID_SIZE;
    } while (playerGrid[row][col] == HIT || playerGrid[row][col] == MISS);
    makeGuess(playerGrid, row, col);
}

// Checks if all ships on the grid have been sunk:
bool checkWin(const char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == SHIP) return false;
        }
    }
    return true;
}

// Main game logic to control the flow of a single game:
void playGame() {
    char playerGrid[GRID_SIZE][GRID_SIZE], computerGrid[GRID_SIZE][GRID_SIZE];
    initializeGrid(playerGrid);
    initializeGrid(computerGrid);

    placeShips(playerGrid, 5);  // Player places 5 ships
    placeShips(computerGrid, 5);  // Computer places 5 ships

    bool gameOver = false;
    while (!gameOver) {
        int row, col;
        printGrid(playerGrid);  // Optionally show the player grid
        cout << "Enter row and column to hit (0-4): ";
        cin >> row >> col;
        if (!makeGuess(computerGrid, row, col)) {
            computerTurn(playerGrid);
        }
        if (checkWin(computerGrid)) {
            cout << "You won!\n";
            gameOver = true;
        } else if (checkWin(playerGrid)) {
            cout << "Computer won!\n";
            gameOver = true;
        }
    }
}

// Displays game instructions:
void showInstructions() {
    cout << "Instructions:\n"
         << "- Both the player and the computer have a 5x5 grid.\n"
         << "- Each player places 5 ships on their grid.\n"
         << "- Players take turns guessing locations on the opponent's grid.\n"
         << "- A hit is marked with an 'X', a miss with an 'O'.\n"
         << "- First to sink all opponent's ships wins.\n";
}
