#ifndef KNIGHT_H
#define KNIGHT_H

#include "ChessPiece.h"

class ChessKnight : public ChessPiece
{
public:
	ChessKnight(PieceColor color);

	virtual bool IsMoveLegal(Position currPos, Position newPos) const;
	virtual char GetSymbol() const;
};

#endif
