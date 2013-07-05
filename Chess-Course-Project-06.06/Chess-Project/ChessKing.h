#ifndef KING_H
#define KING_H

#include "ChessPiece.h"

class ChessKing : public ChessPiece
{
public:
	ChessKing(PieceColor color);

	virtual bool IsMoveLegal() const;
	virtual char GetSymbol() const;
};

#endif

