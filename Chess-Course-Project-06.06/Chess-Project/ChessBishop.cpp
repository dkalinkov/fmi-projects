#include "ChessBishop.h"

//CONSTRUCTOR
ChessBishop::ChessBishop(PieceColor color) : ChessPiece(color, type)
{
	this->type = Pawn;
}

//PUBLIC METHODS
bool ChessBishop::IsMoveLegal() const 
{
	// TODO: IMPLEMENT LOGIC
	return false;
}

//GET SYMBOL
char ChessBishop::GetSymbol() const
{
	return 'B';
}
