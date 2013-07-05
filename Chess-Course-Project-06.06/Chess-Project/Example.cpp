#include <iostream>
#include <string>
#include "GameBoard.h"
#include "Position.h"
using namespace std;

int main()
{
	try
	{
		GameBoard board;
		board.DrawBoard();

		string input;
		getline(cin, input);

		while (input != "end")
		{
			if (input.length() > 5 || input.length() < 2)
			{
				throw invalid_argument("Wrong input");
			}

			Position currPos(input.substr(0, 2));
			Position newPos(input.substr(3));

			ChessPiece* piece = &board.GetPiece(currPos.X, currPos.Y);
			board.SetPiece(piece, newPos.X, newPos.Y);
			board.SetPiece(0, currPos.X, currPos.Y);

			board.DrawBoard();

			getline(cin, input);
		}
	}
	catch(exception& ex)
	{
		cout << ex.what() << endl;
	}

	return 0;
}