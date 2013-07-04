#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include "ChessPiece.h"
#include "Square.h"

class GameBoard
{
private:
	// TODO: za duskata dinamichen ili statichen masiv
	static const int fieldSize = 8;
	Square board[fieldSize][fieldSize]; 

public:
	GameBoard();
	~GameBoard() {};

	int GetBoardSize() const;
	void SetPiece(ChessPiece*, int posX, int posY);
	ChessPiece& GetPiece(int posX, int posY) const;
};

#endif
