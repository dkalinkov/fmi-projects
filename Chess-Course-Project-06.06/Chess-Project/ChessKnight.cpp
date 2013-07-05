#include "ChessKnight.h"
#include "GameBoard.h"

//CONSTRUCTOR
ChessKnight::ChessKnight(PieceColor color): ChessPiece(color, type)
{
	this->type = Pawn;
}

//PUBLIC METHODS
bool ChessKnight::IsMoveLegal(Position currPos, Position newPos, GameBoard* board) const 
{
	if (currPos.X == newPos.X + 1 || currPos.X == newPos.X - 1) {
		if (currPos.Y == newPos.Y + 2 || currPos.Y == newPos.Y - 2) {
			return true;
		}
	}

	if (currPos.X == newPos.X + 2 || currPos.X == newPos.X - 2) {
		if (currPos.Y == newPos.Y + 1 || currPos.Y == newPos.Y - 1) {
			return true;
		}
	}

	return false;
}

//GET SYMBOL
char ChessKnight::GetSymbol() const
{
	return 'H';
}
