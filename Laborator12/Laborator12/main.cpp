#include <iostream>
#include "Clase.h"

using namespace std;
int main()
{
	Agenda A;
	Prieten a, b, c;
	a.Set("Marcel", "05/08/2000", "Str. Principala", 01251231);
	b.Set("Mihai", "02/01/2011", "Str. Vlad Grigorescu", 512316);
	c.Set("Andrei", "01/12/2013", "Str. Mihai Viteazu", 03151251);
	Cunoscut d, e, f;
	d.Set("Bogdan", 215151231);
	e.Set("Razvan", 12315121);
	f.Set("Dan", 12411);
	Coleg g, h, i;
	g.Set("Alex", 125121, "SRL Vanzari Mobila","Str. Bizon");
	h.Set("Alin", 12311, "SRL Pompe Funebre","Str. Vlad Tepes");
	i.Set("Daniel", 1251123, "Lidl","Str. Oii");

	A.AdaugaContact(&a);
	A.AdaugaContact(&b);
	A.AdaugaContact(&c);
	A.AdaugaContact(&d);
	A.AdaugaContact(&e);
	A.AdaugaContact(&f);
	A.AdaugaContact(&g);
	A.AdaugaContact(&h);
	A.AdaugaContact(&i);
	
	cout << A.CautareDupaNume("Andrei") << endl;
	cout << endl;

	cout << "Lista Prieteni:";

	//M1:
	vector<Prieten> P;
	P = A.ListaPrieteni();
	for (int i = 0; i < P.size(); i++)
		cout << P[i].getnume() << " " << P[i].getadresa() << " " << P[i].getdataNastere() << " " << P[i].gettelefon() << endl;
	cout << endl;
	
	/*M2:
	vector<Contact> P;
	P = A.ListaPrieteni();
	for (int i = 0; i < P.size(); i++)
		cout << P[i].getnume() << " " << P[i].getadresa() << " " << P[i].getdataNastere() << " " << P[i].gettelefon() << endl;
	cout << endl;*/

	A.StergereContact("Alex");

	Cunoscut nou;
	nou.Set("Flaviu", 124141);
	A.AdaugaContact(&nou);

	A.Print();
	return 0;
}