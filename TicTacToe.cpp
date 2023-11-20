#include <iostream>
#include <cstdlib>
#include <ctime>

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentPlayer = 'X';

// Function to draw the Tic Tac Toe board
void drawBoard() {
    std::cout << "Tic Tac Toe\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j];
            if (j < 2) std::cout << " | ";
        }
        std::cout << std::endl;
        if (i < 2) std::cout << "---------\n";
    }
    std::cout << std::endl;
}

// Function to check if a player has won
bool checkWin() {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true; // Check rows
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true; // Check columns
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true; // Check diagonal
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true; // Check diagonal
    return false;
}

// Function to check if the board is full (draw)
bool isBoardFull() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

// Function to switch players
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Function to make a move
void makeMove(int choice) {
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;
        switchPlayer();
    } else {
        std::cout << "Invalid move. Try again.\n";
    }
}

int main() {
    std::srand(std::time(0)); // Seed for random player start

    int choice;
    bool gameover = false;

    do {
        drawBoard();

        std::cout << "Player " << currentPlayer << ", enter a number (1-9): ";
        std::cin >> choice;

        makeMove(choice);

        if (checkWin()) {
            drawBoard();
            std::cout << "Player " << currentPlayer << " wins!\n";
            gameover = true;
        } else if (isBoardFull()) {
            drawBoard();
            std::cout << "It's a draw!\n";
            gameover = true;
        }

    } while (!gameover);

    return 0;
}
