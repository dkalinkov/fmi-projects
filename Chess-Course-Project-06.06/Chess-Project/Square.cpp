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
bool Square::IsSquareFree() const
{
	return this->isEmpty;
}

//GETTERS
ChessPiece& Square::GetPiece() const
{
	return *this->piece;
}

//SETTERS
void Square::SetPiece(ChessPiece* piece) 
{
	if (piece == NULL)
	{
		delete piece;
		this->isEmpty = true;
		piece = NULL;
	}
	else
	{
		delete piece;
		this->isEmpty = false;
		this->piece = piece;
	}
}