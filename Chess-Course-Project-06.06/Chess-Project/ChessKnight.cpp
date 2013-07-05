#include "ChessKnight.h"

//CONSTRUCTOR
ChessKnight::ChessKnight(PieceColor color): ChessPiece(color, type)
{
	this->type = Pawn;
}

//PUBLIC METHODS
bool ChessKnight::IsMoveLegal() const 
{
	// TODO: IMPLEMENT LOGIC
	return false;
}

//GET SYMBOL
char ChessKnight::GetSymbol() const
{
	return 'O';
}
