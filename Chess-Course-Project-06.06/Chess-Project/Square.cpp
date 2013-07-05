#include <cstring>
#include "Square.h"

//CONSTRUCTORS
Square::Square()
{
	this->piece = NULL;
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
	char symbol;
	if (piece == NULL)
	{
		symbol = '-';
	}
	else
	{
		symbol = piece->GetSymbol();
	}

	return symbol;
}

//SETTERS
void Square::SetPiece(ChessPiece* piece) 
{
	if (piece == NULL)
	{
		delete piece;
		piece = NULL;
		this->isEmpty = true;
	}
	else
	{
		this->piece = piece;
		this->isEmpty = false;
	}
}