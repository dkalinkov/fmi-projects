#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include "PieceColor.h"
#include "PieceType.h"

// TODO: moje da dobavq neshto za pazene na vuzmojnite hodove, koito moje da pravi edna figura
// TODO: da zabranq kopirashtite

class ChessPiece
{
protected:
	PieceColor color;
	PieceType type;

public:
	ChessPiece() { }
	ChessPiece(PieceColor color, PieceType type);
	virtual ~ChessPiece() { }

	//virtual ChessPiece* clone() const = 0;
	virtual bool IsMoveLegal() const = 0;

	PieceColor GetColor() const;
	PieceType GetType() const;
	const char* GetTypeString() const;
};

#endif