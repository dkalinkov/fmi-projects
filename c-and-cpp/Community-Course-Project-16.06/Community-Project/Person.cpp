#include <iostream>
#include <cstring>
#include <stdexcept>
#include "Person.h"
using std::invalid_argument;

//CONSTRUCTORS
Person::Person()
{
}

Person::Person(const char* name, const char* egn, const char* address = "", ProfessionEnum job = Unemployed, double income = 0)
{
	SetName(name);

	ValidateEGN(egn);
	this->EGN = new char[strlen(egn) + 1];
	strcpy(this->EGN, egn);

	SetAddress(address);
	this->age = CalculateAge();
	this->sex = GetSexFromEGN();
	SetJob(job);
	SetIncome(income);
}

Person::Person(const Person& otherPerson)
{
	this->name = new char[strlen(otherPerson.name) + 1];
	strcpy(this->name, otherPerson.name);

	this->EGN = new char[strlen(otherPerson.EGN) + 1];
	strcpy(this->EGN, otherPerson.EGN);

	this->address = new char[strlen(otherPerson.address) + 1];
	strcpy(this->address, otherPerson.address);

	this->age = otherPerson.age;
	this->sex = otherPerson.sex;
	this->job = otherPerson.job;
	this->income = otherPerson.income;
}

Person& Person::operator = (const Person& otherPerson)
{
	if (this != &otherPerson)
	{
		delete[] name;
		delete[] EGN;
		delete[] address;

		this->name = new char[strlen(otherPerson.name) + 1];
		strcpy(this->name, otherPerson.name);

		this->EGN = new char[strlen(otherPerson.EGN) + 1];
		strcpy(this->EGN, otherPerson.EGN);

		this->address = new char[strlen(otherPerson.address) + 1];
		strcpy(this->address, otherPerson.address);

		this->age = otherPerson.age;
		this->sex = otherPerson.sex;
		this->job = otherPerson.job;
		this->income = otherPerson.income;
	}

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

void Person::Initialise(const char* name, const char* egn, const char* address, ProfessionEnum job, double income)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

	this->EGN = new char[strlen(egn) + 1];
	strcpy(this->EGN, egn);

	this->address = new char[strlen(address) + 1];
	strcpy(this->address, address);

	this->age = CalculateAge();
	this->sex = GetSexFromEGN();
	this->job = job;
	this->income = income;
}

//Redefining operators
bool Person::operator== (const Person& otherPerson)
{
	if (*this->EGN == *otherPerson.EGN)
	{
		return true;
	}

	return false;
}

bool Person::operator!= (const Person& otherPerson)
{
	return *this == otherPerson;
}

//Public Methods
const char* Person::JobAsString() const
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

void Person::Information(std::ostream& output = std::cout) const
{
	output << "Name: "<< this->GetName()
		<<"\nEGN: "<< this->GetEGN()
		<<"\nAddress: "<< this->GetAddress()
		<<"\nAge: "<< this->GetAge()
		<<"\nSex: "<< (this->GetSexType() == 0 ? "Male" : "Female")
		<<"\nJob: "<< this->JobAsString()
		<<"\nIncome: "<< this->GetIncome()
		<< std::endl;
}

//Getter and setter for name
const char* Person::GetName() const
{
	return this->name;
}

void Person::SetName(const char* name)
{
	if (!name)
	{
		throw invalid_argument("Name can't be null!");
	}

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

//Getter for EGN
const char* Person::GetEGN() const
{
	return this->EGN;
}

//Getter and setter for address
const char* Person::GetAddress() const
{
	return this->address;
}

void Person::SetAddress(const char* address)
{
	if (!address)
	{
		throw invalid_argument("Address can't be null!");
	}

	this->address = new char[strlen(address) + 1];
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

//Other methods
std::ostream& operator <<(std::ostream& output, const Person& person)
{
	person.Information(output);

	return output;
}
