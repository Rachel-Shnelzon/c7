#pragma once
#include <iostream>
#include<string>
using namespace std;

class Soldier
{
public:
	int id;
	string FirstName;
	string LastName;
	int countWer;
	virtual int getMark();
	Soldier(int id,string FirstName,string LastName,int countWer);
	Soldier();
	virtual ~Soldier();
	virtual bool medal() = 0;
	virtual void print()=0;
	virtual string soliderType()=0;
	friend bool operator == (const Soldier & l, const Soldier & r);
	friend bool operator<(const Soldier& l, const Soldier &r) ;
	string getFname();
	string getName();
};


string Soldier:: getFname() {
	return this->FirstName;
}
string Soldier::getName() {
	return this->LastName;
}

Soldier::Soldier() {
	this->id = 0;
	this->FirstName = "";
	this->LastName = "";
	this->countWer = 0;
}
Soldier::Soldier(int id, string FirstName, string LastName, int countWer)
{
	this->id = id;
	this->FirstName = FirstName;
	this->LastName = LastName;
	this->countWer = countWer;
}
bool operator == (const Soldier& l, const Soldier& r) {
	return l.id == r.id && l.FirstName == r.FirstName && l.LastName == r.LastName && l.countWer == r.countWer;
}
bool operator<(const Soldier& l, const Soldier& r) {
	return l.id < r.id;
}
Soldier::~Soldier(){}
int Soldier::getMark() {
	throw "ERROR: this function is just for officer soldier";
}