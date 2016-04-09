#ifndef PERSON_H
#define PERSON_H

#include <ostream>
#include "SexEnum.h"
#include "ProfessionEnum.h"

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

	unsigned short CalculateAge() const;
	SexEnum GetSexFromEGN() const;
	void ValidateEGN(const char*) const;
	void Initialise(const char*, const char*, const char*, ProfessionEnum, double);

public:
	Person();
	Person(const char*, const char*, const char*, ProfessionEnum, double);
	Person(const Person&);
	Person& operator = (const Person&);
	~Person();

	bool operator== (const Person&);
	bool operator!= (const Person&);

	const char* GetName() const;
	const char* GetEGN() const;
	const char* GetAddress() const;
	unsigned short GetAge() const;
	SexEnum GetSexType() const;
	ProfessionEnum GetJob() const;
	double GetIncome() const;

	void SetName(const char*);
	void SetAddress(const char*);
	void SetJob(ProfessionEnum);
	void SetIncome(double);

	const char* JobAsString() const;
	void Information(std::ostream&) const;
};

std::ostream& operator <<(std::ostream& output, const Person& person);

#endif
