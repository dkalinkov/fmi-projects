#ifndef DRINK_H
#define DRINK_H

#include <ostream>
#include <vector>
#include "Ingredient.h"
#include "DrinkType.h"
#include "AlienTechnic.h"
using std::vector;

class Drink
{
private:
	char* name;
	vector<Ingredient> ingredients;
	vector<unsigned> ingredientAmount;
	DrinkType type;
	AlienTechnic* alienTechnic;

public:
	Drink(const char* name, DrinkType);
	Drink(const char* name, DrinkType, AlienTechnic&);
	~Drink();

	bool operator== (const Drink&);
	bool operator!= (const Drink&);

	const char* GetName() const;
	DrinkType GetType() const;
	double GetPrice() const;
	const AlienTechnic* GetAlienTechnic() const;

	void SetName(const char*);
	void SetType(DrinkType);
	void SetAlienTechnic(AlienTechnic&);

	void AddIngredient(Ingredient&, unsigned);
	double CalculatePrice() const;
	void Print() const;
};

#endif
