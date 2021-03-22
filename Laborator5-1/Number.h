#ifndef NUMBER_H_INCLUDED
#define NUMBER_H_INCLUDED
#pragma once

class Number
{
    const char *value;
    int base;
public:
    //Constructori/Deconstructor:
    Number( const char * value, int base );
    Number( const Number& n );
    ~Number();
    // mai trebuie move const

    //intrebare:move assignment operator este =?
    //intrebare: la ce sa folosim friendly pt subtraction si addition?
    //intrebare: e bine op de indexare?
    //Operatori:
    Number operator= ( const Number& n);
    Number operator[](int index);
    Number operator+ ( const Number& n1 );
    Number operator- ( const Number& n1 );
    char operator- ( );
    bool operator< ( const Number& n1 );
	bool operator<= ( const Number& n1 );
	bool operator> ( const Number& n1 );
	bool operator>= ( const Number& n1 );
	bool operator== ( const Number& n1 );
	bool operator!= ( const Number& n1 );
    Number operator| (Number& n); //returneaza concatenarea celor 2 numere in baza cea mai mare
    void operator--();
    void operator--(int VariabilaExtremDeFolositoare);


    //Metode:
    void SwitchBase(int newBase);
    void Print();
    int  GetDigitsCount(); // returns the number of digits for the current number
    int  GetBase(); // returns the current base

};

#endif // NUMBER_H_INCLUDED
