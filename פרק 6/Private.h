#pragma once
#include "Soldier.h"
#include<vector>
#include <algorithm>
using namespace std;
class Private:public Soldier
{
public:
	Private();
	Private(int id, string FirstName, string LastName, int countWer, vector<int>marks);
	~Private();
	bool medal() override;
	void print() override;
	string soliderType() override;
	vector<int>marks;
	//friend bool operator == (const Private& l, const Private& r);

};
Private::Private(int id, string FirstName, string LastName, int countWer, vector<int>marks)
	:Soldier( id,  FirstName,  LastName,  countWer) {
	this->marks = marks;
}
Private::Private():Soldier() {}


bool Private::medal() {
	int sum = 0, c = 0, avg;
	for (auto i = marks.begin(); i < marks.end(); i++)
	{
		c++;
		sum += *i;
	}
	if (c > 0) {
		 avg = sum / c;
	}
	if (countWer >= 10 && avg >95)
	{
		return true;
	}
	return false;
}
void Private::print() {
	std::cout << soliderType() << endl;
	std::cout << "ID: " << id << endl;
	std::cout << "first name: " << FirstName << endl;
	std::cout << "last name: " << LastName << endl;
	std::cout << "num operations: " << countWer << endl;
	std::cout << "num operations: " ;
	for (auto i = marks.begin(); i < marks.end(); i++)
	{
		std::cout << *i << ' ';
	}
	std::cout << endl;
}
string Private::soliderType() {
	return "Private";
}
//bool operator == (const Private& l, const Private& r) {
//	return l.id == r.id && l.FirstName == r.FirstName && l.LastName == r.LastName && l.countWer == r.countWer;
//}
Private::~Private() {
	if (!marks.empty())
		marks.clear();
}