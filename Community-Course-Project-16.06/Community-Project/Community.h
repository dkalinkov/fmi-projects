#ifndef COMMUNITY_H
#define COMMUNITY_H

#include <vector>
#include "Person.h"
using std::vector;

class Community
{
private:
	unsigned currSize;
	char* name;
	char* foundationDate;
	Person* founder;
	unsigned maxMembersCount;
	unsigned membersCount;
	Person* members;
	// TODO: ADD COMMUNITIES COUNT. I HAVE A MISUNDERSTANDING WITH THE OBJECTIVE!

	void init(const Community&);
	void ResizeCommunity(bool);
	int FindPerson(const char*);
	void SwapMemberToLast(const Person&);

public:
	Community(const char* name, const char* foundationDate, Person& founder, int maxMembersCount);
	Community(const Community&);
	Community& operator = (const Community&);
	~Community();

	char* GetName() const;
	char* GetFoundationDate() const;
	Person GetFounder() const;
	unsigned GetMaxMembersCount() const;
	unsigned GetMembersCount() const;
	Person* GetMembers() const;
	// TODO: Add communities getter

	void SetName(const char*);
	void SetFounder(Person&);
	void SetMaxMembersCount(int);

	bool AddMember(const Person&);
	bool RemoveMember(const char*);
	bool IsFull() const;
	bool IsMember(const Person&) const;
	bool IsMember(const char*) const;
	void Information(std::ostream&) const;

	Community& operator += (const Person&);
	Community& operator -= (const Person&);
	vector<Person> operator + (const Community&);
	vector<Person> operator / (const Community&);
	vector<Person> operator - (const Community&);
	vector<Person> operator * (const Community&);
	bool operator == (const Community&);
    bool operator < (const Community&);
};

std::ostream& operator <<(std::ostream& output, const Community& person);

#endif
