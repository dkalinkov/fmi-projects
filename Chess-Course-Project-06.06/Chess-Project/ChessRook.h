#ifndef ROOK_H
#define ROOK_H

#include "ChessPiece.h"

class ChessRook : public ChessPiece
{
public:
	ChessRook(PieceColor color);

	virtual bool IsMoveLegal() const;
	virtual char GetSymbol() const;
};

#endif