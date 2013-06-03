#ifndef COMMUNITY_H
#define COMMUNITY_H

#include "Person.h"

class Community
{
private:
	char* name;
	char* foundationDate;
	Person* founder;
	unsigned maxMembersCount;
	unsigned membersCount;
	Person* members;
	//TODO: ADD COMMUNITIES COUNT. I HAVE A MISUNDERSTANDING WITH THE OBJECTIVE!

public:
	Community(const char*, const char*, Person&, int);
	Community(const Community&);
	Community& operator = (const Community&);
	~Community();

	char* GetName() const;
	char* GetFoundationDate() const;
	Person GetFounder() const;
	int GetMaxMembersCount() const;
	int GetMembersCount() const;
	Person* GetMembers() const;

	void SetName(const char*);
	void SetFounder(Person&);
	void SetMaxMembersCount(int);

	void AddMember(const Person&);
	void RemoveMember(const char*);
	bool IsFull() const;
	bool IsMember(const Person&) const;
	bool IsMember(const char*) const;
	void Information() const;
};

std::ostream& operator <<(std::ostream& output, const Community& person);

#endif