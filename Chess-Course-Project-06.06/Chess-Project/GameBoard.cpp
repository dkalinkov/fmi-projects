#include "GameBoard.h"

//CONSTRUCTOR
GameBoard::GameBoard()
{
	for (int row = 0; row < fieldSize; row++)
	{
		for (int col = 0; col < fieldSize; col++)
		{
			Square square;
			this->board[row][col] = square;
		}
	}
}

//GETS THE FIELD SIZE (N x N) RETURNS N
int GameBoard::GetBoardSize() const
{
	return this->fieldSize;
}

//SETS THE NEW PEACE TO THE PASSED BOARD COORDINATES
void GameBoard::SetPiece(ChessPiece* piece, int posX, int posY)
{
	board[posX][posY].SetPiece(piece);
}

//GETS THE PEACE LOCATED ON THE PASSED BOARD COORDINATES
ChessPiece& GameBoard::GetPiece(int posX, int posY) const
{
	return board[posX][posY].GetPiece();
}

