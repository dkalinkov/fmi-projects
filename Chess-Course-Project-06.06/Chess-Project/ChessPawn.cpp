#include "ChessPawn.h"
#include "GameBoard.h"

//CONSTRUCTOR
ChessPawn::ChessPawn(PieceColor color) : ChessPiece(color, type)
{
	this->type = Pawn;
}

//PUBLIC METHODS
bool ChessPawn::IsMoveLegal(Position currPos, Position newPos, GameBoard* board) const 
{
	if (board->IsSquareFree(newPos)) {
		if (newPos.Y == currPos.Y) {
			if (this->color == White) {
				if (newPos.X == currPos.X + 1) {
					return true;
				}
			}
			else {
				if (newPos.X == currPos.X - 1) {
					return true;
				}
			}
		}
	}
	else {
		if (newPos.Y == currPos.Y + 1 || newPos.Y == currPos.Y - 1) {
			if (this->color == White) {
				if (newPos.X == currPos.X + 1) {
					return true;
				}
			}
			else {
				if (newPos.X == currPos.X - 1) {
					return true;
				}
			}
		}
	}

	return false;
}

//GET SYMBOL
char ChessPawn::GetSymbol() const
{
	return 'P';
}
