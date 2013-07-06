#ifndef POSITION_H
#define POSITION_H

#include <cstring>
#include <stdexcept>
using std::invalid_argument;

class Position
{
public:
	int X; //row
	int Y; //col

	Position(std::string coords)
	{
		if (coords.length() >= 3)
		{
			throw invalid_argument("Wrong coordinates.");
		}

		this->X = coords.at(1) - '1';
		this->Y = coords.at(0) - 'a';

		if (X < 0 || X > 7 || Y < 0 || Y > 7)
		{
			throw invalid_argument("Position is out of board.");
		}
	}

	Position(int x, int y)
	{
		this->X = x;
		this->Y = y;

		if (X < 0 || X > 7 || Y < 0 || Y > 7)
		{
			throw invalid_argument("Position is out of board.");
		}
	}
};

#endif
