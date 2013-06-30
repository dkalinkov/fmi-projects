#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include "PieceColor.h"

class ChessPiece
{
private:
	PieceColor color;

	bool IsMoveLegal() const;

public:
	ChessPiece(PieceColor color);
	~ChessPiece();


};

#endif