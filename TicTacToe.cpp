#include <iostream>

//this func is used to track user input
void playerMovement(char board[3][3], int row, int col, char currentPlayer){
    board[row][col]= currentPlayer;
}

bool checkWinner(char board [3][3], char currentPlayer){
    for( int i =0; i< 3; i++){ //iterator

    if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] ==currentPlayer)
    return true;
    //this is to check for a horizontal win 
    if (board[0][i] == currentPlayer && board [1][i] == currentPlayer && board[2][i] == currentPlayer)
    return true;
    //this is to check a vertical win

    }

    //now to check for diagonals
    if(board[0][0] == currentPlayer && board[1][1] ==currentPlayer && board[2][2]==currentPlayer)
    return true;
    //this checks a win from top left to bottom right

    if(board[0][2] == currentPlayer&& board[1][1] ==currentPlayer && board[2][0] ==currentPlayer)
    return true;
    //this is for bottom left to top right 

    return false;
    //this is for no wins
}





    


int main() {
    char map[3][3] = {
        {'  ', '  ', '  '},
        {'  ', '  ', '  '},
        {'  ', '  ', '  '},
    };

   const char player1 = 'X';
    const char player2 = 'O';
    char currentPlayer= player1 ;
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

    std::cout << "Player " << currentPlayer <<" enter desired row (0-2)";
    std::cin>>row;

    std::cout << "player " << currentPlayer << " enter desired column (0-2)";
    std::cin>>col;
    
    if (row > 2 || row < 0 || col > 2 || col < 0){
        std::cout<<"Invalid move, try again" << std::endl;
        --turn; //this lets user try again in the same turn

    }


}
}
