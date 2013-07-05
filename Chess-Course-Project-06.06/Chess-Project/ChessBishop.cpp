#include "ChessBishop.h"

//CONSTRUCTOR
ChessBishop::ChessBishop(PieceColor color) : ChessPiece(color, type)
{
	this->type = Pawn;
}

//PUBLIC METHODS
bool ChessBishop::IsMoveLegal(Position currPos, Position newPos) const 
{
	if ((newPos.X - currPos.X == newPos.Y - currPos.X) || (newPos.X - currPos.X == currPos.Y - currPos.X)) {

	}

	return false;
}

//GET SYMBOL
char ChessBishop::GetSymbol() const
{
	return 'B';
}
