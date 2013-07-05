#include <iostream>
#include "GameBoard.h"
#include "ChessPawn.h"
#include "ChessKnight.h"
#include "ChessBishop.h"
#include "ChessRook.h"
#include "ChessQueen.h"
#include "ChessKing.h"
using std::cout;
using std::endl;

// TODO: moje da polzvam SINGLETON za tozi klas

//CONSTRUCTOR
GameBoard::GameBoard()
{
	for (int row = 0; row < fieldSize; row++)
	{
		for (int col = 0; col < fieldSize; col++)
		{
			this->board[row][col] = new Square();
		}
	}

	InitBoard();
}

GameBoard::~GameBoard()
{
	//for (int row = 0; row < fieldSize; row++)
	//{
	//	for (int col = 0; col < fieldSize; col++)
	//	{
	//		delete board[row][col];
	//		board[row][col] = 0;
	//	}
	//}
}

//INIT THE BOARD WHEN GAME STARTS
void GameBoard::InitBoard()
{
	//Init rooks
	board[0][0]->SetPiece(new ChessRook(White));
	board[0][7]->SetPiece(new ChessRook(White));
	board[7][0]->SetPiece(new ChessRook(Black));
	board[7][7]->SetPiece(new ChessRook(Black));

	//Init knights(horse)
	board[0][1]->SetPiece(new ChessKnight(White));
	board[0][6]->SetPiece(new ChessKnight(White));
	board[7][1]->SetPiece(new ChessKnight(Black));
	board[7][6]->SetPiece(new ChessKnight(Black));

	//Init bishops(officer)
	board[0][2]->SetPiece(new ChessBishop(White));
	board[0][5]->SetPiece(new ChessBishop(White));
	board[7][2]->SetPiece(new ChessBishop(Black));
	board[7][5]->SetPiece(new ChessBishop(Black));

	//Init pawns
	for (int col = 0; col < fieldSize; col++)
	{		
		board[1][col]->SetPiece(new ChessPawn(White));
		board[6][col]->SetPiece(new ChessPawn(Black));
	}

	//Init queens
	board[0][3]->SetPiece(new ChessQueen(White));
	board[7][3]->SetPiece(new ChessQueen(Black));

	//Init kings
	board[0][4]->SetPiece(new ChessKing(White));
	board[7][4]->SetPiece(new ChessKing(Black));
}

//RETURNS THE GAME BOARD
Square* GameBoard::GetBoard() const
{
	return board[fieldSize][fieldSize];
}

//DRAWS THE GAME BOARD TO THE CONSOLE
void GameBoard::DrawBoard() const
{
	//DRAW TOP LETTER INDEXES
	char cols[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
	cout << "    ";
	for (int index = 0; index < fieldSize; index++)
	{
		cout << " " << cols[index] << "  ";
	}

	cout << endl << "   -";
	for (int col = 0; col < fieldSize; col++)
	{
		cout << "----";
	}

	//DRAW FIELD
	cout << endl;
	for (int row = 0; row < fieldSize; row++)
	{
		cout << row + 1 << ". | ";
		for (int col = 0; col < fieldSize; col++)
		{
			if (board[row][col]->IsSquareEmpty())
			{
				cout << "- | ";
			}
			else
			{
				cout << board[row][col]->GetPieceSymbol() << " | ";
			}
		}

		cout << endl << "   -";
		for (int col = 0; col < fieldSize; col++)
		{
			cout << "----";
		}

		cout << endl;
	}
}

//CHECKS IF SQUARE IS FREE
bool GameBoard::IsSquareFree(Position pos) const
{
	return board[pos.X][pos.Y]->IsSquareEmpty();
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
