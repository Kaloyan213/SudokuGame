#pragma once
#include <vector>
#include <iostream>
bool findEmptyCell(std::vector <std::vector<int>>& board, int& row, int& col);
bool isValidMove(std::vector <std::vector<int>>& board, int row, int col, int num);
bool solveSudoku(std::vector <std::vector<int>>& board);
bool isSolvable(std::vector <std::vector<int>>& board);


