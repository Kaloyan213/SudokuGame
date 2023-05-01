#include <iostream>
#include "RemoveNumbers.h"



int main() {
	std::vector<std::vector<int>> board{ createBoard() };
	printBoard(board);
	removeNumbers(board, 15);
	printBoard(board);
	solveSudoku(board);
	printBoard(board);
}

