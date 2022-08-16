
#include "tictactoe.hpp"

int main() {
    std::string input;
    std::cout<<"Do you want to play tic tac toe? (y/n) ";
    std::cin>>input;
    while(input != "y" && input != "n") {
        std::cout<<"Invalid Answer! Enter y for yes or n for no ";
        std::cin>>input;
    }
    while (input == "y") {
        std::vector<std::vector<char>>board = {{'-','-','-'},
                                                {'-','-','-'},
                                                {'-','-','-'}};
        std::vector<std::vector<int>>board_pos= {{1,2,3},
                                                {4,5,6},
                                                {7,8,9}};
        std::cout<<"Here is the board and the coresponding positions"<<std::endl;
        int row_pos = 0;
        for (std::vector<char> row : board) { //prints the empty board
            for (char x : row) {
                std::cout<<x<<" ";
            }
            std::cout<<" ";
            std::vector<int> individual_row = board_pos.at(row_pos);
            for (int p : individual_row) { //prints the board positions
                std::cout<<p<<" ";
            }
            row_pos++;
            std::cout<<"\n";
        }
        int count = 0;
        char player = 'X';
        bool game = false;
        while(count < 9) { //Main Game Loop
            int pos;
            std::cout<<"It's currently "<< player <<"'s  turn. Choose a position from 1-9  ";
            std::cin>> pos;
            while((!ValidPos(pos) || !CheckPosTaken(pos,board))) { //Makes sure that user enters a valid input 
            if (!ValidPos(pos)) {
                std::cout<<"Invalid Position! Choose a position from 1-9  ";
                std::cin>> pos;
                }
            else if (!CheckPosTaken(pos,board)) {
                std::cout<<"Position has already been taken! Choose a different position from 1-9 ";
                std::cin>> pos;
                }
            }
            UpdateBoard(board, pos, player);
            row_pos = 0;
            for (std::vector<char> row : board) { //prints the board after player makes mpve
                for (char x : row) {
                    std::cout<<x<<" ";
                }
                std::cout<<" ";
                std::vector<int> individual_row = board_pos.at(row_pos);
                for (int p : individual_row) { //prints the board positions
                    std::cout<<p<<" ";
                }
                row_pos++;
                std::cout<<"\n";
            }
            if (CheckHoz(board) == 'X' || CheckVert(board) == 'X' || CheckLeftDiag(board) == 'X' || CheckRightDiag(board) == 'X') {
                std::cout<<"X Won!"<<std::endl;
                count = 8;
                game = true;
            }
            else if (CheckHoz(board) == 'O' || CheckVert(board) == 'O' || CheckLeftDiag(board) == 'O' || CheckRightDiag(board) == 'O') {
                std::cout<<"O Won!"<<std::endl;
                count = 8;
                game = true;
            }
            if (player == 'X') {
                player = 'O';
            }
            else if (player == 'O') {
                player = 'X';
            }
            count++;
        }
        if (!game) {
            std::cout<<"Nobody Won. There's a tie! ";
        }
        std::cout<<"Do you want to play again? (y/n) ";
        std::cin>>input;
    }
    std::cout<<"GoodBye! ";
}

