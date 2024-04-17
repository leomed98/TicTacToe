#include <iostream>

void playerMovement(char board[3][3], int row, int col, char currentPlayer){
    board[row][col]= currentPlayer;
}

bool checkWinner(char board [3][3], char currentPlayer){
    
}

int main() {
    char map[3][3] = {
        {'  ', '  ', '  '},
        {'  ', '  ', '  '},
        {'  ', '  ', '  '},
    };

   const char Player1 = 'X';
    const char player2 = 'O';
    char currentPlayer= Player1;
    int row, col;


for (int i = 0; i<9; i++){
    //this prints the real time board 
std::cout << "Board:" << std::endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout <<  "| " <<map[i][j] << " ";
        }
        std::cout << "|" << std::endl;
    }

    std::cout << "Player 1" << currentPlayer <<" enter desired row/column (0-2)";
    


}
}
