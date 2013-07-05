#ifndef BISHOP_H
#define BISHOP_H

#include "ChessPiece.h"

class ChessBishop : public ChessPiece
{
public:
	ChessBishop(PieceColor color);

	virtual bool IsMoveLegal() const;
	virtual char GetSymbol() const;
};

#endif