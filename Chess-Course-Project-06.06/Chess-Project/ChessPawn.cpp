#include "ChessPawn.h"

//CONSTRUCTOR
ChessPawn::ChessPawn(PieceColor color) : ChessPiece(color, type)
{
	this->type = Pawn;
}

//PUBLIC METHODS
bool ChessPawn::IsMoveLegal() const 
{
	// TODO: IMPLEMENT LOGIC
	return false;
}

//GET SYMBOL
char ChessPawn::GetSymbol() const
{
	return 'P';
}
