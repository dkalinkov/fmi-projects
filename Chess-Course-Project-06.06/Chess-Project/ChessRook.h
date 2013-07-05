#ifndef ROOK_H
#define ROOK_H

#include "ChessPiece.h"

class ChessRook : public ChessPiece
{
public:
	ChessRook(PieceColor color);

	virtual bool IsMoveLegal(Position currPos, Position newPos, GameBoard*) const;
	virtual char GetSymbol() const;
};

#endif