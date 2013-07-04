#include "ChessPiece.h"

//CONSTRUCTORS
ChessPiece::ChessPiece(PieceColor color, PieceType type = None)
{
	this->color = color;
	this->type = type;
}

//PUBLIC METHODS

//GETTERS
PieceColor ChessPiece::GetColor() const
{
	return this->color;
}

PieceType ChessPiece::GetType() const
{
	return this->type;
}

const char* ChessPiece::GetTypeString() const
{
	switch (type)
	{
	case Pawn:
		return "Pawn";
	case Knight:
		return "Knight";
	case Bishop:
		return "Bishop";
	case Rook:
		return "Rook";
	case Queen:
		return "Queen";
	case King:
		return "King";
	default:
		return "None";
	}
}
