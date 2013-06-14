#include <stdexcept>
#include <iostream>
#include <cstring>
#include "Community.h"
using std::invalid_argument;

//TODO: Proper destructor

//CONSTRUCTORS
Community::Community(const char* name, const char* foundationDate, Person& founder, int maxMembersCount)
{
	SetName(name);

	if (!foundationDate)
	{
		throw invalid_argument("Foundation date must not be null.");
	}

	this->foundationDate = new char[strlen(foundationDate) + 1];
	strcpy(this->foundationDate, foundationDate);

	SetFounder(founder);
	SetMaxMembersCount(maxMembersCount);
	this->membersCount = 0;
	
	this->members = new Person[5];
}

Community::Community(const Community& otherCommunity)
{
	init(otherCommunity);
}

Community& Community::operator= (const Community& otherCommunity)
{
	if (this != &otherCommunity)
	{
		delete[] name;
		delete[] foundationDate;
		delete[] members;

		init(otherCommunity);
	}

	return *this;
}

Community::~Community()
{
	delete[] name;
	delete[] foundationDate;
	//delete founder;
	delete[] members;
}

//PRIVATE METHODS
void Community::init(const Community& otherCommunity)
{
	this->name = new char[strlen(otherCommunity.name) + 1];
	strcpy(this->name, otherCommunity.name);

	this->foundationDate = new char[strlen(otherCommunity.foundationDate) + 1];
	strcpy(this->foundationDate, otherCommunity.foundationDate);

	this->founder = otherCommunity.founder;
	this->maxMembersCount = otherCommunity.maxMembersCount;
	this->membersCount = otherCommunity.membersCount;

	this->members = new Person[otherCommunity.membersCount];
	for (int index = 0; index < this->membersCount; index++)
	{
		this->members[index] = otherCommunity.members[index];
	}
}

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
	if (number <= 2)
	{
		throw invalid_argument("Max members cound must not above 2.");
	}
	this->maxMembersCount = number;
}

//OPERATORS
