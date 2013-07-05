#ifndef QUEEN_H
#define QUEEN_H

#include "ChessPiece.h"

class ChessQueen : public ChessPiece
{
public:
	ChessQueen(PieceColor color);

	virtual bool IsMoveLegal(Position currPos, Position newPos, GameBoard*) const;
	virtual char GetSymbol() const;
};

#endif