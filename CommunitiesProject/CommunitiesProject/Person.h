#ifndef PERSON_H
#define PERSON_H

#include "ostream"
#include "SexEnum.h"
#include "ProfessionEnum.h"
using namespace std;

class Person
{
private:
	char* name;
	char* EGN;
	char* address;
	unsigned short age;
	SexEnum sex;
	ProfessionEnum job;
	double income;

	unsigned short CalculateAge(void) const;
	SexEnum GetSexFromEGN(void) const;

public:
	Person(void);
	Person(const char*, const char*, const char*, ProfessionEnum, double);
	Person(const Person&);
	Person& operator = (const Person&);
	~Person(void);

	char* GetName(void);
	void SetName(const char*);

	char* GetEGN(void);
	void SetEGN(const char*);

	char* GetAddress(void);
	void SetAddress(const char*);

	unsigned short GetAge(void);

	SexEnum GetSexType(void);

	ProfessionEnum GetJob(void);
	void SetJob(ProfessionEnum);

	double GetIncome(void);
	void SetIncome(double);
};

ostream& operator <<(ostream& output, const Person& person);

#endif
