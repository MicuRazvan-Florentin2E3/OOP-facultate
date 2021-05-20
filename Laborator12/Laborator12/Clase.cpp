#include "Clase.h"
#include <iostream>

using namespace std;

Contact* Agenda::CautareDupaNume(string a) {
	for (auto i : contacte)
		if (i->getnume() == a)
			return i;
}

 //M1:
vector<Prieten> Agenda::ListaPrieteni() {
	vector<Prieten> prieteni;
	for (auto i : contacte)
		if (typeid(i) == typeid(Prieten))
		{
			Prieten* p = dynamic_cast<Prieten*>(i);
			prieteni.push_back(*p);
		}		
	return prieteni;
}

/*M2:
vector<Contact> Agenda::ListaPrieteni() {
	vector<Contact> prieteni;
	for (auto i : contacte)
		if (i->getTip() == "Prieten")
		{
			prieteni.push_back(i);
		}
	return prieteni;
}*/

void Agenda::StergereContact(string a) {
	for(int i = 0; i < contacte.size(); i++)
		if (contacte[i]->getnume() == a)
		{
			for (int j = i; j < contacte.size()-1; j++)
				contacte[j] = contacte[j + 1];
			contacte.pop_back();
			i--;
		}
}

void Agenda::AdaugaContact(Contact* a) {
	contacte.push_back(a);
}

void Agenda::Print()
{
	for (auto i : contacte)
		cout << i->getnume() << " ";
	cout << endl;
}