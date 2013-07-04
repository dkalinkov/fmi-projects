#ifndef PAWN_H
#define PAWN_H

#include "ChessPiece.h"

class ChessPawn : public ChessPiece
{
public:
	ChessPawn(PieceColor color);
	~ChessPawn() {}

	//virtual ChessPawn* clone() const;
	virtual bool IsMoveLegal() const;
};

#endif
