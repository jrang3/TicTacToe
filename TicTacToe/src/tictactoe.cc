#include "tictactoe.hpp"
bool ValidPos(int x) {
    if ( x < 1 || x > 9) {
        return false;
    }
    return true;
}
std::vector<int>GetPos(int pos) { //Converts a given position on the board to the corresponding row and column on board
    std::vector<int>row_col_pos;
    int row = 0;
    int col = 0;
    if (pos >= 0 && pos <= 3) {
        col = pos - 1;
    }
    else if (pos >= 4 && pos <= 6) {
        row = 1;
        col = pos - 4;
    }
    else {
        row = 2;
        col = pos - 7;
    }
    row_col_pos.push_back(row);
    row_col_pos.push_back(col);
    return row_col_pos;
}
bool CheckPosTaken(int pos, std::vector<std::vector<char>> board) {
    if (!ValidPos(pos)) {
       std::cout<<"Invalid Pos! Choose a position from 1-9."<<std::endl;
        return false;
    }
    std::vector<int>row_col_pos = GetPos(pos);
    if (board.at(row_col_pos.at(0)).at(row_col_pos.at(1)) == '-') {
        return true;
    }
    return false;
     
}
void UpdateBoard(std::vector<std::vector<char>>& board, int pos, char player) {
    std::vector<int>row_col_pos = GetPos(pos);
    board.at(row_col_pos.at(0)).at(row_col_pos.at(1)) = player;
}
char CheckHoz(std::vector<std::vector<char>> board) {
    int xcount = 0;
    int ocount = 0;
    for (std::vector<char> row : board) {
        for (int c : row) {
            if (c == 'X') {
                xcount++;
            }
            else if (c == 'O') {
                ocount++;
            }
        }
        if (xcount == 3) {
            return 'X';

        } 
        if (ocount == 3) {
            return 'O';
        }
        xcount = 0;
        ocount = 0;
    }
    return ' '; //Nobody wins
}
char CheckVert(std::vector<std::vector<char>> board) {
    int xcount = 0;
    int ocount = 0;
    for (size_t c = 0 ; c < 3; c++) {
        for (size_t r = 0; r < 3; r++) {
            if (board.at(r).at(c) == 'X') {
                xcount++;
            }
            else if (board.at(r).at(c) == 'O') {
                ocount++;
            }
        }
        if (xcount == 3) {
            return 'X';

        } 
        if (ocount == 3) {
            return 'O';
        }
        xcount = 0;
        ocount = 0;
    }
    return ' '; //Nobody wins
}
char CheckLeftDiag(std::vector<std::vector<char>> board) {
    int rpos = 0;
    int cpos = 0;
    int xcount = 0;
    int ocount = 0;
    while (rpos < 3) {
        if (board.at(rpos).at(cpos) == 'X') {
            xcount++;
        } 
        else if (board.at(rpos).at(cpos) == 'O') {
            ocount++;
        }
        rpos++;
        cpos++;
    }
    if (xcount == 3) {
        return 'X';
    }
    if (ocount == 3) {
        return 'O';
    }
    return ' ';
}
char CheckRightDiag(std::vector<std::vector<char>> board) {
    int rpos = 0;
    int cpos = 2;
    int xcount = 0;
    int ocount = 0;
    while (rpos < 3) {
        if (board.at(rpos).at(cpos) == 'X') {
            xcount++;
        } 
        else if (board.at(rpos).at(cpos) == 'O') {
            ocount++;
        }
        rpos++;
        cpos--;
    }
    if (xcount == 3) {
        return 'X';
    }
    if (ocount == 3) {
        return 'O';
    }
    return ' ';
}

