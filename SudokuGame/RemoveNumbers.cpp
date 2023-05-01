#include "RemoveNumbers.h"

std::vector <std::vector<int>> removeNumbers(std::vector <std::vector<int>>& board, int amount) {

	for (size_t i = 0; i < amount; i++)
	{
		std::random_device rd; // create a random device to generate a seed
		std::mt19937 gen(rd());
		size_t a = gen() % 8;
		size_t b = (gen() + 2) % 8;


		size_t  temp = board.at(a).at(b);
		board.at(a).at(b) = 0;

		if (!isSolvable) {
			board.at(a).at(b) = 0;
			i--;
		}
	}


	return board;
}

