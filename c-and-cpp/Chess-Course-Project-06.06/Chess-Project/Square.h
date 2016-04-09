#ifndef SQUARE_H
#define SQUARE_H

#include "ChessPiece.h"

class Square
{
private:
	ChessPiece* piece;
	bool isEmpty;

public:
	Square();
	~Square();

	bool IsSquareEmpty() const;

	ChessPiece& GetPiece() const;
	void SetPiece(ChessPiece*);
	const char GetPieceSymbol() const;
};

#endif
