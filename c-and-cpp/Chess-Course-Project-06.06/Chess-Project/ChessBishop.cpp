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
	if ((newPos.Y - currPos.Y == newPos.X - currPos.X) || (newPos.Y - currPos.Y == currPos.X - newPos.X)) {
		int xOffset = (newPos.X - currPos.X) > 0 ? 1 : -1;
		int yOffset = (newPos.Y - currPos.Y) > 0 ? 1 : -1;
		int checkX, checkY;
		for (checkX = currPos.X + xOffset, checkY = currPos.Y + yOffset; 
			checkX != newPos.X; 
			checkX += xOffset, checkY += yOffset)
		{
			Position pos(checkX, checkY);
			if (!board->IsSquareFree(pos))
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
