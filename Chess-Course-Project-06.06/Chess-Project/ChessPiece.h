#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include "PieceColor.h"
#include "PieceType.h"

// TODO: moje da dobavq neshto za pazene na vuzmojnite hodove, koito moje da pravi edna figura

class ChessPiece
{
protected:
	PieceColor color;
	PieceType type;

public:
	ChessPiece() { }
	ChessPiece(PieceColor color, PieceType type);
	ChessPiece(const ChessPiece*);
	virtual ChessPiece& operator= (const ChessPiece&);
	virtual ~ChessPiece() { }

	virtual bool IsMoveLegal() const = 0;
	PieceColor GetColor() const;
	PieceType GetType() const;
	virtual char GetSymbol() const = 0;
};

#endif