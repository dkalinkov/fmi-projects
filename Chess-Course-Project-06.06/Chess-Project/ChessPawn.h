#ifndef PAWN_H
#define PAWN_H

#include "ChessPiece.h"

class ChessPawn : public ChessPiece
{
public:
	ChessPawn(PieceColor color);

	virtual bool IsMoveLegal(Position currPos, Position newPos) const;
	virtual char GetSymbol() const;
};

#endif
