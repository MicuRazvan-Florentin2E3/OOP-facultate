#ifndef NUMBER_H_INCLUDED
#define NUMBER_H_INCLUDED
#pragma once

class Number
{
    const char *value;
    int base;
public:
    //Constructori:
    Number( const char * value, int base );
    ~Number();
    Number( const Number& n );
    // mai trebuie move const


    //Operatori:
    Number operator+ ( const Number& n1 , const Number& n2 );
    Number operator- ( const Number& n1 , const Number& n2 );
    Number operator- ( const Number& n );
    bool operator< ( const Number& n1 , const Number& n2 );
	bool operator<= ( const Number& n1 , const Number& n2 );
	bool operator> ( const Number& n1 , const Number& n2 );
	bool operator>= ( const Number& n1 , const Number& n2 );
	bool operator== ( const Number& n1 , const Number& n2 );
	bool operator!= ( const Number& n1 , const Number& n2 );
    Number operator| (Number& n); //returneaza concatenarea celor 2 numere in baza cea mai mare



    //Metode:
    void SwitchBase(int newBase);
    void Print();
    int  GetDigitsCount(); // returns the number of digits for the current number
    int  GetBase(); // returns the current base

};

#endif // NUMBER_H_INCLUDED
