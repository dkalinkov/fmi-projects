#include "ChessRook.h"

//CONSTRUCTOR
ChessRook::ChessRook(PieceColor color) : ChessPiece(color, type)
{
	this->type = Pawn;
}

//PUBLIC METHODS
bool ChessRook::IsMoveLegal() const 
{
	// TODO: IMPLEMENT LOGIC
	return false;
}

//GET SYMBOL
char ChessRook::GetSymbol() const
{
	return 'R';
}
