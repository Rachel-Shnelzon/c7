#pragma once
#include "Soldier.h"
#include <string>
class Officer:public Soldier
{
public:
	int markSoch;
	Officer();
	Officer(int id, string FirstName, string LastName, int countWer,int markSoch);
	~Officer();
	bool medal() override;
	void print() override;
	int getMark();
	string soliderType() override;
//friend bool operator == (const Officer& l, const Officer& r);
private:

};

int Officer::getMark() {
	return this->markSoch;
}

Officer::Officer()
{
}
Officer::Officer(int id, string FirstName, string LastName, int countWer, int markSoch)
:Soldier( id,  FirstName,  LastName,  countWer) {
	this->markSoch = markSoch;
}

Officer::~Officer()
{
}
bool Officer::medal() {
	
	if (countWer >= 2&&markSoch>92 )
	{
		return true;
	}
	return false;
}
void Officer::print() {
	std::cout << soliderType() << endl;
	std::cout << "ID: " <<id<< endl;
	std::cout << "first name: " <<FirstName<< endl;
	std::cout << "last name: " <<LastName<< endl;
	std::cout << "num operations: " <<countWer<< endl;
	std::cout << "mark of sochimetry: " <<markSoch<< endl;
}
string Officer::soliderType() {
	return "Officer";
}
//bool operator == (const Officer& l, const Officer& r) {
//	return l.id == r.id && l.FirstName == r.FirstName && l.LastName == r.LastName && l.countWer == r.countWer &&l.markSoch==r.markSoch;
//}
