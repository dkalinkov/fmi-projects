#include <iostream>
#include "GameBoard.h"
#include "ChessPawn.h"
#include "ChessKnight.h"
using std::cout;
using std::endl;

//CONSTRUCTOR
GameBoard::GameBoard()
{
	for (int row = 0; row < fieldSize; row++)
	{
		for (int col = 0; col < fieldSize; col++)
		{
			//Square square;
			this->board[row][col] = new Square();
		}
	}
}

GameBoard::~GameBoard()
{
	for (int row = 0; row < fieldSize; row++)
	{
		for (int col = 0; col < fieldSize; col++)
		{
			delete board[row][col];
		}
	}
}

//INIT THE BOARD WHEN GAME STARTS
void GameBoard::InitBoard()
{
	for (int col = 0; col < fieldSize; col++)
	{		
		board[1][col]->SetPiece(new ChessPawn(White));
		board[6][col]->SetPiece(new ChessPawn(Black));
	}

	board[0][1]->SetPiece(new ChessKnight(White));
	board[0][6]->SetPiece(new ChessKnight(White));
	board[7][1]->SetPiece(new ChessKnight(Black));
	board[7][6]->SetPiece(new ChessKnight(Black));
}

//DRAWS THE GAME BOARD TO THE CONSOLE
void GameBoard::DrawBoard() const
{
	char cols[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
	cout << "    ";
	for (int index = 0; index < fieldSize; index++)
	{
		cout << " " << cols[index] << "  ";
	}

	cout << endl;
	for (int row = 0; row < fieldSize; row++)
	{
		cout << row + 1 << ". | ";
		for (int col = 0; col < fieldSize; col++)
		{
			cout << board[row][col]->GetPieceSymbol() << " | ";
		}

		cout << endl << "   -";
		for (int col = 0; col < fieldSize; col++)
		{
			cout << "----";
		}

		cout << endl;
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
	board[posX][posY]->SetPiece(piece);
}

//GETS THE PEACE LOCATED ON THE PASSED BOARD COORDINATES
ChessPiece& GameBoard::GetPiece(int posX, int posY) const
{
	return board[posX][posY]->GetPiece();
}

