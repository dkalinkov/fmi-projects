#include "stdafx.h"
#include "Person.h"
#include "string.h"
#include <iostream>

//TODO: EGN verification

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
	Person newPerson = Person();
	
	newPerson.name = new char[strlen(otherPerson.name)];
	strcpy(newPerson.name, otherPerson.name);

	newPerson.EGN = new char[strlen(otherPerson.EGN)];
	strcpy(newPerson.EGN, otherPerson.EGN);

	newPerson.address = new char[strlen(otherPerson.address)];
	strcpy(newPerson.address, otherPerson.address);

	newPerson.age = otherPerson.age;
	newPerson.sex = otherPerson.sex;
	newPerson.job = otherPerson.job;
	newPerson.income = otherPerson.income;

	return newPerson;
}

Person::~Person(void)
{
	delete[] name;
	delete[] EGN;
	delete[] address;
}

unsigned short Person::CalculateAge() const
{
	short currentYear = 113;
	short yearBorn = (short)(EGN[0] - '0') * 10 + (short)(EGN[1] - '0');

	return currentYear - yearBorn;
}

SexEnum Person::GetSexFromEGN() const
{
	int digitPosShowingSex = 8;
	int sexDigit = (int)(EGN[digitPosShowingSex] - '0');
	SexEnum sex = none;

	if (sexDigit % 2 == 0)
	{
		sex = Male;
	}
	else
	{
		sex = Female;
	}

	return sex;
}

//Getter and setter for name
char* Person::GetName()
{
	return this->name;
}

void Person::SetName(const char* name)
{
	this->name = new char[strlen(name)];
	strcpy(this->name, name);
}

//Getter and setter for EGN
char* Person::GetEGN()
{
	return this->EGN;
}

void Person::SetEGN(const char* egn)
{
	this->EGN = new char[strlen(egn)];
	strcpy(this->EGN, egn);
}

//Getter and setter for address
char* Person::GetAddress()
{
	return this->address;
}

void Person::SetAddress(const char* address)
{
	this->address = new char[strlen(address)];
	strcpy(this->address, address);
}

//Getter for age
unsigned short Person::GetAge()
{
	return 15;
}

//Getter for sex
SexEnum Person::GetSexType()
{
	return SexEnum::none;
}

//Getter and setter for job
ProfessionEnum Person::GetJob()
{
	return this->job;
}

void Person::SetJob(ProfessionEnum job)
{
	this->job = job;
}

//Getter and setter for income
double Person::GetIncome()
{
	return this->income;
}

void Person::SetIncome(double income)
{
	if (income < 0)
	{
		this->income = 0;
		//should throw an exception
	}
	else
	{
		this->income = income;
	}
}

std::ostream& operator <<(std::ostream& output, const Person& person)
{
	output << person.GetName <<" "<< person.GetEGN <<" "<< person.GetAddress <<" "<< person.GetAge<<" "
		<< person.GetSexType <<" "<< person.GetJob<<" "<< person.GetIncome << std::endl;

	return output;
}
