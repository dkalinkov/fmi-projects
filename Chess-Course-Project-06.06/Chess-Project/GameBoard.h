#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include "ChessPiece.h"
#include "Square.h"

class GameBoard
{
private:
	static const int fieldSize = 8;
	Square* board[fieldSize][fieldSize]; 

	void InitBoard();

public:
	GameBoard();
	~GameBoard();

	void DrawBoard() const;
	//bool IsSquareFree(Position) const;
	int GetBoardSize() const;
	ChessPiece& GetPiece(int posX, int posY) const;
	void SetPiece(ChessPiece* piece, int posX, int posY);
};

#endif
