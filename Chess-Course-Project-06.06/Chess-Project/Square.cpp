#include <cstring>
#include "Square.h"


Square::Square()
{
}


Square::~Square()
{
}

//PUBLIC METHODS

//GETTERS
int Square::GetPosX() const
{
	return this->posX;
}

int Square::GetPosY() const
{
	return this->posY;
}

//SETTERS
void Square::SetPosX(int posX)
{
	this->posX = posX;
}

void Square::SetPosY(int posY)
{
	this->posY = posY;
}