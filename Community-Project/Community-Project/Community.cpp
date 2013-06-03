#include <stdexcept>
#include <iostream>
#include <cstring>
#include "Community.h"
using std::invalid_argument;

//CONSTRUCTORS
Community::Community(const char* name, const char* foundationDate, Person& founder, int maxMembersCount)
{
	SetName(name);

	this->foundationDate = new char[strlen(foundationDate) + 1];
	strcpy(this->foundationDate, foundationDate);

	SetFounder(founder);
	SetMaxMembersCount(maxMembersCount);
	
	this->members = new Person[maxMembersCount];
}

Community::~Community()
{
	delete[] name;
	delete[] foundationDate;
	delete founder;
	delete[] members;
}

//PRIVATE METHODS

//PUBLIC METHODS
bool Community::IsFull() const
{
	if (this->membersCount == this->maxMembersCount)
	{
		return true;
	}

	return false;
}

//GETTERS
char* Community::GetName() const
{
	return this->name;
}

char* Community::GetFoundationDate() const
{
	return this->foundationDate;
}

Person Community::GetFounder() const
{
	return *this->founder;
}

int Community::GetMaxMembersCount() const
{
	return this->maxMembersCount;
}

int Community::GetMembersCount() const
{
	return this->membersCount;
}

Person* Community::GetMembers() const
{
	return this->members;
}

//Setters
void Community::SetName(const char* name)
{
	if (!name)
	{
		throw invalid_argument("Community name must not be null.");
	}

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void Community::SetFounder(Person& founder)
{
	this->founder = &founder;
}

void Community::SetMaxMembersCount(int number)
{
	this->maxMembersCount = number;
}

//OPERATORS
