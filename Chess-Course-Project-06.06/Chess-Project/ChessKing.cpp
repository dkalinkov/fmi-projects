#include "ChessKing.h"

//CONSTRUCTOR
ChessKing::ChessKing(PieceColor color) : ChessPiece(color, type)
{
	this->type = Pawn;
}

//PUBLIC METHODS
bool ChessKing::IsMoveLegal() const 
{
	// TODO: IMPLEMENT LOGIC
	return false;
}

//GET SYMBOL
char ChessKing::GetSymbol() const
{
	return 'K';
}
