#include <cstring>
#include "Square.h"

//CONSTRUCTORS
Square::Square()
{
	this->piece = 0;
	this->isEmpty = true;
}

Square::~Square()
{
	delete piece;
}

//PUBLIC METHODS
bool Square::IsSquareEmpty() const
{
	return this->isEmpty;
}

//GETTERS
ChessPiece& Square::GetPiece() const
{
	return *this->piece;
}

const char Square::GetPieceSymbol() const
{
	return piece->GetSymbol();
}

//SETTERS
void Square::SetPiece(ChessPiece* piece) 
{
	if (piece == 0)
	{
		delete piece;
		piece = 0;
		this->isEmpty = true;
	}
	else
	{
		this->piece = piece;
		this->isEmpty = false;
	}
}