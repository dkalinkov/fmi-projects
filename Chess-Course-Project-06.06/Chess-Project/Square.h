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

	bool IsSquareFree() const;

	ChessPiece& GetPiece() const;
	void SetPiece(ChessPiece*);
};

#endif
