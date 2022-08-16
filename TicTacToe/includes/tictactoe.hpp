#ifndef TIC_TAC_TOE_HPP
#define TIC_TAC_TOE_HPP
#include <iostream>
#include <vector>
bool ValidPos(int x);
std::vector<int>GetPos(int pos);
bool CheckPosTaken(int pos, std::vector<std::vector<char>> board);
void UpdateBoard(std::vector<std::vector<char>>& board, int pos, char player);
char CheckHoz(std::vector<std::vector<char>> board); //returns who wins in horizontal direction
char CheckVert(std::vector<std::vector<char>> board); //returns who wins in vertical direction
char CheckLeftDiag(std::vector<std::vector<char>> board); //returns who wins in left diag direction
char CheckRightDiag(std::vector<std::vector<char>> board); //returns who wins in right diag direction
#endif