#include <iostream>
#include <cstring>
#include <stdexcept>
#include "Ingredient.h"
using std::invalid_argument;

//Constructors
Ingredient::Ingredient(const char* name, double price)
{
	SetName(name);
	SetPrice(price);
}

Ingredient::~Ingredient()
{
	//delete[] name;
}

//Getters
const char* Ingredient::GetName() const
{
	return this->name;
}

double Ingredient::GetPrice() const
{
	return this->price;
}

//Setters
void Ingredient::SetName(const char* name)
{
	if (!name)
	{
		throw invalid_argument("The ingredient name cannot be null.");
	}

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void Ingredient::SetPrice(double price)
{
	this->price = price;
}

//Other methods
std::ostream& operator <<(std::ostream& output, const Ingredient& ingred)
{
	output << ingred.GetName() << " - " << ingred.GetPrice() << std::endl;

	return output;
}