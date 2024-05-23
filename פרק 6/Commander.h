#pragma once
#include "Private.h"
using namespace std;
class Commander: public Private 
{
public:
	bool isKrav;
	Commander(int id, string FirstName, string LastName, int countWer, vector<int>marks,bool isKrav);
	~Commander(); 
	Commander();
	string soliderType() override;
	bool medal() override;
	void print() override;
	//friend bool operator == (const Commander& l, const Commander& r);
private:

};

Commander::Commander(int id, string FirstName, string LastName, int countWer, vector<int>marks, bool isKrav)
:Private( id,  FirstName,  LastName,  countWer,marks) {
	this->isKrav = isKrav;
}

Commander::Commander():Private()
{

}
bool Commander::medal() {
	int sum = 0, c = 0;
	for (auto i = marks.begin(); i < marks.end(); i++)
	{
		c++;
		sum += *i;
	}
	if (c != 0)
	{
		auto avg = sum / c;
	}

	if (countWer >= 7 && c > 90)
	{
		return true;
	}
	return false;
}
void Commander::print() {
	std::cout <<  soliderType() << endl;
	std::cout << "ID: " << id << endl;
	std::cout << "first name: " << FirstName << endl;
	std::cout << "last name: " << LastName << endl;
	std::cout << "num operations: " << countWer << endl;
	if(isKrav)
		std::cout << "is kravi : yes " <<endl;
	else
		std::cout << "is kravi : no " << endl;
}
string Commander::soliderType() {
	return "Commander";
}
//bool operator == (const Commander& l, const Commander& r) {
//	return l.id == r.id && l.FirstName == r.FirstName && l.LastName == r.LastName && l.countWer == r.countWer&&l.isKrav==r.isKrav;
//}
Commander::~Commander(){

}