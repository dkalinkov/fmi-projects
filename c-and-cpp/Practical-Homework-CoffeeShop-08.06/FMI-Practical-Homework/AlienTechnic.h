#ifndef ALIEN_TECHNIC_H
#define ALIEN_TECHNIC_H

class AlienTechnic
{
private:
	char* name;
	char* technic;
	unsigned priceToAdd; //In percent

	void SetName(const char*);
	void SetTechnic(const char*);

public:
	AlienTechnic(const char* name, const char* technic, unsigned percentageOfPriceToAdd);
	AlienTechnic& operator= (const AlienTechnic&);
	~AlienTechnic();

	const char* GetName() const;
	const char* GetTechnic() const;
	unsigned GetPriceToAdd() const;

	void SetPriceToAdd(unsigned);
	void Print() const;
};

#endif
