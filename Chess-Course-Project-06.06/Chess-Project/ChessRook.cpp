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
	if (currPos.Y == newPos.Y)
	{
		int xOffset = (newPos.X - currPos.X) > 0 ? 1 : -1;
		for (int checkX = currPos.X + xOffset; checkX != newPos.X; checkX += xOffset)
		{
			ChessPiece* piece = &board->GetPiece(currPos.X, checkX);
			if (piece != 0) {
				return false;
			}
		}

		return true;
	}
	else if (currPos.X == newPos.X)
	{
		int yOffset = (newPos.Y - currPos.Y) > 0 ? 1 : -1;
		for (int yCheck = currPos.Y + yOffset; yCheck != newPos.Y; yCheck += yOffset)
		{
			ChessPiece* piece = &board->GetPiece(currPos.Y, yCheck);
			if (piece != 0) {
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
