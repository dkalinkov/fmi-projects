#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include "ChessPiece.h"
#include "Square.h"

class GameBoard
{
private:
	static const int fieldSize = 8;
	Square* board[fieldSize][fieldSize]; 

public:
	GameBoard();
	~GameBoard();

	void InitBoard();
	void DrawBoard() const;
	int GetBoardSize() const;
	void SetPiece(ChessPiece*, int posX, int posY);
	ChessPiece& GetPiece(int posX, int posY) const;
};

#endif
