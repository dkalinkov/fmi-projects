#ifndef COFFEE_SHOP_H
#define COFFEE_SHOP_H

#include <vector>
#include "Drink.h"
using std::vector;

class CoffeeShop
{
private:
	char* name;
	vector<Drink> drinks;

	int IsDrinkAvailable(Drink&);

public:
	CoffeeShop(const char*);
	CoffeeShop(const CoffeeShop&);
	CoffeeShop& operator= (const CoffeeShop&);
	~CoffeeShop();

	const char* GetName() const;
	void SetName(const char*);

	void AddDrink(Drink&);
	void PrintDrinkIfFound(Drink&);
	void PrintMenu() const;
};

#endif
