#include <iostream>
#include "CoffeeShop.h"
using namespace std;

void main()
{
	try
	{
		CoffeeShop fmiCafe("FMI Coffee Shop");

		Ingredient ing1("kanela", 5);
		Ingredient ing2("voda", 1);
		Ingredient ing3("cafe", 2);

		AlienTechnic alienTech("Izvunzemno", "Klqkash 3 puti, dokato se vurtish v krug", 50);

		Drink coffee("Cafe", Hot);
		coffee.AddIngredient(ing1, 1);
		coffee.AddIngredient(ing2, 1);
		coffee.AddIngredient(ing3, 2);

		Drink alienCoffee("Cafe", Hot, alienTech);
		alienCoffee.AddIngredient(ing1, 1);
		alienCoffee.AddIngredient(ing2, 1);
		alienCoffee.AddIngredient(ing3, 2);

		cout << coffee.GetPrice() << endl << alienCoffee.GetPrice();

		//fmiCafe.AddDrink(coffee);
	}
	catch(exception& ex)
	{
		cout << ex.what();
	}
}