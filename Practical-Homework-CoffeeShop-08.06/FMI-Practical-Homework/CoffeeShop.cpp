#include <iostream>
#include "CoffeeShop.h"
using std::cout;

//Constructors
CoffeeShop::CoffeeShop(const char* name)
{
	SetName(name);
}

CoffeeShop::CoffeeShop(const CoffeeShop& otherCoffeeShop)
{
	this->name = new char[strlen(otherCoffeeShop.GetName()) + 1];
	strcpy(this->name, otherCoffeeShop.GetName());
}

CoffeeShop& CoffeeShop::operator= (const CoffeeShop& otherCoffeeShop)
{
	if (this != &otherCoffeeShop)
	{
		delete[] name;

		this->name = new char[strlen(otherCoffeeShop.GetName()) + 1];
		strcpy(this->name, otherCoffeeShop.GetName());
	}

	return *this;
}

CoffeeShop::~CoffeeShop()
{
	delete[] name;
}

//Checks if drinks is available
int CoffeeShop::IsDrinkAvailable(Drink& drink)
{
	int begin = 0,
		end = drinks.size();
	bool isFound = false;

	while (begin < end && !isFound)
	{
		if (drinks[begin] == drink)
		{
			isFound = true;
		}

		begin++;
	}

	if (isFound)
	{
		return begin;
	}

	return -1;
}

//Getter for Name
const char* CoffeeShop::GetName() const
{
	return this->name;
}

//Setter for Name
void CoffeeShop::SetName(const char* name)
{
	if (!name)
	{
		throw std::invalid_argument("CoffeShop name must not be null.");
	}

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

//AddDrink method
void CoffeeShop::AddDrink(Drink& drink)
{
	if (IsDrinkAvailable(drink) == -1)
	{
		this->drinks.push_back(drink);
	}
	else
	{
		cout << "Drink already added.";
	}
}

//Finds drink and prints it if it is availavle
void CoffeeShop::PrintDrinkIfFound(Drink& drink)
{
	int isAvailable = IsDrinkAvailable(drink);

	if (isAvailable != -1)
	{
		drinks[isAvailable].Print();
	}
	else
	{
		cout << "Drink not available.\n";
	}
}

//Prints all the menu items
void CoffeeShop::PrintMenu() const
{
	cout << this->GetName() << "\n";

	unsigned menuItemsCount = this->drinks.size();
	if (menuItemsCount == 0)
	{
		cout << "No items in the menu.";
	}
	else
	{
		for (unsigned index = 0; index < menuItemsCount; index++)
		{
			cout << this->drinks[index].GetName() << " -> $" << this->drinks[index].GetPrice() << "\n";
		}
	}

	cout << std::endl;
}
