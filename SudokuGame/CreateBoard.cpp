#include "CreateBoard.h"

const int N = 9;


// check if a number is safe to place in a cell
bool isSafe(std::vector<std::vector<int>>& board, int row, int col, int num) {
    // check row
    for (int j = 0; j < N; j++) {
        if (board[row][j] == num) {
            return false;
        }
    }
    // check column
    for (int i = 0; i < N; i++) {
        if (board[i][col] == num) {
            return false;
        }
    }
    // check 3x3 box
    int boxRow = (row / 3) * 3;
    int boxCol = (col / 3) * 3;
    for (int i = boxRow; i < boxRow + 3; i++) {
        for (int j = boxCol; j < boxCol + 3; j++) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

std::vector<std::vector<int>> createBoard() {
    std::vector<std::vector<int>> board(N, std::vector<int>(N, 0));

    // Create a vector with numbers 1-9 in random order
    std::vector<int> nums{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(nums.begin(), nums.end(), g);

    // Fill the first row of the board with the randomized numbers
    for (int i = 0; i < N; i++) {
        board.at(0).at(i) = nums.at(i);
    }

    //Fill the other part of the board

    for (size_t i = 1; i < N; i++)
    {
        for (size_t k = 0; k < N; ++k)
        {
            while (!isSafe(board, i, k, nums.at(k))) {
                int temp = nums.at(k);
                nums.erase(nums.begin() + k);
                nums.push_back(temp);
            }
            board.at(i).at(k) = nums.at(k);

        }
    }
    return board;
};







void printBoard(const std::vector<std::vector<int>>& board) {
    for (int row = 0; row < N; row++) {
        if (row % 3 == 0) {
            std::cout << "-------------------------\n";
        }
        for (int col = 0; col < N; col++) {

            if (col % 3 == 0) {
                std::cout << "| ";
            }
            std::cout << board.at(row).at(col) << " ";
        }
        std::cout << "|\n";
    }
    std::cout << "-------------------------\n";
}









