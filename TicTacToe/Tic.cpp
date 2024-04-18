#include <iostream>

// Function to update the game board with player's move
void playerMovement(char board[3][3], int row, int col, char currentPlayer) {
    board[row][col] = currentPlayer;
}

// Function to check if the current player has won
bool checkWinner(char board[3][3], char currentPlayer) {
    // Check rows and columns for a win
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true; // Horizontal win
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return true; // Vertical win
    }

    // Check diagonals for a win
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true; // Top-left to bottom-right diagonal win
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true; // Top-right to bottom-left diagonal win

    return false; // No win
}

// Function to display the game board with row and column indicators
void displayBoard(char board[3][3]) {
    std::cout << "    0   1   2" << std::endl;
    std::cout << "  -------------" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            std::cout << "| " << board[i][j] << " ";
        }
        std::cout << "|" << std::endl;
        std::cout << "  -------------" << std::endl;
    }
}

int main() {
    char map[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    const char player1 = 'X';
    const char player2 = 'O';
    char currentPlayer = player1;
    int row, col;

    // Game loop
    for (int turn = 0; turn < 9; ++turn) {
        // Print the current board
        std::cout << "Board:" << std::endl;
        displayBoard(map);

        // user input
        std::cout << "Player " << currentPlayer << " enter desired row (0-2): ";
        std::cin >> row;
        std::cout << "Player " << currentPlayer << " enter desired column (0-2): ";
        std::cin >> col;
        
        // Validate the move
        if (row < 0 || row > 2 || col < 0 || col > 2 || map[row][col] != ' ') {
            std::cout << "Invalid move! Try again." << std::endl;
            --turn; // Repeat the same turn
            continue;
        }

        // Make the move
        playerMovement(map, row, col, currentPlayer);

        // Check if the current player has won
        if (checkWinner(map, currentPlayer)) {
            // Print the final board
            std::cout << "Final Board:" << std::endl;
            displayBoard(map);
            std::cout << "Player " << currentPlayer << " wins!" << std::endl;
            return 0; // End the game
        }

        // alternate players
        currentPlayer = (currentPlayer == player1) ? player2 : player1;
    }

    // stalemate
    std::cout << "Final Board:" << std::endl;
    displayBoard(map);
    std::cout << "It's a draw!" << std::endl;

    return 0;
}
