#include <stdexcept>
#include <iostream>
#include <cstring>
#include "Drink.h"
using std::invalid_argument;
using std::cout;

//Constructors
Drink::Drink(const char* name, DrinkType type)
{
	SetName(name);
	SetType(type);
}

Drink::Drink(const char* name, DrinkType type, AlienTechnic& alienTechnic)
{
	SetName(name);
	SetType(type);
	SetAlienTechnic(alienTechnic);
}

Drink::~Drink()
{
	delete[] name;
	delete alienTechnic;
}

//Public Methods
void Drink::AddIngredient(Ingredient& ingred, unsigned amount)
{
	this->ingredients.push_back(ingred);
	this->ingredientAmount.push_back(amount);
}

double Drink::CalculatePrice() const
{
	unsigned length = this->ingredients.size();
	double price = 0;

	for (unsigned index = 0; index < length; index++)
	{
		price += this->ingredients[index].GetPrice() * this->ingredientAmount[index];
	}

	if (this->type == Hot)
	{
		price = price * 1.1;
	}

	if (this->alienTechnic != NULL)
	{
		AlienTechnic technic = *this->alienTechnic;

		price = price * ((technic.GetPriceToAdd() / 100) + 1);
	}

	return price;
}

void Drink::Print() const
{
	cout << "Drink name: " << this->name << "\nPrice: " << this->GetPrice();
	cout << "\nType: " << (this->type == Hot) ? "Hot" : "Cold";
	cout << "\nIngredients:\n";

	unsigned length = this->ingredients.size();
	for (unsigned index = 0; index < length; index++)
	{
		cout << "Ingredient -> " << this->ingredients[index].GetName();
		cout << " | Amount -> " << this->ingredientAmount[index] << "\n";
	}

	if (this->alienTechnic != NULL)
	{
		AlienTechnic technic = *this->alienTechnic;

		cout << "Alien Technic Name: " << technic.GetName() << cout << "\nTechnic: " << technic.GetTechnic()
			<< "Price to add: " << technic.GetPriceToAdd() <<"%";
	}

	cout << std::endl;
}

//Overriding the operators for eqial
bool Drink::operator== (const Drink& otherDrink)
{
	if (*this->name == *otherDrink.name)
	{
		return true;
	}

	return false;
}

bool Drink::operator!= (const Drink& otherDrink)
{
	return *this == otherDrink;
}

//Getters
const char* Drink::GetName() const
{
	return this->name;
}

DrinkType Drink::GetType() const
{
	return this->type;
}

double Drink::GetPrice() const
{
	double price = CalculatePrice();

	return price;
}

const AlienTechnic* Drink::GetAlienTechnic() const
{
	return this->alienTechnic;
}

//Setters
void Drink::SetName(const char* name)
{
	if (!name)
	{
		throw invalid_argument("Name must not be null.");
	}

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void Drink::SetType(DrinkType type)
{
	this->type = type;
}

void Drink::SetAlienTechnic(AlienTechnic& alienTechnic)
{
	this->alienTechnic = &alienTechnic;
}