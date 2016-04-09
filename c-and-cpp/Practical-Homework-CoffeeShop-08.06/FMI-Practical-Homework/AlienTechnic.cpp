#include <iostream>
#include <stdexcept>
#include <cstring>
#include "AlienTechnic.h"
using std::invalid_argument;

//Constructors
AlienTechnic::AlienTechnic(const char* name, const char* technic, unsigned priceToAdd)
{
	SetName(name);
	SetTechnic(technic);
	SetPriceToAdd(priceToAdd);
}

AlienTechnic& AlienTechnic::operator= (const AlienTechnic& alienTechnic)
{
	if (this != &alienTechnic)
	{
		//delete[] name;
		//delete[] technic;

		this->name = new char[strlen(alienTechnic.GetName()) + 1];
		strcpy(this->name, alienTechnic.GetName());

		this->technic = new char[strlen(alienTechnic.GetTechnic()) + 1];
		strcpy(this->technic, alienTechnic.GetTechnic());

		this->priceToAdd = alienTechnic.GetPriceToAdd();
	}

	return *this;
}

AlienTechnic::~AlienTechnic()
{
	//delete[] name;
	//delete[] technic;
}

//Getters
const char* AlienTechnic::GetName() const
{
	return this->name;
}

const char* AlienTechnic::GetTechnic() const
{
	return this->technic;
}

unsigned AlienTechnic::GetPriceToAdd() const
{
	return this->priceToAdd;
}

//Setters
void AlienTechnic::SetName(const char* name)
{
	if (!name)
	{
		throw invalid_argument("Must not be null.");
	}

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void AlienTechnic::SetTechnic(const char* technic)
{
	if (!technic)
	{
		throw invalid_argument("Must not be null.");
	}

	this->technic = new char[strlen(technic) + 1];
	strcpy(this->technic, technic);
}

void AlienTechnic::SetPriceToAdd(unsigned price)
{
	this->priceToAdd = price;
}

//Printing method
void AlienTechnic::Print() const
{
	std::cout << "Name: " << this->name
		<< "\nTechnic: " << this->technic
		<< "\nPriceToAdd" << this->priceToAdd
		<< std::endl;
}