#ifndef SQUARE_H
#define SQUARE_H

class Square
{
private:
	int posX;
	int posY;

public:
	Square();
	~Square();

	int GetPosX() const;
	int GetPosY() const;

	void SetPosX(int);
	void SetPosY(int);
};

#endif
