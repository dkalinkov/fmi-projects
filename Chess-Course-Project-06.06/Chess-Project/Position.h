#ifndef POSITION_H
#define POSITION_H

#include <cstring>
#include <stdexcept>
using std::invalid_argument;

class Position
{
public:
	int X;
	int Y;

	Position(std::string coords)
	{
		if (coords.length() >= 3)
		{
			throw invalid_argument("Wrong coordinates.");
		}

		this->Y = coords.at(0) - 'a';
		this->X = coords.at(1) - '1';

		if (X < 0 || X > 7 || Y < 0 || Y > 7)
		{
			throw invalid_argument("Position is out of board.");
		}
	}
};

#endif
