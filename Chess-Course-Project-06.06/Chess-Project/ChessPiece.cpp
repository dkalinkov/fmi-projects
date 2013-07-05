#include "ChessPiece.h"

//CONSTRUCTORS
ChessPiece::ChessPiece(PieceColor color, PieceType type = None)
{
	this->color = color;
	this->type = type;
}

ChessPiece::ChessPiece(const ChessPiece* other)
{
	this->type = other->GetType();
	this->color = other->GetColor();
}

ChessPiece& ChessPiece::operator= (const ChessPiece& other)
{
	this->type = other.GetType();
	this->color = other.GetColor();

	return *this;
}

//GETTERS
PieceColor ChessPiece::GetColor() const
{
	return this->color;
}

PieceType ChessPiece::GetType() const
{
	return this->type;
}
