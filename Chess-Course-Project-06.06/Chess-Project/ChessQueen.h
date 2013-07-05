#ifndef QUEEN_H
#define QUEEN_H

#include "ChessPiece.h"

class ChessQueen : public ChessPiece
{
public:
	ChessQueen(PieceColor color);

	virtual bool IsMoveLegal() const;
	virtual char GetSymbol() const;
};

#endif