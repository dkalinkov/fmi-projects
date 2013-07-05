#ifndef PAWN_H
#define PAWN_H

#include "ChessPiece.h"

class ChessPawn : public ChessPiece
{
public:
	ChessPawn(PieceColor color);

	virtual ChessPawn* clone() const;
	virtual bool IsMoveLegal() const;
	virtual char GetSymbol() const;
};

#endif
