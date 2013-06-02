#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <stdexcept>
#include "Person.h"
#include "string.h"
using std::invalid_argument;

//TODO: DECONSTRUCTOR FIX

//CONSTRUCTORS
Person::Person()
{
}

Person::Person(const char* name, const char* egn, const char* address, ProfessionEnum job, double income)
{
	SetName(name);
	SetEGN(egn);
	SetAddress(address);
	this->age = CalculateAge();
	this->sex = GetSexFromEGN();
	SetJob(job);
	SetIncome(income);
}

Person::Person(const Person& otherPerson)
{
	this->name = new char[strlen(otherPerson.name)];
	strcpy(this->name, otherPerson.name);

	this->EGN = new char[strlen(otherPerson.EGN)];
	strcpy(this->EGN, otherPerson.EGN);

	this->address = new char[strlen(otherPerson.address)];
	strcpy(this->address, otherPerson.address);

	this->age = otherPerson.age;
	this->sex = otherPerson.sex;
	this->job = otherPerson.job;
	this->income = otherPerson.income;
}

Person& Person::operator = (const Person& otherPerson)
{
	this->name = new char[strlen(otherPerson.name)];
	strcpy(this->name, otherPerson.name);

	this->EGN = new char[strlen(otherPerson.EGN)];
	strcpy(this->EGN, otherPerson.EGN);

	this->address = new char[strlen(otherPerson.address)];
	strcpy(this->address, otherPerson.address);

	this->age = otherPerson.age;
	this->sex = otherPerson.sex;
	this->job = otherPerson.job;
	this->income = otherPerson.income;

	return *this;
}

Person::~Person()
{
	delete[] name;
	delete[] EGN;
	delete[] address;
}

//Private Methods
unsigned short Person::CalculateAge() const
{
	unsigned short currentYear = 113;
	unsigned short yearBorn = (short)(EGN[0] - '0') * 10 + (short)(EGN[1] - '0');

	return currentYear - yearBorn;
}

SexEnum Person::GetSexFromEGN() const
{
	int digitPosShowingSex = 8;
	int sexDigit = (int)(EGN[digitPosShowingSex] - '0');
	SexEnum sex = Female;

	if (sexDigit % 2 == 0)
	{
		sex = Male;
	}

	return sex;
}

void Person::ValidateEGN(const char* egn) const
{
	if (!egn)
	{
		throw std::invalid_argument("EGN must not be null!");
	}

	unsigned short egnLenght = strlen(egn);
	if (egnLenght != 10)
	{
		throw std::length_error("ENG must be 10 digits long!!!");
	}

	for (int index = 0; index < egnLenght; index++)
	{
		if (egn[index] - '0' < 0 || egn[index] - '0' > 9)
		{
			throw invalid_argument("EGN must be consisted entirely by numbers!!!");
		}
	}
}

//Public Methods
char* Person::JobAsString() const
{
	switch (job)
	{
	case Baker:
		return "Baker";
	case Teacher:
		return "Teacher";
	case Janitor:
		return "Janitor";
	case Gamer:
		return "Gamer";
	case Journalist:
		return "Journalist";
	case SoftwareDev:
		return "SoftwareDev";
	case Unemployed:
		return "Unemployed";
	default:
		return "Unemployed";
	}
}

//Getter and setter for name
char* Person::GetName() const
{
	return this->name;
}

void Person::SetName(const char* name)
{
	if (!name)
	{
		throw invalid_argument("Name can't be null!");
	}

	this->name = new char[strlen(name)];
	strcpy(this->name, name);
}

//Getter and setter for EGN
char* Person::GetEGN() const
{
	return this->EGN;
}

void Person::SetEGN(const char* egn)
{
	ValidateEGN(egn);
	this->EGN = new char[strlen(egn)];
	strcpy(this->EGN, egn);
}

//Getter and setter for address
char* Person::GetAddress() const
{
	return this->address;
}

void Person::SetAddress(const char* address)
{
	if (!address)
	{
		throw invalid_argument("Address can't be null!");
	}

	this->address = new char[strlen(address)];
	strcpy(this->address, address);
}

//Getter for age
unsigned short Person::GetAge() const
{
	return this->age;
}

//Getter for sex
SexEnum Person::GetSexType() const
{
	return this->sex;
}

//Getter and setter for job
ProfessionEnum Person::GetJob() const
{
	return this->job;
}

void Person::SetJob(ProfessionEnum job)
{
	this->job = job;
}

//Getter and setter for income
double Person::GetIncome() const
{
	return this->income;
}

void Person::SetIncome(double income)
{
	if (income < 0)
	{
		throw std::range_error("Income must not be negative!");
	}
	else
	{
		this->income = income;
	}
}

std::ostream& operator <<(std::ostream& output, const Person& person)
{
	output << "Name: "<< person.GetName() 
		<<"\nEGN: "<< person.GetEGN() 
		<<"\nAddress: "<< person.GetAddress() 
		<<"\nAge: "<< person.GetAge() 
		<<"\nSex: "<< (person.GetSexType() == 0 ? "Male" : "Female")
		<<"\nJob: "<< person.JobAsString()
		<<"\nIncome: "<< person.GetIncome() 
		<< std::endl;

	return output;
}
