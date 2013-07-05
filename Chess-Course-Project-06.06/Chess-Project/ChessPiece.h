#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include "PieceColor.h"
#include "PieceType.h"
#include "Position.h"

class GameBoard;

class ChessPiece
{
protected:
	PieceColor color;
	PieceType type;

public:
	ChessPiece() {}
	ChessPiece(PieceColor color, PieceType type);
	ChessPiece(const ChessPiece*);
	virtual ChessPiece& operator= (const ChessPiece&);
	virtual ~ChessPiece() {}

	virtual bool IsMoveLegal(Position currPos, Position newPos, GameBoard*) const = 0;
	PieceColor GetColor() const;
	PieceType GetType() const;
	virtual char GetSymbol() const = 0;
};

#endif