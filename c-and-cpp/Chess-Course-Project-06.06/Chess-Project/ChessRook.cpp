#include "ChessRook.h"
#include "GameBoard.h"

//CONSTRUCTOR
ChessRook::ChessRook(PieceColor color) : ChessPiece(color, type)
{
	this->type = Pawn;
}

//PUBLIC METHODS
bool ChessRook::IsMoveLegal(Position currPos, Position newPos, GameBoard* board) const 
{
	if (currPos.X == newPos.X)
	{
		int yOffset = (newPos.Y - currPos.Y) > 0 ? 1 : -1;
		for (int checkY = currPos.Y + yOffset; checkY != newPos.Y; checkY += yOffset)
		{
			Position pos(currPos.X, checkY);
			if (!board->IsSquareFree(pos)) {
				return false;
			}
		}

		return true;
	}
	else if (currPos.Y == newPos.Y)
	{
		int xOffset = (newPos.X - currPos.X) > 0 ? 1 : -1;
		for (int xCheck = currPos.X + xOffset; xCheck != newPos.X; xCheck += xOffset)
		{
			Position pos(xCheck, currPos.Y);
			if (!board->IsSquareFree(pos)) {
				return false;
			}
		}

		return true;
	}

	return false;
}

//GET SYMBOL
char ChessRook::GetSymbol() const
{
	return 'R';
}
