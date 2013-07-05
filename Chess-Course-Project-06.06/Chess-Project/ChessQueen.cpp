#include "ChessQueen.h"

//CONSTRUCTOR
ChessQueen::ChessQueen(PieceColor color) : ChessPiece(color, type)
{
	this->type = Pawn;
}

//PUBLIC METHODS
bool ChessQueen::IsMoveLegal() const 
{
	// TODO: IMPLEMENT LOGIC
	return false;
}

//GET SYMBOL
char ChessQueen::GetSymbol() const
{
	return 'Q';
}