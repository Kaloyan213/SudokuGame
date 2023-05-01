#include "SolveBoard.h"

const size_t N{ 9 };

bool findEmptyCell(std::vector <std::vector<int>>& board, int& row, int& col) {
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (board.at(row).at(col) == 0) {
                return true;
            }
        }
    }
    return false;
}

bool isValidMove(std::vector <std::vector<int>>& board, int row, int col, int num) {
    for (int i = 0; i < N; i++) {
        if (board.at(row).at(i) == num || board.at(i).at(col) == num) {
            return false;
        }
    }
}

bool solveSudoku(std::vector <std::vector<int>>& board) {
    int row, col;
    if (!findEmptyCell(board, row, col)) {
        return true;
    }
    for (int num = 1; num <= 9; num++) {
        if (isValidMove(board, row, col, num)) {
            board.at(row).at(col) = num;
            if (solveSudoku(board)) {
                return true;
            }
            board.at(row).at(col) = 0;
        }
    }
    return false;
}

bool isSolvable(std::vector <std::vector<int>>& board) {
    int row, col;
    if (!findEmptyCell(board, row, col)) {
        return true;
    }
    for (int num = 1; num <= 9; num++) {
        if (isValidMove(board, row, col, num)) {
            board.at(row).at(col) = num;
            if (solveSudoku(board)) {
                return true;
            }
            board.at(row).at(col) = 0;
        }
    }
    return false;
};
