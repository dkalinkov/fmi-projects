#ifndef INGREDIENT_H
#define INGREDIENT_H

#include<ostream>

class Ingredient
{
private:
	char* name;
	double price;

public:
	Ingredient(const char* name, double price);
	~Ingredient();

	const char* GetName() const;
	double GetPrice() const;

	void SetName(const char*);
	void SetPrice(double);
};

std::ostream& operator <<(std::ostream& output, const Ingredient& ingred);

#endif
