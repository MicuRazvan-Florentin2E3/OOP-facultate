#pragma once
#include <string>
#include <map>
#include <vector>

using namespace std;

class Contact {
protected:
	string nume;
public:
	virtual string getnume() { return nume; } 
	/*virtual string getTip() { return "Contact"; }
	virtual string getdataNastere() { return dataNastere; }
	virtual string getadresa() { return adresa; }
	virtual string getfirma() { return firma; }
	virtual int gettelefon() { return telefon; }*/
};

class Prieten : public Contact {
protected:
	string dataNastere, adresa;
	int telefon;
public:
	void Set(string _nume, string _dataNastere, string _adresa, int _telefon) { nume = _nume; dataNastere = _dataNastere; adresa = _adresa; telefon = _telefon; }
	string getdataNastere() { return dataNastere; }
	string getadresa() { return adresa; }
	int gettelefon() { return telefon; }
	/*string getTip() { return "Prieten"; }
	string getfirma() { return firma; }*/
};

class Cunoscut : public Contact {
protected:
	int telefon;
public:
	void Set(string _nume, int _telefon) { nume = _nume; telefon = _telefon; }
	int gettelefon() { return telefon; }
	/*string getTip() { return "Cunoscut"; }
	string getdataNastere() { return dataNastere; }
	string getadresa() { return adresa; }
	string getfirma() { return firma; }*/
};

class Coleg : public Contact {
protected:
	int telefon;
	string firma;
	string adresa;
public:
	void Set(string _nume, int _telefon, string _firma, string _adresa) { nume = _nume; telefon = _telefon; firma = _firma; adresa = _adresa; }
	string getadresa() { return adresa; }
	int gettelefon() { return telefon; }
	string getfirma() { return firma; }
	/*string getTip() { return "Coleg"; }
	string getdataNastere() { return dataNastere; }*/
};

class Agenda {
	vector<Contact*> contacte;
public:
	Contact* CautareDupaNume(string a);
	vector<Prieten> ListaPrieteni();   //M1
	//vector<Contact> ListaPrieteni();  //M2
	void StergereContact(string a);
	void AdaugaContact(Contact* a);
	void Print();
};
