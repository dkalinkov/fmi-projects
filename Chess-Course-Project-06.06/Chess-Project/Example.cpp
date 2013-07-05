#include <iostream>
#include "GameBoard.h"
#include "ChessPiece.h"
#include "ChessPawn.h"
using namespace std;

int main()
{
	GameBoard board;
	board.InitBoard();
	board.DrawBoard();

	return 0;
}