#include "ChessBishop.h"
#include "GameBoard.h"

//CONSTRUCTOR
ChessBishop::ChessBishop(PieceColor color) : ChessPiece(color, type)
{
	this->type = Pawn;
}

//PUBLIC METHODS
bool ChessBishop::IsMoveLegal(Position currPos, Position newPos, GameBoard* board) const 
{
	if ((newPos.X - currPos.X == newPos.Y - currPos.X) || (newPos.X - currPos.X == currPos.Y - currPos.Y)) {
		int xOffset = (newPos.Y - currPos.Y) > 0 ? 1 : -1;
		int yOffset = (newPos.X - currPos.X) > 0 ? 1 : -1;
		int checkX, checkY;
		for (checkX = currPos.X + xOffset, checkY = currPos.Y + yOffset; 
			checkX != newPos.Y; 
			checkX += xOffset, checkY += yOffset)
		{
			ChessPiece* piece = &board->GetPiece(checkX, checkY);
			if (piece != 0)
			{
				return false;
			}
		}

		return true;
	}

	return false;
}

//GET SYMBOL
char ChessBishop::GetSymbol() const
{
	return 'B';
}
