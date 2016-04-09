#include "ChessKing.h"
#include "GameBoard.h"

//CONSTRUCTOR
ChessKing::ChessKing(PieceColor color) : ChessPiece(color, type)
{
	this->type = Pawn;
}

//PUBLIC METHODS
bool ChessKing::IsMoveLegal(Position currPos, Position newPos, GameBoard* board) const 
{
	int deltaX = newPos.X - currPos.X;
	int deltaY = newPos.Y - currPos.Y;
	if (((deltaX >= -1) && (deltaX <= 1)) && ((deltaY >= -1) && (deltaY <= 1)))
	{
		return true;
	}

	return false;
}

//GET SYMBOL
char ChessKing::GetSymbol() const
{
	return 'K';
}
