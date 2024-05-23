#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Soldier.h"
#include "Private.h"
#include "Commander.h"
#include "Officer.h"
using namespace std;

enum option {
	stop,
	addNewSoldier,
	medalList,
	mostSociometric,
	countMedalPrivate,
	noCombatCommander,
	overSoldier,
	removeOfficer,
};

void add(vector<Soldier*>& vacSoled) {

	vector<int>marks;
	int numOfOperetion, mark;
	int choice, id, m;
	string fn, ln;
	bool kk;
	cout << "enter 1 to add private solider\n";
	cout << "enter 2 to add commander solider\n";
	cout << "enter 3 to add officer solider\n";
	cin >> choice;
	cout << "enter id,first name,last name and number Of opertions\n";
	cin >> id >> fn >> ln >> numOfOperetion;
	/*	cin >> fn;
		cin >> ln;
		cin >> numOfOperetion;*/
	if (choice == 1) {
		if (numOfOperetion > 0) {
			cout << "enter " << numOfOperetion << " grades\n";
			for (int i = 0; i < numOfOperetion; i++)
			{
				cin >> mark;
				marks.push_back(mark);
			}
		}
		Soldier* p = new Private(id, fn, ln, numOfOperetion, marks);
		vacSoled.push_back(p);
	}
	if (choice == 2)
	{
		if (numOfOperetion > 0) {
			cout << "enter " << numOfOperetion << "grades\n";
			for (int i = 0; i < numOfOperetion; i++)
			{
				cin >> mark;
				marks.push_back(mark);
			}
		}
		cout << "enter 1 if the solider is combat and 0 if not\n";
		cin >> kk;
		Soldier* p = new Commander(id, fn, ln, numOfOperetion, marks, kk);
		vacSoled.push_back(p);
	}
	if (choice == 3)
	{
		cout << "enter number of sociometric score\n";
		cin >> m;
		Soldier* p = new Officer(id, fn, ln, numOfOperetion, m);
		vacSoled.push_back(p);
	}
}
void medal(vector<Soldier*> vs) {
	for (auto i = vs.begin(); i < vs.end(); i++)
	{
		if ((*i)->medal()) {
			(*i)->print();
		}
	}
}
Soldier* mostSociometricScore(vector<Soldier*> vs) {
	int max = 0;
	Soldier* tempi = nullptr;
	for (auto i = vs.begin(); i < vs.end(); i++)
	{
		try {
			if ((*i)->getMark() > max)
			{
				max = (*i)->getMark();
				tempi = *i;
			}

		}
		catch (...) {
			cout << "u";
		}
	}
	return tempi;
}

int main()
{
	vector<Soldier*> vacSoled;
	int op;
	cout << "enter 0-7\n";
	cin >> op;
	while (op != stop)
	{
		switch (op)
		{
		case addNewSoldier: {add(vacSoled);
			break; }
		case medalList: {medal(vacSoled);
			break; }
		case mostSociometric:
		{	Soldier* s = mostSociometricScore(vacSoled);
		cout << "Officer soldier with most sociometric score: ";
		cout << s->getFname() << ' ' << s->getName() << endl;

		break;
		}
		case countMedalPrivate: { cout << "# private soldier for medal: ";
			int c = 0;
			for_each(vacSoled.begin(), vacSoled.end(), [&c](Soldier* i) {if (i->soliderType() == "Private" && i->medal()) { c++; } });
			cout <<c<< endl;
			break; }
		case noCombatCommander: {cout << "list of no combat commander soldier :";
			
			for_each(vacSoled.begin(), vacSoled.end(), [](Soldier* i) {Commander* c= dynamic_cast<Commander*>(i); if( (*i).soliderType() == "Commander"&&c&&!c->isKrav)
				cout << i->getFname() << ' ' << i->getName() << endl; });
			cout << endl;
			break; }
		case overSoldier: {
			if (any_of(vacSoled.begin(), vacSoled.end(), [](Soldier* i) {return (*i).countWer >= 15; }))
				cout << "there is a soldier that takes more than 15 operations\n";
			else cout << "no soldier takes more than 15 operations\n";
			break; }
		case removeOfficer: {
			
		vacSoled.erase( remove_if(vacSoled.begin(), vacSoled.end(), [](Soldier* i) {return (i)->soliderType() == "Officer" && (i)->countWer == 0; }),vacSoled.end());
		for_each(vacSoled.begin(), vacSoled.end(), [](Soldier* i) { i->print(); });
			break; }
		default:
		{
			cout << "ERROR:the value is unvalid";
			break;
		}
		};
		cout << "enter 0-7\n";
		cin >> op;
	}
	return 0;
}

