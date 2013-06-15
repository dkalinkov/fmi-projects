#include <stdexcept>
#include <iostream>
#include <cstring>
#include "Community.h"
using std::invalid_argument;

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
	this->currSize = 10;

	this->members = new Person[currSize];
	AddMember(founder);
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
	for (unsigned index = 0; index < this->membersCount; index++)
	{
		this->members[index] = otherCommunity.members[index];
	}
}

void Community::ResizeCommunity(bool enlarge)
{
	int size = this->maxMembersCount / 4;
	if (enlarge)
	{
		size = this->currSize * 2;
	}

	Person* newArray = new Person[size];
	//memcpy(newArray, this->members, size * sizeof(Person));
	for (unsigned index = 0; index < this->membersCount; index++)
	{
		newArray[index] = this->members[index];
	}

	this->currSize = size;
	delete[] members;
	members = newArray;
}

int Community::FindPerson(const char* personEgn)
{
	for (unsigned index = 0; index < this->membersCount; index++)
	{
		if (strcmp(this->members[index].GetEGN(), personEgn) == 0)
		{
			return index;
		}
	}

	return -1;
}

void Community::SwapMemberToLast(const Person& person)
{
	int pos = FindPerson(person.GetEGN());
	Person tempDude = this->members[pos];
	this->members[pos] = this->members[this->membersCount - 1];
	this->members[this->membersCount - 1] = tempDude;
}

//PUBLIC METHODS
bool Community::AddMember(const Person& person)
{
	if (!&person)
	{
		throw invalid_argument("Person must not be null.");
	}

	if (!IsFull() && !IsMember(person))
	{
		if (this->membersCount == this->currSize)
		{
			ResizeCommunity(true);
		}

		this->members[membersCount] = person;
		membersCount++;

		return true;
	}

	return false;
}

bool Community::RemoveMember(const char* personEgn)
{
	if (!personEgn)
	{
		throw invalid_argument("Argument must not be null.");
	}

	if (IsMember(personEgn))
	{
		if (this->membersCount <= (this->currSize / 4))
		{
			ResizeCommunity(false);
		}

		int personPos = FindPerson(personEgn);
		SwapMemberToLast(this->members[personPos]);
		delete &members[this->membersCount - 1];
		this->membersCount--;

		return true;
	}

	return false;
}

bool Community::IsFull() const
{
	if (this->membersCount == this->maxMembersCount)
	{
		return true;
	}

	return false;
}

bool Community::IsMember(const Person& person) const
{
	return IsMember(person.GetEGN());
}

bool Community::IsMember(const char* personEgn) const
{
	for (unsigned index = 0; index < this->membersCount; index++)
	{
		if (strcmp(this->members[index].GetEGN(), personEgn) == 0)
		{
			return true;
		}
	}

	return false;
}

void Community::Information(std::ostream& output = std::cout) const
{
	output << this->name
		<< ", founded: " <<  this->foundationDate
		<< " by " << this->founder->GetName()
		<< ". Members: " <<this->membersCount
		<< std::endl;

	for (unsigned index = 0; index < this->membersCount; index++)
	{
		output << index + 1 << ". " << this->members[index] << std::endl;
	}
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

unsigned Community::GetMaxMembersCount() const
{
	return this->maxMembersCount;
}

unsigned Community::GetMembersCount() const
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
Community& Community::operator+= (const Person& person)
{
	this->AddMember(person);
	return *this;
}

Community& Community::operator-= (const Person& person)
{
	this->RemoveMember(person.GetEGN());
	return *this;
}

vector<Person> Community::operator+ (const Community& com)
{
	vector<Person> result;

	for (unsigned index = 0; index < this->membersCount; index++)
	{
		if (!com.IsMember(this->members[index]))
		{
			result.push_back(this->members[index]);
		}
	}

	for (unsigned index = 0; index < com.GetMembersCount(); index++)
	{
		result.push_back(com.GetMembers()[index]);
	}

	return result;
}

vector<Person> Community::operator- (const Community& com)
{
    vector<Person> result;

    for (unsigned index = 0; index < this->membersCount; index++)
    {
		if (!com.IsMember(this->members[index]))
		{
			result.push_back(this->members[index]);
		}
    }

    for (unsigned index = 0; index < com.GetMembersCount(); index++)
    {
        if (!IsMember(com.members[index]))
        {
            result.push_back(com.members[index]);
        }
    }

    return result;
}

vector<Person> Community::operator* (const Community& com)
{
    vector<Person> result;

    for (unsigned index = 0; index < com.GetMembersCount(); index++)
    {
        if (!IsMember(com.members[index]))
        {
            result.push_back(com.members[index]);
        }
    }

    return result;
}

vector<Person> Community::operator/ (const Community& com)
{
    vector<Person> result;

    for (unsigned index = 0; index < this->membersCount; index++)
    {
        if (com.IsMember(this->members[index]))
        {
            result.push_back(this->members[index]);
        }
    }

    return result;
}

bool Community::operator== (const Community& com)
{
	if (this->membersCount != com.GetMembersCount())
	{
	    std::cout<<"pesho";
		return false;
	}

	for (unsigned index = 0; index < com.GetMembersCount(); index++)
	{
		if (!this->IsMember(com.members[index]))
		{
			return false;
		}
	}

	return true;
}

bool Community::operator< (const Community& com)
{
    if (this->membersCount > com.GetMembersCount())
    {
        return false;
    }

    for (unsigned index = 0; index < this->membersCount; index++)
	{
	    if (!com.IsMember(this->members[index]))
        {
            return false;
        }
	}

    return true;
}

std::ostream& operator <<(std::ostream& output, const Community& other)
{
	other.Information(output);

	return output;
}
